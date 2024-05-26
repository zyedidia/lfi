use bad64::{Imm, Instruction, Op, Operand, Reg, Shift};

struct Buf<'a> {
    data: &'a mut [u32],
    n: usize,
}

impl<'a> Buf<'a> {
    fn push(self: &mut Self, val: u32) {
        if self.n < self.data.len() {
            self.data[self.n] = val;
            self.n += 1;
        }
    }
}

const ADDR_REG: Reg = Reg::X18;
const RET_REG: Reg = Reg::X30;
const TMP_REG: Reg = Reg::X22;
const SP_REG: Reg = Reg::SP;
const BASE_REG: Reg = Reg::X21;
const SYS_REG: Reg = Reg::X25;

const UXTW: u32 = 0b010;

static mut FAILED: bool = false;

fn guard(rd: Reg, rm: Reg) -> u32 {
    return (0b10001011001 << 21)
        | (num(rm) << 16)
        | (UXTW << 13)
        | (0b000 << 10)
        | (num(BASE_REG) << 5)
        | (num(rd));
}

fn br(rn: Reg) -> u32 {
    return (0b1101011000011111000000 << 10) | (num(rn) << 5) | (0b00000);
}

fn blr(rn: Reg) -> u32 {
    return (0b1101011000111111000000 << 10) | (num(rn) << 5) | (0b00000);
}

// Indirect branches.
fn do_branch(insn: &Instruction, buf: &mut Buf) -> bool {
    match insn.op() {
        Op::BR => {
            buf.push(guard(ADDR_REG, rt(insn)));
            buf.push(br(ADDR_REG));
            return true;
        }
        Op::BLR => {
            buf.push(guard(ADDR_REG, rt(insn)));
            buf.push(blr(ADDR_REG));
            return true;
        }
        // Could rewrite RET as well, but it is unlikely anyone is using it with something other
        // than x30 (if they do, it will be caught by the verifier).
        _ => {
            return false;
        }
    }
}

fn imm(imm: Imm) -> i32 {
    match imm {
        Imm::Signed(i) => i as i32,
        Imm::Unsigned(i) => i as i32,
    }
}

fn add_imm_valid(i: Imm) -> bool {
    let nimm = imm(i);
    return (nimm < 4096 && nimm > -4096) || (nimm % 4096 == 0);
}

fn add_imm(rd: Reg, rn: Reg, i: Imm) -> u32 {
    assert!(add_imm_valid(i));
    let nimm = imm(i);
    let (sh, imm12) = if nimm >= 4096 || nimm <= -4096 {
        (1, nimm / 4096)
    } else {
        (0, nimm)
    };
    let (op, imm12) = if nimm < 0 {
        (1, -imm12 as u32)
    } else {
        (0, imm12 as u32)
    };
    let sf = 0b1;
    return (sf << 31)
        | (op << 30)
        | (0b00100010 << 23)
        | (sh << 22)
        | (imm12 << 10)
        | (num(rn) << 5)
        | (num(rd));
}

fn ldr_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000011, 1, if islo(rt) { 0 } else { 1 });
}

fn ldrb_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000011, 0, 0);
}

fn ldrh_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000011, 0, 1);
}

fn ldrsb_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(
        rt,
        rm,
        0b111000101 | if islo(rt) { 0b10 } else { 0b00 },
        0,
        0,
    );
}

fn ldrsh_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(
        rt,
        rm,
        0b111000101 | if islo(rt) { 0b10 } else { 0b00 },
        0,
        1,
    );
}

fn ldrsw_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000101, 1, 0);
}

fn str_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000001, 1, if islo(rt) { 0 } else { 1 });
}

fn strb_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000001, 0, 0);
}

fn strh_uxtw(rt: Reg, rm: Reg) -> u32 {
    return xxr_uxtw(rt, rm, 0b111000001, 0, 1);
}

