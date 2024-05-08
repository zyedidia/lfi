use bad64::Op;

use crate::autogen::is_allowed_autogen;

// Some instruction type definitions. Partially auto-verified using armgen.

pub fn nomodify(op: Op) -> bool {
    match op {
        // arithmetic
        Op::NOP => true,
        Op::CMP => true,
        Op::CMN => true,
        Op::PRFM => true,
        Op::PRFUM => true,
        // branches
        Op::RET => true,
        Op::BLR => true,
        Op::BR => true,
        Op::BL => true,
        Op::BTI => true,
        Op::B_AL => true,
        Op::B_CC => true,
        Op::B_CS => true,
        Op::B_EQ => true,
        Op::B_GE => true,
        Op::B_GT => true,
        Op::B_HI => true,
        Op::B_LE => true,
        Op::B_LS => true,
        Op::B_LT => true,
        Op::B_MI => true,
        Op::B_NE => true,
        Op::B_NV => true,
        Op::B_PL => true,
        Op::B_VC => true,
        Op::B_VS => true,
        Op::B => true,
        Op::TBZ => true,
        Op::TBNZ => true,
        Op::CBZ => true,
        Op::CBNZ => true,
        // stores
        Op::ST1 => true,
        Op::ST2 => true,
        Op::ST3 => true,
        Op::ST4 => true,
        Op::STLR => true,
        Op::STLRB => true,
        Op::STLRH => true,
        Op::STNP => true,
        Op::STP => true,
        Op::STR => true,
        Op::STRB => true,
        Op::STRH => true,
        Op::STTR => true,
        Op::STTRB => true,
        Op::STTRH => true,
        Op::STUR => true,
        Op::STURB => true,
        Op::STURH => true,

        _ => false,
    }
}

pub fn is_multimod(op: Op) -> bool {
    match op {
        Op::LDP => true,
        Op::LDPSW => true,
        Op::LDNP => true,
        Op::LDXP => true,
        Op::LDAXP => true,
        _ => false,
    }
}

pub fn is_allowed(op: Op) -> bool {
    match op {
        Op::NOP => true,
        Op::MSR | Op::MRS => true,
        Op::DMB => true,
        Op::BFC => true,
        Op::UXTL2 | Op::SXTL2 => true,
        Op::UADDW2 | Op::UADDL2 | Op::SSUBW2 | Op::USUBL2 | Op::UMULL2 | Op::UMLAL2 => true,
        Op::FMLA | Op::FMLS => true,
        Op::FABD => true,
        Op::FADDP => true,
        Op::FCVTN2 | Op::FCVTL2 => true,
        Op::FCMGE | Op::FCMGT | Op::FCMLE | Op::FCMEQ | Op::FCMLT => true,
        Op::BRK => true,
        Op::XTN2 => true,
        Op::SHRN2 => true,
        Op::AUTIA1716 | Op::AUTIB1716 => true,
        Op::STLR => true,
        Op::BTI => true,
        Op::XPACLRI | Op::XPACI | Op::XPACD => true,
        Op::CNTD | Op::CNTB | Op::CNTH | Op::CNTP | Op::CNTW => true,
        _ => is_allowed_autogen(op),
    }
}
