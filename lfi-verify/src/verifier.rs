extern crate alloc;

use crate::inst::{is_allowed, is_multimod, nomodify};
use crate::reg::{lo_reg, lo};
use alloc::format;
use bad64::{Imm, Instruction, Op, Operand, Reg, Shift, SysReg};

const RES_REG: Reg = Reg::X18;
const RET_REG: Reg = Reg::X30;
const SP_REG: Reg = Reg::SP;
const BASE_REG: Reg = Reg::X21;
const SYS_REG: Reg = Reg::X25;

pub struct Verifier {
    pub failed: bool,
    pub message: Option<fn(bytes: *const u8, size: usize)>,
}

// List of registers that may be used as load targets
fn data_reg(r: Reg) -> bool {
    match r {
        RES_REG | SP_REG => true,
        _ => false,
    }
}

// List of registers that may never be modified.
fn fixed_reg(r: Reg) -> bool {
    r == BASE_REG || r == lo(BASE_REG) || r == SYS_REG || r == lo(SYS_REG)
}

// List of registers that may be modified only via guards.
fn restricted_reg(r: Reg) -> bool {
    r == RET_REG
        || r == RES_REG
        || r == SP_REG
        || r == lo(RET_REG)
        || r == lo(RES_REG)
        || r == lo(SP_REG)
}

fn legal_implspec(reg: Operand) -> bool {
    match reg {
        Operand::ImplSpec{ o0: 3, o1: 0, cm: 0, cn: 4, o2: 1 } => true, // id_aa64pfr1_el1
        Operand::ImplSpec{ o0: 3, o1: 0, cm: 0, cn: 4, o2: 0 } => true, // id_aa64pfr0_el1
        Operand::ImplSpec{ o0: 3, o1: 0, cm: 0, cn: 4, o2: 4 } => true, // id_aa64zfr0_el1
        Operand::ImplSpec{ o0: 3, o1: 0, cm: 0, cn: 6, o2: 0 } => true, // id_aa64isar0_el1
        Operand::ImplSpec{ o0: 3, o1: 0, cm: 0, cn: 6, o2: 1 } => true, // id_aa64isar1_el1
        _ => false,
    }
}

fn legal_sysreg(reg: SysReg) -> bool {
    match reg {
        SysReg::TPIDR_EL0 => true,
        SysReg::FPSR => true,
        SysReg::FPCR => true,
        _ => false,
    }
}

fn nimm(imm: Imm, val: i64) -> bool {
    match imm {
        Imm::Signed(i) => i == val,
        Imm::Unsigned(u) => u == val as u64,
    }
}

fn zero(imm: Imm) -> bool {
    nimm(imm, 0)
}

// Checks a memory address to make it sure only uses the guard mode, or a reserved register
fn ok_operand(op: &Operand) -> bool {
    match op {
        Operand::MemReg(r) => data_reg(*r),
        Operand::MemOffset {
            reg,
            offset,
            mul_vl,
            ..
        } => {
            !mul_vl && ((*reg == SYS_REG && (zero(*offset) || nimm(*offset, 8))) || data_reg(*reg))
        }
        Operand::MemPreIdx { reg, .. } => data_reg(*reg),
        Operand::MemPostIdxReg { .. } => false,
        Operand::MemPostIdxImm { reg, .. } => data_reg(*reg),
        Operand::MemExt { regs, shift, .. } => {
            // only allow [BASE_REG, wN, uxtw #0]
            regs[0] == BASE_REG && lo_reg(regs[1]) && *shift == Some(Shift::UXTW(0))
        }
        _ => true,
    }
}