fn xxr_uxtw(rt: Reg, rm: Reg, opcode: u32, size1: u32, size0: u32) -> u32 {
    let (vr, size1, size0, opc1) = if v128(rt) {
        (1, 0, 0, 1)
    } else if v64(rt) {
        (1, 1, 1, 0)
    } else if v32(rt) {
        (1, 1, 0, 0)
    } else if v16(rt) {
        (1, 0, 1, 0)
    } else if v8(rt) {
        (1, 0, 0, 0)
    } else {
        assert!(isgpr(rt));
        (0, size1, size0, 0)
    };
    return (size1 << 31)
        | (size0 << 30)
        | (opcode << 21)
        | (vr << 26)
        | (opc1 << 23)
        | (num(rm) << 16)
        | (UXTW << 13)
        | (0 << 12)
        | (0b10 << 10)
        | (num(BASE_REG) << 5)
        | (num(rt));
}

fn xxr_imm(input: u32, rt: Reg) -> u32 {
    let input = (input >> 10) << 10;
    return input | (num(ADDR_REG) << 5) | (num(rt));
}

fn add_reg(rd: Reg, rn: Reg, rm: Reg, shift: Option<Shift>) -> u32 {
    let sf = 0b1;

    let (option, imm3) = match shift {
        Some(Shift::LSL(n)) => (0b011, n),
        Some(Shift::UXTW(n)) => (0b010, n),
        Some(Shift::SXTW(n)) => (0b110, n),
        Some(Shift::SXTX(n)) => (0b111, n),
        Some(Shift::UXTX(n)) => (0b011, n),
        Some(Shift::SXTB(n)) => (0b100, n),
        Some(Shift::SXTH(n)) => (0b101, n),
        Some(Shift::UXTH(n)) => (0b001, n),
        Some(Shift::UXTB(n)) => (0b000, n),
        _ => (0, 0),
    };

    return (sf << 31)
        | (0b0001011001 << 21)
        | (num(rm) << 16)
        | (option << 13)
        | (imm3 << 10)
        | (num(rn) << 5)
        | (num(rd));
}

fn do_addropt(
    idat: u32,
    op: Operand,
    rt: Reg,
    load: bool,
    x_uxtw: fn(Reg, Reg) -> u32,
    buf: &mut Buf,
) -> bool {
    let mut rt = rt;
    if load && rt == RET_REG {
        rt = TMP_REG;
    }
    match op {
        Operand::MemReg(rm) => {
            buf.push(ldr_uxtw(rt, rm));
        }
        Operand::MemOffset { reg, offset, .. } => {
            if add_imm_valid(offset) {
                buf.push(add_imm(TMP_REG, reg, offset));
                buf.push(x_uxtw(rt, TMP_REG));
            } else {
                buf.push(guard(ADDR_REG, reg));
                buf.push(xxr_imm(idat, rt));
            }
        }
        Operand::MemPreIdx { reg, imm, .. } => {
            buf.push(add_imm(reg, reg, imm));
            buf.push(x_uxtw(rt, reg));
        }
        Operand::MemPostIdxImm { reg, imm, .. } => {
            buf.push(x_uxtw(rt, reg));
            buf.push(add_imm(reg, reg, imm));
        }
        Operand::MemExt { regs, shift, .. } => {
            buf.push(add_reg(TMP_REG, regs[0], regs[1], shift));
            buf.push(x_uxtw(rt, TMP_REG));
        }
        _ => {}
    };
    if load && rt == TMP_REG {
        buf.push(guard(RET_REG, TMP_REG));
    }
    return buf.n > 0;
}

fn do_addr(idat: u32, op: Operand, rt: Reg, load: bool, buf: &mut Buf) -> bool {
    let mut rt = rt;
    if load && rt == RET_REG {
        rt = TMP_REG;
    }
    match op {
        Operand::MemReg(rm) => {
            buf.push(guard(ADDR_REG, rm));
            buf.push(xxr_imm(idat, rt));
        }
        Operand::MemOffset { reg, .. } => {
            buf.push(guard(ADDR_REG, reg));
            buf.push(xxr_imm(idat, rt));
        }
        Operand::MemPreIdx { reg, .. } => {
            buf.push(guard(ADDR_REG, reg));
            buf.push(xxr_imm(idat, rt));
        }
        Operand::MemPostIdxImm { reg, .. } => {
            buf.push(guard(ADDR_REG, reg));
            buf.push(xxr_imm(idat, rt));
        }
        _ => {}
    };
    if load && rt == TMP_REG {
        buf.push(guard(RET_REG, TMP_REG));
    }
    return buf.n > 0;
}

