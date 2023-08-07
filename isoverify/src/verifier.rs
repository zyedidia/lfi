use bad64::{Imm, Instruction, Op, Operand, Reg, Shift};

use crate::inst::{
    is_access_incomplete, is_allowed, is_branch, legal_sysreg, lo, lo_reg, nomodify,
};

const RES_REG: Reg = Reg::X15;
const RET_REG: Reg = Reg::X30;
const SP_REG: Reg = Reg::SP;
const OPT_REG: Reg = Reg::X24;
const OPT_REG2: Reg = Reg::X22;
const BASE_REG: Reg = Reg::X21;
const RES32_REG: Reg = Reg::X14;

pub static mut FAILED: bool = false;

fn error(inst: &Instruction, msg: &str) {
    eprintln!("error: {:x}: {}: {}", inst.address(), inst, msg);
    // this is not a multithreaded program
    unsafe {
        FAILED = true;
    }
}

fn data_reg(r: Reg) -> bool {
    match r {
        RES_REG | SP_REG | OPT_REG | OPT_REG2 => true,
        _ => false,
    }
}

fn fixed_reg(r: Reg) -> bool {
    r == BASE_REG || r == lo(BASE_REG) || r == RES32_REG
}

fn restricted_reg(r: Reg) -> bool {
    r == RET_REG
        || r == OPT_REG
        || r == OPT_REG2
        || r == RES_REG
        || r == SP_REG
        || r == lo(RET_REG)
        || r == lo(OPT_REG)
        || r == lo(OPT_REG2)
        || r == lo(RES_REG)
        || r == lo(SP_REG)
}

fn check_branch(inst: &Instruction) {
    match inst.op() {
        Op::BLR | Op::BR | Op::RET => {
            let ops = inst.operands();
            if ops.len() == 0 {
                return;
            }
            if let Operand::Reg { reg: r, arrspec: _ } = ops[0] {
                if r != RES_REG && r != RET_REG {
                    error(inst, "indirect branch on non-reserved register");
                }
            }
        }
        _ => {}
    }
}

fn check_sysreg(inst: &Instruction, i: usize) {
    if let Operand::SysReg(r) = inst.operands()[i] {
        if !legal_sysreg(r) {
            error(inst, "attempt to access illegal system register");
        }
    }
}

fn check_sys(inst: &Instruction) {
    match inst.op() {
        Op::MSR => check_sysreg(inst, 0),
        Op::MRS => check_sysreg(inst, 1),
        _ => {}
    }
}

fn zero(imm: Imm) -> bool {
    match imm {
        Imm::Signed(i) => i == 0,
        Imm::Unsigned(u) => u == 0,
    }
}

fn ok_operand(op: &Operand) -> bool {
    match op {
        Operand::MemReg(r) => data_reg(*r),
        Operand::MemOffset {
            reg,
            offset,
            mul_vl,
            ..
        } => !mul_vl && ((*reg == BASE_REG && zero(*offset)) || data_reg(*reg)),
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

fn ok_check_sp(next: &[Option<Result<Instruction, bad64::DecodeError>>]) -> bool {
    if let Some(Ok(next1)) = &next[0] {
        if let Some(Ok(next2)) = &next[1] {
            if next1.op() != Op::MOV
                || next1.operands().len() != 2
                || next2.op() != Op::ADD
                || next2.operands().len() != 3
            {
                return false;
            }
            let (ops1, ops2) = (next1.operands(), next2.operands());
            match (ops1[0], ops1[1], ops2[0], ops2[1], ops2[2]) {
                (
                    Operand::Reg { reg: res32, .. },
                    Operand::Reg { reg: wsp, .. },
                    Operand::Reg { reg: sp, .. },
                    Operand::Reg { reg: base, .. },
                    Operand::Reg { reg: res32_x, .. },
                ) => {
                    return res32 == lo(RES32_REG)
                        && wsp == Reg::WSP
                        && sp == Reg::SP
                        && base == BASE_REG
                        && res32_x == RES32_REG;
                }
                _ => return false,
            }
        }
    }
    return false;
}

fn ok_mod(
    inst: &Instruction,
    reg: Reg,
    next: &[Option<Result<Instruction, bad64::DecodeError>>],
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
                // 'add restricted, base, RES32_REG' is allowed
                (Operand::Reg { reg: base, .. }, Operand::Reg { reg, .. }) => {
                    if base == BASE_REG && reg == RES32_REG {
                        return true;
                    }
                }
                _ => {}
            };
        }
    }

    if reg == SP_REG {
        // must be followed by
        // mov lo(RES32_REG), wsp
        // add sp, BASE_REG, RES32_REG
        //
        // or a load/store before the next branch
        if ok_check_sp(next) {
            return true;
        }
        if (inst.op() == Op::ADD || inst.op() == Op::SUB)
            && matches!(inst.operands()[2], Operand::Imm64 { .. })
        {
            for maybe_inst in next {
                if let Some(Ok(inst)) = maybe_inst {
                    if is_branch(inst.op()) {
                        break;
                    }
                    if !is_access_incomplete(inst.op()) {
                        continue;
                    }
                    for op in inst.operands() {
                        match op {
                            Operand::MemReg(r) if *r == SP_REG => return true,
                            Operand::MemOffset { reg, mul_vl, .. } if *reg == SP_REG && !mul_vl => {
                                return true
                            }
                            Operand::MemPreIdx { reg, .. } if *reg == SP_REG => return true,
                            Operand::MemPostIdxImm { reg, .. } if *reg == SP_REG => return true,
                            _ => {}
                        }
                    }
                }
            }
        }
    } else if reg == RET_REG {
        if inst.op() == Op::LDR {
            // ldr x30, [x21] is legal
            match inst.operands()[1] {
                Operand::MemOffset {
                    reg,
                    offset,
                    mul_vl,
                    ..
                } => {
                    if reg == BASE_REG && !mul_vl && zero(offset) {
                        return true;
                    }
                }
                _ => {}
            };
        }
        // must be followed by
        // add RET_REG, BASE_REG, lo(RET_REG), uxtw
        if let Some(Ok(next)) = &next[0] {
            if next.op() != Op::ADD || next.operands().len() != 3 {
                return false;
            }
            let ops = next.operands();
            match (ops[0], ops[1], ops[2]) {
                (
                    Operand::Reg { reg: ret, .. },
                    Operand::Reg { reg: base, .. },
                    Operand::ShiftReg { reg: loret, shift },
                ) => {
                    if ret == RET_REG
                        && base == BASE_REG
                        && loret == lo(RET_REG)
                        && shift == Shift::UXTW(0)
                    {
                        return true;
                    }
                }
                _ => return false,
            };
        }
    }

    return false;
}

pub fn check(
    inst: &Instruction,
    iter: &mut peekmore::PeekMoreIterator<
        impl Iterator<Item = Result<Instruction, bad64::DecodeError>>,
    >,
) {
    if !is_allowed(inst.op()) {
        error(inst, "disallowed instruction");
    }
    check_branch(&inst);
    check_sys(&inst);

    for op in inst.operands().iter() {
        if !ok_operand(op) {
            error(inst, "disallowed operand")
        }
    }

    if nomodify(inst.op()) || inst.operands().len() == 0 {
        return;
    }
    if let Operand::Reg { reg, .. } = inst.operands()[0] {
        let next = iter.peek_range(0, 32);
        let ok = ok_mod(&inst, reg, next);
        if !ok {
            error(inst, "disallowed modification");
        }
    }
}