// Returns true if an instruction, with 'reg' as its first operand, does not modify a reserved
// register illegaly.
fn ok_mod(
    inst: &Instruction,
    reg: Reg,
) -> bool {
    if fixed_reg(reg) {
        return false;
    }
    if !restricted_reg(reg) {
        return true;
    }
    if inst.op() == Op::ADD {
        let ops = inst.operands();
        if ops.len() == 3 {
            match (ops[1], ops[2]) {
                // 'add restricted, base, lo, uxtw' is allowed
                (Operand::Reg { reg: base, .. }, Operand::ShiftReg { reg, shift }) => {
                    if base == BASE_REG && lo_reg(reg) && shift == Shift::UXTW(0) {
                        return true;
                    }
                }
                _ => {}
            };
        }
    }

    if reg == RET_REG {
        if inst.op() == Op::LDR {
            // 'ldr x30, [x21]' is legal and so is 'ldr x30, [x25]'
            match inst.operands()[1] {
                Operand::MemOffset {
                    reg,
                    offset,
                    mul_vl,
                    ..
                } => {
                    if (reg == SYS_REG) && !mul_vl && (zero(offset)) {
                        return true;
                    }
                }
                _ => {}
            };
        }
    }

    return false;
}

impl Verifier {
    fn error(self: &mut Self, inst: &Instruction, msg: &str) {
        self.failed = true;
        if let Some(message) = self.message {
            let s = format!("{:x}: {}: {}", inst.address(), inst, msg);
            message(s.as_ptr(), s.len());
        }
    }

    // Makes sure that indirect branches only used reserved registers
    fn check_branch(self: &mut Self, inst: &Instruction) {
        match inst.op() {
            Op::BLR | Op::BR | Op::RET => {
                let ops = inst.operands();
                if ops.len() == 0 {
                    return;
                }
                if let Operand::Reg { reg: r, arrspec: _ } = ops[0] {
                    if r != RES_REG && r != RET_REG {
                        self.error(inst, "indirect branch on non-reserved register");
                    }
                }
            }
            _ => {}
        }
    }

    // Checks that operand 'i' is not an illegal system register
    fn check_sysreg(self: &mut Self, inst: &Instruction, i: usize) {
        if let Operand::SysReg(r) = inst.operands()[i] {
            if !legal_sysreg(r) {
                self.error(inst, "attempt to access illegal system register");
            }
        } else if let ispec @ Operand::ImplSpec{ .. } = inst.operands()[i] {
            // Read of system registers that the disassembler doesn't pretty-print for us.
            if i == 1 && !legal_implspec(ispec) {
                self.error(inst, "attempt to access illegal system register");
            }
        } else {
            self.error(inst, "attempt to access illegal system register");
        }
    }

    fn check_sys(self: &mut Self, inst: &Instruction) {
        match inst.op() {
            Op::MSR => self.check_sysreg(inst, 0),
            Op::MRS => self.check_sysreg(inst, 1),
            _ => {}
        }
    }

    fn check_rel_load(self: &mut Self, inst: &Instruction) {
        let operand = match inst.op() {
            Op::LDR => inst.operands()[1],
            Op::LDRSW => inst.operands()[1],
            _ => return
        };
        if let Operand::Label(_) = operand {
            self.error(inst, "disallowed relative load");
        }
    }

    pub fn check_insn(
        self: &mut Self,
        inst: &Instruction,
    ) {
        // check if the instruction is in the allowlist.
        if !is_allowed(inst.op()) {
            self.error(inst, "disallowed instruction");
        }
        // make sure indirect branches target a reserved register
        self.check_branch(&inst);
        // make sure system instructions (MRS/MSR) only access legal registers
        self.check_sys(&inst);
        // check relative memory accesses (only ldr{sw})
        self.check_rel_load(&inst);

        // check memory addressing operands for legality
        for op in inst.operands().iter() {
            if !ok_operand(op) {
                self.error(inst, "disallowed operand")
            }
        }

        if nomodify(inst.op()) || inst.operands().len() == 0 {
            // these instructions don't modify their first operand
            return;
        }
        // check that reserved registers are only modified according to the right rules
        if let Operand::Reg { reg, .. } = inst.operands()[0] {
            let ok = ok_mod(&inst, reg);
            if !ok {
                self.error(inst, "disallowed modification");
            }
            if is_multimod(inst.op()) {
                if let Operand::Reg { reg, .. } = inst.operands()[1] {
                    // these instructions also modify their second operand, so we check that too
                    let ok = ok_mod(&inst, reg);
                    if !ok {
                        self.error(inst, "disallowed modification");
                    }
                }
            }
        }
    }
}