fn xxp_imm(input: u32, rt1: Reg, rt2: Reg) -> u32 {
    let input = input & !(0b11111 << 10) & !(0b11111 << 5) & !(0b11111);
    return input | (num(rt2) << 10) | (num(ADDR_REG) << 5) | (num(rt1));
}

fn do_addrmulti(idat: u32, op: Operand, rt1: Reg, rt2: Reg, load: bool, buf: &mut Buf) -> bool {
    let (mut rt1, mut rt2) = (rt1, rt2);
    if load && rt1 == RET_REG {
        rt1 = TMP_REG;
    }
    if load && rt2 == RET_REG {
        rt2 = TMP_REG;
    }
    match op {
        Operand::MemReg(rm) => {
            buf.push(guard(ADDR_REG, rm));
            buf.push(xxp_imm(idat, rt1, rt2));
        }
        Operand::MemOffset { reg, .. } => {
            buf.push(guard(ADDR_REG, reg));
            buf.push(xxp_imm(idat, rt1, rt2));
        }
        Operand::MemPreIdx { reg, .. } => {
            buf.push(guard(ADDR_REG, reg));
            buf.push(xxp_imm(idat, rt1, rt2));
        }
        Operand::MemPostIdxImm { reg, .. } => {
            buf.push(guard(ADDR_REG, reg));
            buf.push(xxp_imm(idat, rt1, rt2));
        }
        _ => {}
    };
    if load && rt1 == TMP_REG || rt2 == TMP_REG {
        buf.push(guard(RET_REG, TMP_REG));
    }
    return buf.n > 0;
}

fn rt(insn: &Instruction) -> Reg {
    let Operand::Reg { reg: rt, .. } = insn.operands()[0] else {
        println!("op 0 not a register");
        unsafe {
            FAILED = true;
        }
        return SP_REG;
    };
    return rt;
}

fn rt2(insn: &Instruction) -> Reg {
    let Operand::Reg { reg: rt, .. } = insn.operands()[1] else {
        panic!("op 1 not a register");
    };
    return rt;
}

fn do_mem(idat: u32, insn: &Instruction, buf: &mut Buf) -> bool {
    match insn.op() {
        // Memory accesses that can be optimized with the uxtw address mode.
        Op::LDR => {
            if let Operand::Reg { reg: rt, .. } = insn.operands()[0] {
                if isgpr(rt) || issimd(rt) {
                    return do_addropt(idat, insn.operands()[1], rt, true, ldr_uxtw, buf);
                }
            }
            // SVE or SME load, which we do not support
            return false;
        }
        Op::LDRB => do_addropt(idat, insn.operands()[1], rt(insn), true, ldrb_uxtw, buf),
        Op::LDRH => do_addropt(idat, insn.operands()[1], rt(insn), true, ldrh_uxtw, buf),
        Op::LDRSB => do_addropt(idat, insn.operands()[1], rt(insn), true, ldrsb_uxtw, buf),
        Op::LDRSH => do_addropt(idat, insn.operands()[1], rt(insn), true, ldrsh_uxtw, buf),
        Op::LDRSW => do_addropt(idat, insn.operands()[1], rt(insn), true, ldrsw_uxtw, buf),

        Op::STR => {
            if let Operand::Reg { reg: rt, .. } = insn.operands()[0] {
                if isgpr(rt) || issimd(rt) {
                    return do_addropt(idat, insn.operands()[1], rt, false, str_uxtw, buf);
                }
            }
            // SVE or SME store, which we do not support
            return false;
        }
        Op::STRB => do_addropt(idat, insn.operands()[1], rt(insn), false, strb_uxtw, buf),
        Op::STRH => do_addropt(idat, insn.operands()[1], rt(insn), false, strh_uxtw, buf),

        // Single memory accesses that cannot be optimized.
        Op::LDUR => do_addr(idat, insn.operands()[1], rt(insn), true, buf),
        Op::LDURB => do_addr(idat, insn.operands()[1], rt(insn), true, buf),
        Op::LDURH => do_addr(idat, insn.operands()[1], rt(insn), true, buf),
        Op::LDURSB => do_addr(idat, insn.operands()[1], rt(insn), true, buf),
        Op::LDURSH => do_addr(idat, insn.operands()[1], rt(insn), true, buf),
        Op::LDURSW => do_addr(idat, insn.operands()[1], rt(insn), true, buf),

        Op::STUR => do_addr(idat, insn.operands()[1], rt(insn), false, buf),
        Op::STURB => do_addr(idat, insn.operands()[1], rt(insn), false, buf),
        Op::STURH => do_addr(idat, insn.operands()[1], rt(insn), false, buf),

        // Multi memory accesses (cannot be optimized).
        Op::LDP => do_addrmulti(idat, insn.operands()[1], rt(insn), rt2(insn), true, buf),

        Op::STP => do_addrmulti(idat, insn.operands()[1], rt(insn), rt2(insn), true, buf),
        _ => false,
    }
}

fn arith_lo(idat: u32, rd: Reg) -> u32 {
    let idat = idat & !(1 << 31) & !(0b1111);
    return idat | num(rd);
}

// Modifications to the stack pointer.
fn do_modsp(idat: u32, insn: &Instruction, buf: &mut Buf) -> bool {
    match insn.op() {
        Op::ADD | Op::SUB => {
            buf.push(arith_lo(idat, TMP_REG));
            buf.push(guard(SP_REG, TMP_REG));
            return true;
        }
        _ => {
            return false;
        }
    }
}

#[no_mangle]
pub extern "C" fn lfi_reassemble(idat: u32, raw: *mut u32, size: usize) -> usize {
    let result = unsafe { core::slice::from_raw_parts_mut(raw, size) };

    let mut buf = Buf { data: result, n: 0 };

    if let Ok(insn) = bad64::decode(idat, 0) {
        if do_branch(&insn, &mut buf) {
            unsafe {
                if FAILED {
                    panic!("failed: {:x}", idat);
                }
            }
            return buf.n;
        }
        if do_mem(idat, &insn, &mut buf) {
            unsafe {
                if FAILED {
                    panic!("failed: {:x}", idat);
                }
            }
            return buf.n;
        }
        if do_modsp(idat, &insn, &mut buf) {
            unsafe {
                if FAILED {
                    panic!("failed: {:x}", idat);
                }
            }
            return buf.n;
        }
    }

    buf.push(idat);
    return buf.n;
}

fn v128(r: Reg) -> bool {
    match r {
        Reg::Q0 => true,
        Reg::Q1 => true,
        Reg::Q2 => true,
        Reg::Q3 => true,
        Reg::Q4 => true,
        Reg::Q5 => true,
        Reg::Q6 => true,
        Reg::Q7 => true,
        Reg::Q8 => true,
        Reg::Q9 => true,
        Reg::Q10 => true,
        Reg::Q11 => true,
        Reg::Q12 => true,
        Reg::Q13 => true,
        Reg::Q14 => true,
        Reg::Q15 => true,
        Reg::Q16 => true,
        Reg::Q17 => true,
        Reg::Q18 => true,
        Reg::Q19 => true,
        Reg::Q20 => true,
        Reg::Q21 => true,
        Reg::Q22 => true,
        Reg::Q23 => true,
        Reg::Q24 => true,
        Reg::Q25 => true,
        Reg::Q26 => true,
        Reg::Q27 => true,
        Reg::Q28 => true,
        Reg::Q29 => true,
        Reg::Q30 => true,
        Reg::Q31 => true,
        _ => false,
    }
}

fn v64(r: Reg) -> bool {
    match r {
        Reg::D0 => true,
        Reg::D1 => true,
        Reg::D2 => true,
        Reg::D3 => true,
        Reg::D4 => true,
        Reg::D5 => true,
        Reg::D6 => true,
        Reg::D7 => true,
        Reg::D8 => true,
        Reg::D9 => true,
        Reg::D10 => true,
        Reg::D11 => true,
        Reg::D12 => true,
        Reg::D13 => true,
        Reg::D14 => true,
        Reg::D15 => true,
        Reg::D16 => true,
        Reg::D17 => true,
        Reg::D18 => true,
        Reg::D19 => true,
        Reg::D20 => true,
        Reg::D21 => true,
        Reg::D22 => true,
        Reg::D23 => true,
        Reg::D24 => true,
        Reg::D25 => true,
        Reg::D26 => true,
        Reg::D27 => true,
        Reg::D28 => true,
        Reg::D29 => true,
        Reg::D30 => true,
        Reg::D31 => true,
        _ => false,
    }
}

fn v32(r: Reg) -> bool {
    match r {
        Reg::S0 => true,
        Reg::S1 => true,
        Reg::S2 => true,
        Reg::S3 => true,
        Reg::S4 => true,
        Reg::S5 => true,
        Reg::S6 => true,
        Reg::S7 => true,
        Reg::S8 => true,
        Reg::S9 => true,
        Reg::S10 => true,
        Reg::S11 => true,
        Reg::S12 => true,
        Reg::S13 => true,
        Reg::S14 => true,
        Reg::S15 => true,
        Reg::S16 => true,
        Reg::S17 => true,
        Reg::S18 => true,
        Reg::S19 => true,
        Reg::S20 => true,
        Reg::S21 => true,
        Reg::S22 => true,
        Reg::S23 => true,
        Reg::S24 => true,
        Reg::S25 => true,
        Reg::S26 => true,
        Reg::S27 => true,
        Reg::S28 => true,
        Reg::S29 => true,
        Reg::S30 => true,
        Reg::S31 => true,
        _ => false,
    }
}

fn v16(r: Reg) -> bool {
    match r {
        Reg::H0 => true,
        Reg::H1 => true,
        Reg::H2 => true,
        Reg::H3 => true,
        Reg::H4 => true,
        Reg::H5 => true,
        Reg::H6 => true,
        Reg::H7 => true,
        Reg::H8 => true,
        Reg::H9 => true,
        Reg::H10 => true,
        Reg::H11 => true,
        Reg::H12 => true,
        Reg::H13 => true,
        Reg::H14 => true,
        Reg::H15 => true,
        Reg::H16 => true,
        Reg::H17 => true,
        Reg::H18 => true,
        Reg::H19 => true,
        Reg::H20 => true,
        Reg::H21 => true,
        Reg::H22 => true,
        Reg::H23 => true,
        Reg::H24 => true,
        Reg::H25 => true,
        Reg::H26 => true,
        Reg::H27 => true,
        Reg::H28 => true,
        Reg::H29 => true,
        Reg::H30 => true,
        Reg::H31 => true,
        _ => false,
    }
}

fn v8(r: Reg) -> bool {
    match r {
        Reg::B0 => true,
        Reg::B1 => true,
        Reg::B2 => true,
        Reg::B3 => true,
        Reg::B4 => true,
        Reg::B5 => true,
        Reg::B6 => true,
        Reg::B7 => true,
        Reg::B8 => true,
        Reg::B9 => true,
        Reg::B10 => true,
        Reg::B11 => true,
        Reg::B12 => true,
        Reg::B13 => true,
        Reg::B14 => true,
        Reg::B15 => true,
        Reg::B16 => true,
        Reg::B17 => true,
        Reg::B18 => true,
        Reg::B19 => true,
        Reg::B20 => true,
        Reg::B21 => true,
        Reg::B22 => true,
        Reg::B23 => true,
        Reg::B24 => true,
        Reg::B25 => true,
        Reg::B26 => true,
        Reg::B27 => true,
        Reg::B28 => true,
        Reg::B29 => true,
        Reg::B30 => true,
        Reg::BZR => true,
        _ => false,
    }
}

fn islo(r: Reg) -> bool {
    match r {
        Reg::W0 => true,
        Reg::W1 => true,
        Reg::W2 => true,
        Reg::W3 => true,
        Reg::W4 => true,
        Reg::W5 => true,
        Reg::W6 => true,
        Reg::W7 => true,
        Reg::W8 => true,
        Reg::W9 => true,
        Reg::W10 => true,
        Reg::W11 => true,
        Reg::W12 => true,
        Reg::W13 => true,
        Reg::W14 => true,
        Reg::W15 => true,
        Reg::W16 => true,
        Reg::W17 => true,
        Reg::W18 => true,
        Reg::W19 => true,
        Reg::W20 => true,
        Reg::W21 => true,
        Reg::W22 => true,
        Reg::W23 => true,
        Reg::W24 => true,
        Reg::W25 => true,
        Reg::W26 => true,
        Reg::W27 => true,
        Reg::W28 => true,
        Reg::W29 => true,
        Reg::W30 => true,
        Reg::WZR => true,
        Reg::WSP => true,
        _ => false,
    }
}

fn ishi(r: Reg) -> bool {
    match r {
        Reg::X0 => true,
        Reg::X1 => true,
        Reg::X2 => true,
        Reg::X3 => true,
        Reg::X4 => true,
        Reg::X5 => true,
        Reg::X6 => true,
        Reg::X7 => true,
        Reg::X8 => true,
        Reg::X9 => true,
        Reg::X10 => true,
        Reg::X11 => true,
        Reg::X12 => true,
        Reg::X13 => true,
        Reg::X14 => true,
        Reg::X15 => true,
        Reg::X16 => true,
        Reg::X17 => true,
        Reg::X18 => true,
        Reg::X19 => true,
        Reg::X20 => true,
        Reg::X21 => true,
        Reg::X22 => true,
        Reg::X23 => true,
        Reg::X24 => true,
        Reg::X25 => true,
        Reg::X26 => true,
        Reg::X27 => true,
        Reg::X28 => true,
        Reg::X29 => true,
        Reg::X30 => true,
        Reg::XZR => true,
        Reg::SP => true,
        _ => false,
    }
}

fn isgpr(r: Reg) -> bool {
    return islo(r) || ishi(r);
}

fn issimd(r: Reg) -> bool {
    return v128(r) || v64(r) || v32(r) || v16(r) || v8(r);
}

#[rustfmt::skip]
fn num(r: Reg) -> u32 {
    match r {
        Reg::X0 | Reg::W0 | Reg::Q0 | Reg::D0 | Reg::S0 | Reg::H0 | Reg::B0 | Reg::P0 | Reg::Z0 | Reg::V0 => 0,
        Reg::X1 | Reg::W1 | Reg::Q1 | Reg::D1 | Reg::S1 | Reg::H1 | Reg::B1 | Reg::P1 | Reg::Z1 | Reg::V1 => 1,
        Reg::X2 | Reg::W2 | Reg::Q2 | Reg::D2 | Reg::S2 | Reg::H2 | Reg::B2 | Reg::P2 | Reg::Z2 | Reg::V2 => 2,
        Reg::X3 | Reg::W3 | Reg::Q3 | Reg::D3 | Reg::S3 | Reg::H3 | Reg::B3 | Reg::P3 | Reg::Z3 | Reg::V3 => 3,
        Reg::X4 | Reg::W4 | Reg::Q4 | Reg::D4 | Reg::S4 | Reg::H4 | Reg::B4 | Reg::P4 | Reg::Z4 | Reg::V4 => 4,
        Reg::X5 | Reg::W5 | Reg::Q5 | Reg::D5 | Reg::S5 | Reg::H5 | Reg::B5 | Reg::P5 | Reg::Z5 | Reg::V5 => 5,
        Reg::X6 | Reg::W6 | Reg::Q6 | Reg::D6 | Reg::S6 | Reg::H6 | Reg::B6 | Reg::P6 | Reg::Z6 | Reg::V6 => 6,
        Reg::X7 | Reg::W7 | Reg::Q7 | Reg::D7 | Reg::S7 | Reg::H7 | Reg::B7 | Reg::P7 | Reg::Z7 | Reg::V7 => 7,
        Reg::X8 | Reg::W8 | Reg::Q8 | Reg::D8 | Reg::S8 | Reg::H8 | Reg::B8 | Reg::P8 | Reg::Z8 | Reg::V8 => 8,
        Reg::X9 | Reg::W9 | Reg::Q9 | Reg::D9 | Reg::S9 | Reg::H9 | Reg::B9 | Reg::P9 | Reg::Z9 | Reg::V9 => 9,
        Reg::X10 | Reg::W10 | Reg::Q10 | Reg::D10 | Reg::S10 | Reg::H10 | Reg::B10 | Reg::P10 | Reg::Z10 | Reg::V10 => 10,
        Reg::X11 | Reg::W11 | Reg::Q11 | Reg::D11 | Reg::S11 | Reg::H11 | Reg::B11 | Reg::P11 | Reg::Z11 | Reg::V11 => 11,
        Reg::X12 | Reg::W12 | Reg::Q12 | Reg::D12 | Reg::S12 | Reg::H12 | Reg::B12 | Reg::P12 | Reg::Z12 | Reg::V12 => 12,
        Reg::X13 | Reg::W13 | Reg::Q13 | Reg::D13 | Reg::S13 | Reg::H13 | Reg::B13 | Reg::P13 | Reg::Z13 | Reg::V13 => 13,
        Reg::X14 | Reg::W14 | Reg::Q14 | Reg::D14 | Reg::S14 | Reg::H14 | Reg::B14 | Reg::P14 | Reg::Z14 | Reg::V14 => 14,
        Reg::X15 | Reg::W15 | Reg::Q15 | Reg::D15 | Reg::S15 | Reg::H15 | Reg::B15 | Reg::P15 | Reg::Z15 | Reg::V15 => 15,
        Reg::X16 | Reg::W16 | Reg::Q16 | Reg::D16 | Reg::S16 | Reg::H16 | Reg::B16 | Reg::P16 | Reg::Z16 | Reg::V16 => 16,
        Reg::X17 | Reg::W17 | Reg::Q17 | Reg::D17 | Reg::S17 | Reg::H17 | Reg::B17 | Reg::P17 | Reg::Z17 | Reg::V17 => 17,
        Reg::X18 | Reg::W18 | Reg::Q18 | Reg::D18 | Reg::S18 | Reg::H18 | Reg::B18 | Reg::P18 | Reg::Z18 | Reg::V18 => 18,
        Reg::X19 | Reg::W19 | Reg::Q19 | Reg::D19 | Reg::S19 | Reg::H19 | Reg::B19 | Reg::P19 | Reg::Z19 | Reg::V19 => 19,
        Reg::X20 | Reg::W20 | Reg::Q20 | Reg::D20 | Reg::S20 | Reg::H20 | Reg::B20 | Reg::P20 | Reg::Z20 | Reg::V20 => 20,
        Reg::X21 | Reg::W21 | Reg::Q21 | Reg::D21 | Reg::S21 | Reg::H21 | Reg::B21 | Reg::P21 | Reg::Z21 | Reg::V21 => 21,
        Reg::X22 | Reg::W22 | Reg::Q22 | Reg::D22 | Reg::S22 | Reg::H22 | Reg::B22 | Reg::P22 | Reg::Z22 | Reg::V22 => 22,
        Reg::X23 | Reg::W23 | Reg::Q23 | Reg::D23 | Reg::S23 | Reg::H23 | Reg::B23 | Reg::P23 | Reg::Z23 | Reg::V23 => 23,
        Reg::X24 | Reg::W24 | Reg::Q24 | Reg::D24 | Reg::S24 | Reg::H24 | Reg::B24 | Reg::P24 | Reg::Z24 | Reg::V24 => 24,
        Reg::X25 | Reg::W25 | Reg::Q25 | Reg::D25 | Reg::S25 | Reg::H25 | Reg::B25 | Reg::P25 | Reg::Z25 | Reg::V25 => 25,
        Reg::X26 | Reg::W26 | Reg::Q26 | Reg::D26 | Reg::S26 | Reg::H26 | Reg::B26 | Reg::P26 | Reg::Z26 | Reg::V26 => 26,
        Reg::X27 | Reg::W27 | Reg::Q27 | Reg::D27 | Reg::S27 | Reg::H27 | Reg::B27 | Reg::P27 | Reg::Z27 | Reg::V27 => 27,
        Reg::X28 | Reg::W28 | Reg::Q28 | Reg::D28 | Reg::S28 | Reg::H28 | Reg::B28 | Reg::P28 | Reg::Z28 | Reg::V28 => 28,
        Reg::X29 | Reg::W29 | Reg::Q29 | Reg::D29 | Reg::S29 | Reg::H29 | Reg::B29 | Reg::P29 | Reg::Z29 | Reg::V29 => 29,
        Reg::X30 | Reg::W30 | Reg::Q30 | Reg::D30 | Reg::S30 | Reg::H30 | Reg::B30 | Reg::P30 | Reg::Z30 | Reg::V30 => 30,
        Reg::XZR | Reg::WZR | Reg::Q31 | Reg::QZR | Reg::D31 | Reg::DZR | Reg::S31 | Reg::SZR | Reg::H31 | Reg::HZR | Reg::B31 | Reg::BZR | Reg::P31 | Reg::Z31 | Reg::V31 | Reg::VZR => 31,
        Reg::SP | Reg::WSP => 31,
    }
}
