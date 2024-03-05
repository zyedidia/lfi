#pragma once

#include <capstone/capstone.h>

static inline bool is_lo(aarch64_reg reg) {
    switch (reg) {
    case AArch64_REG_W0:
    case AArch64_REG_W1:
    case AArch64_REG_W2:
    case AArch64_REG_W3:
    case AArch64_REG_W4:
    case AArch64_REG_W5:
    case AArch64_REG_W6:
    case AArch64_REG_W7:
    case AArch64_REG_W8:
    case AArch64_REG_W9:
    case AArch64_REG_W10:
    case AArch64_REG_W11:
    case AArch64_REG_W12:
    case AArch64_REG_W13:
    case AArch64_REG_W14:
    case AArch64_REG_W15:
    case AArch64_REG_W16:
    case AArch64_REG_W17:
    case AArch64_REG_W18:
    case AArch64_REG_W19:
    case AArch64_REG_W20:
    case AArch64_REG_W21:
    case AArch64_REG_W22:
    case AArch64_REG_W23:
    case AArch64_REG_W24:
    case AArch64_REG_W25:
    case AArch64_REG_W26:
    case AArch64_REG_W27:
    case AArch64_REG_W28:
    case AArch64_REG_W29:
    case AArch64_REG_W30:
        return true;
    default:
        return false;
    }
}

static inline bool is_ldr_imm(cs_insn* insn) {
    switch (insn->id) {
        case AArch64_INS_LDR:
        case AArch64_INS_LDRSW:
        case AArch64_INS_PRFM:
            return true;
        default:
            return false;
    }
}

static inline bool is_uxtw(cs_aarch64_op* op) {
    if (op->shift.value == 0 && op->ext == AArch64_EXT_UXTW) {
        return true;
    }
    return false;
}

static inline bool is_indbranch(cs_insn* insn) {
    switch (insn->id) {
    case AArch64_INS_BLR:
    case AArch64_INS_RET:
    case AArch64_INS_BR:
        return true;
    default:
        return false;
    }
}

static inline bool is_msr(cs_insn* insn) {
    return insn->id == AArch64_INS_MSR;
}

static inline bool is_mrs(cs_insn* insn) {
    return insn->id == AArch64_INS_MRS;
}

static inline bool is_legal(cs_insn* insn) {
    switch (insn->id) {
    case AArch64_INS_ABS:
	case AArch64_INS_ADCLB:
	case AArch64_INS_ADCLT:
	case AArch64_INS_ADCS:
	case AArch64_INS_ADC:
	case AArch64_INS_ADDG:
	case AArch64_INS_ADDHA:
	case AArch64_INS_ADDHNB:
	case AArch64_INS_ADDHNT:
	case AArch64_INS_ADDHN:
	case AArch64_INS_ADDHN2:
	case AArch64_INS_ADDPL:
	case AArch64_INS_ADDP:
	case AArch64_INS_ADDQV:
	case AArch64_INS_ADDSPL:
	case AArch64_INS_ADDSVL:
	case AArch64_INS_ADDS:
	case AArch64_INS_ADDVA:
	case AArch64_INS_ADDVL:
	case AArch64_INS_ADDV:
	case AArch64_INS_ADD:
	case AArch64_INS_ADR:
	case AArch64_INS_ADRP:
	// case AArch64_INS_AESD:
	// case AArch64_INS_AESE:
	// case AArch64_INS_AESIMC:
	// case AArch64_INS_AESMC:
	case AArch64_INS_ANDQV:
	case AArch64_INS_ANDS:
	case AArch64_INS_ANDV:
	case AArch64_INS_AND:
	case AArch64_INS_ASRD:
	case AArch64_INS_ASRR:
	case AArch64_INS_ASR:
	case AArch64_INS_AUTDA:
	case AArch64_INS_AUTDB:
	case AArch64_INS_AUTDZA:
	case AArch64_INS_AUTDZB:
	case AArch64_INS_AUTIA:
	case AArch64_INS_HINT:
	case AArch64_INS_AUTIB:
	case AArch64_INS_AUTIZA:
	case AArch64_INS_AUTIZB:
	case AArch64_INS_AXFLAG:
	case AArch64_INS_B:
	case AArch64_INS_BCAX:
	case AArch64_INS_BC:
	case AArch64_INS_BDEP:
	case AArch64_INS_BEXT:
	case AArch64_INS_BFDOT:
	case AArch64_INS_BFADD:
	case AArch64_INS_BFCLAMP:
	case AArch64_INS_BFCVT:
	case AArch64_INS_BFCVTN:
	case AArch64_INS_BFCVTN2:
	case AArch64_INS_BFCVTNT:
	case AArch64_INS_BFMAXNM:
	case AArch64_INS_BFMAX:
	case AArch64_INS_BFMINNM:
	case AArch64_INS_BFMIN:
	case AArch64_INS_BFMLALB:
	case AArch64_INS_BFMLALT:
	case AArch64_INS_BFMLAL:
	case AArch64_INS_BFMLA:
	case AArch64_INS_BFMLSLB:
	case AArch64_INS_BFMLSLT:
	case AArch64_INS_BFMLSL:
	case AArch64_INS_BFMLS:
	case AArch64_INS_BFMMLA:
	case AArch64_INS_BFMOPA:
	case AArch64_INS_BFMOPS:
	case AArch64_INS_BFMUL:
	case AArch64_INS_BFM:
	case AArch64_INS_BFSUB:
	case AArch64_INS_BFVDOT:
	case AArch64_INS_BGRP:
	case AArch64_INS_BICS:
	case AArch64_INS_BIC:
	case AArch64_INS_BIF:
	case AArch64_INS_BIT:
	case AArch64_INS_BL:
	case AArch64_INS_BLR:
	case AArch64_INS_BLRAA:
	case AArch64_INS_BLRAAZ:
	case AArch64_INS_BLRAB:
	case AArch64_INS_BLRABZ:
	case AArch64_INS_BMOPA:
	case AArch64_INS_BMOPS:
	case AArch64_INS_BR:
	case AArch64_INS_BRAA:
	case AArch64_INS_BRAAZ:
	case AArch64_INS_BRAB:
	case AArch64_INS_BRABZ:
	case AArch64_INS_BRB:
	case AArch64_INS_BRK:
	case AArch64_INS_BRKAS:
	case AArch64_INS_BRKA:
	case AArch64_INS_BRKBS:
	case AArch64_INS_BRKB:
	case AArch64_INS_BRKNS:
	case AArch64_INS_BRKN:
	case AArch64_INS_BRKPAS:
	case AArch64_INS_BRKPA:
	case AArch64_INS_BRKPBS:
	case AArch64_INS_BRKPB:
	case AArch64_INS_BSL1N:
	case AArch64_INS_BSL2N:
	case AArch64_INS_BSL:
	case AArch64_INS_CADD:
	// case AArch64_INS_CASAB:
	// case AArch64_INS_CASAH:
	// case AArch64_INS_CASALB:
	// case AArch64_INS_CASALH:
	// case AArch64_INS_CASAL:
	// case AArch64_INS_CASA:
	// case AArch64_INS_CASB:
	// case AArch64_INS_CASH:
	// case AArch64_INS_CASLB:
	// case AArch64_INS_CASLH:
	// case AArch64_INS_CASL:
	// case AArch64_INS_CASPAL:
	// case AArch64_INS_CASPA:
	// case AArch64_INS_CASPL:
	// case AArch64_INS_CASP:
	// case AArch64_INS_CAS:
	case AArch64_INS_CBNZ:
	case AArch64_INS_CBZ:
	case AArch64_INS_CCMN:
	case AArch64_INS_CCMP:
	case AArch64_INS_CDOT:
	case AArch64_INS_CFINV:
	case AArch64_INS_CLASTA:
	case AArch64_INS_CLASTB:
	case AArch64_INS_CLREX:
	case AArch64_INS_CLS:
	case AArch64_INS_CLZ:
	case AArch64_INS_CMEQ:
	case AArch64_INS_CMGE:
	case AArch64_INS_CMGT:
	case AArch64_INS_CMHI:
	case AArch64_INS_CMHS:
	case AArch64_INS_CMLA:
	case AArch64_INS_CMLE:
	case AArch64_INS_CMLT:
	case AArch64_INS_CMPEQ:
	case AArch64_INS_CMPGE:
	case AArch64_INS_CMPGT:
	case AArch64_INS_CMPHI:
	case AArch64_INS_CMPHS:
	case AArch64_INS_CMPLE:
	case AArch64_INS_CMPLO:
	case AArch64_INS_CMPLS:
	case AArch64_INS_CMPLT:
	case AArch64_INS_CMPNE:
	case AArch64_INS_CMTST:
	case AArch64_INS_CNOT:
	case AArch64_INS_CNTB:
	case AArch64_INS_CNTD:
	case AArch64_INS_CNTH:
	case AArch64_INS_CNTP:
	case AArch64_INS_CNTW:
	case AArch64_INS_CNT:
	case AArch64_INS_COMPACT:
	// case AArch64_INS_CPYE:
	// case AArch64_INS_CPYEN:
	// case AArch64_INS_CPYERN:
	// case AArch64_INS_CPYERT:
	// case AArch64_INS_CPYERTN:
	// case AArch64_INS_CPYERTRN:
	// case AArch64_INS_CPYERTWN:
	// case AArch64_INS_CPYET:
	// case AArch64_INS_CPYETN:
	// case AArch64_INS_CPYETRN:
	// case AArch64_INS_CPYETWN:
	// case AArch64_INS_CPYEWN:
	// case AArch64_INS_CPYEWT:
	// case AArch64_INS_CPYEWTN:
	// case AArch64_INS_CPYEWTRN:
	// case AArch64_INS_CPYEWTWN:
	// case AArch64_INS_CPYFE:
	// case AArch64_INS_CPYFEN:
	// case AArch64_INS_CPYFERN:
	// case AArch64_INS_CPYFERT:
	// case AArch64_INS_CPYFERTN:
	// case AArch64_INS_CPYFERTRN:
	// case AArch64_INS_CPYFERTWN:
	// case AArch64_INS_CPYFET:
	// case AArch64_INS_CPYFETN:
	// case AArch64_INS_CPYFETRN:
	// case AArch64_INS_CPYFETWN:
	// case AArch64_INS_CPYFEWN:
	// case AArch64_INS_CPYFEWT:
	// case AArch64_INS_CPYFEWTN:
	// case AArch64_INS_CPYFEWTRN:
	// case AArch64_INS_CPYFEWTWN:
	// case AArch64_INS_CPYFM:
	// case AArch64_INS_CPYFMN:
	// case AArch64_INS_CPYFMRN:
	// case AArch64_INS_CPYFMRT:
	// case AArch64_INS_CPYFMRTN:
	// case AArch64_INS_CPYFMRTRN:
	// case AArch64_INS_CPYFMRTWN:
	// case AArch64_INS_CPYFMT:
	// case AArch64_INS_CPYFMTN:
	// case AArch64_INS_CPYFMTRN:
	// case AArch64_INS_CPYFMTWN:
	// case AArch64_INS_CPYFMWN:
	// case AArch64_INS_CPYFMWT:
	// case AArch64_INS_CPYFMWTN:
	// case AArch64_INS_CPYFMWTRN:
	// case AArch64_INS_CPYFMWTWN:
	// case AArch64_INS_CPYFP:
	// case AArch64_INS_CPYFPN:
	// case AArch64_INS_CPYFPRN:
	// case AArch64_INS_CPYFPRT:
	// case AArch64_INS_CPYFPRTN:
	// case AArch64_INS_CPYFPRTRN:
	// case AArch64_INS_CPYFPRTWN:
	// case AArch64_INS_CPYFPT:
	// case AArch64_INS_CPYFPTN:
	// case AArch64_INS_CPYFPTRN:
	// case AArch64_INS_CPYFPTWN:
	// case AArch64_INS_CPYFPWN:
	// case AArch64_INS_CPYFPWT:
	// case AArch64_INS_CPYFPWTN:
	// case AArch64_INS_CPYFPWTRN:
	// case AArch64_INS_CPYFPWTWN:
	// case AArch64_INS_CPYM:
	// case AArch64_INS_CPYMN:
	// case AArch64_INS_CPYMRN:
	// case AArch64_INS_CPYMRT:
	// case AArch64_INS_CPYMRTN:
	// case AArch64_INS_CPYMRTRN:
	// case AArch64_INS_CPYMRTWN:
	// case AArch64_INS_CPYMT:
	// case AArch64_INS_CPYMTN:
	// case AArch64_INS_CPYMTRN:
	// case AArch64_INS_CPYMTWN:
	// case AArch64_INS_CPYMWN:
	// case AArch64_INS_CPYMWT:
	// case AArch64_INS_CPYMWTN:
	// case AArch64_INS_CPYMWTRN:
	// case AArch64_INS_CPYMWTWN:
	// case AArch64_INS_CPYP:
	// case AArch64_INS_CPYPN:
	// case AArch64_INS_CPYPRN:
	// case AArch64_INS_CPYPRT:
	// case AArch64_INS_CPYPRTN:
	// case AArch64_INS_CPYPRTRN:
	// case AArch64_INS_CPYPRTWN:
	// case AArch64_INS_CPYPT:
	// case AArch64_INS_CPYPTN:
	// case AArch64_INS_CPYPTRN:
	// case AArch64_INS_CPYPTWN:
	// case AArch64_INS_CPYPWN:
	// case AArch64_INS_CPYPWT:
	// case AArch64_INS_CPYPWTN:
	// case AArch64_INS_CPYPWTRN:
	// case AArch64_INS_CPYPWTWN:
	// case AArch64_INS_CPY:
	case AArch64_INS_CRC32B:
	case AArch64_INS_CRC32CB:
	case AArch64_INS_CRC32CH:
	case AArch64_INS_CRC32CW:
	case AArch64_INS_CRC32CX:
	case AArch64_INS_CRC32H:
	case AArch64_INS_CRC32W:
	case AArch64_INS_CRC32X:
	case AArch64_INS_CSEL:
	case AArch64_INS_CSINC:
	case AArch64_INS_CSINV:
	case AArch64_INS_CSNEG:
	case AArch64_INS_CTERMEQ:
	case AArch64_INS_CTERMNE:
	case AArch64_INS_CTZ:
	// case AArch64_INS_DCPS1:
	// case AArch64_INS_DCPS2:
	// case AArch64_INS_DCPS3:
	case AArch64_INS_DECB:
	case AArch64_INS_DECD:
	case AArch64_INS_DECH:
	case AArch64_INS_DECP:
	case AArch64_INS_DECW:
	// case AArch64_INS_DMB:
	case AArch64_INS_DRPS:
	// case AArch64_INS_DSB:
	case AArch64_INS_DUPM:
	case AArch64_INS_DUPQ:
	case AArch64_INS_DUP:
	case AArch64_INS_MOV:
	case AArch64_INS_EON:
	case AArch64_INS_EOR3:
	case AArch64_INS_EORBT:
	case AArch64_INS_EORQV:
	case AArch64_INS_EORS:
	case AArch64_INS_EORTB:
	case AArch64_INS_EORV:
	case AArch64_INS_EOR:
	case AArch64_INS_ERET:
	case AArch64_INS_ERETAA:
	case AArch64_INS_ERETAB:
	case AArch64_INS_EXTQ:
	case AArch64_INS_MOVA:
	case AArch64_INS_EXTR:
	case AArch64_INS_EXT:
	case AArch64_INS_FABD:
	case AArch64_INS_FABS:
	case AArch64_INS_FACGE:
	case AArch64_INS_FACGT:
	case AArch64_INS_FADDA:
	case AArch64_INS_FADD:
	case AArch64_INS_FADDP:
	case AArch64_INS_FADDQV:
	case AArch64_INS_FADDV:
	case AArch64_INS_FCADD:
	case AArch64_INS_FCCMP:
	case AArch64_INS_FCCMPE:
	case AArch64_INS_FCLAMP:
	case AArch64_INS_FCMEQ:
	case AArch64_INS_FCMGE:
	case AArch64_INS_FCMGT:
	case AArch64_INS_FCMLA:
	case AArch64_INS_FCMLE:
	case AArch64_INS_FCMLT:
	case AArch64_INS_FCMNE:
	case AArch64_INS_FCMP:
	case AArch64_INS_FCMPE:
	case AArch64_INS_FCMUO:
	case AArch64_INS_FCPY:
	case AArch64_INS_FCSEL:
	case AArch64_INS_FCVTAS:
	case AArch64_INS_FCVTAU:
	case AArch64_INS_FCVT:
	case AArch64_INS_FCVTLT:
	case AArch64_INS_FCVTL:
	case AArch64_INS_FCVTL2:
	case AArch64_INS_FCVTMS:
	case AArch64_INS_FCVTMU:
	case AArch64_INS_FCVTNS:
	case AArch64_INS_FCVTNT:
	case AArch64_INS_FCVTNU:
	case AArch64_INS_FCVTN:
	case AArch64_INS_FCVTN2:
	case AArch64_INS_FCVTPS:
	case AArch64_INS_FCVTPU:
	case AArch64_INS_FCVTXNT:
	case AArch64_INS_FCVTXN:
	case AArch64_INS_FCVTXN2:
	case AArch64_INS_FCVTX:
	case AArch64_INS_FCVTZS:
	case AArch64_INS_FCVTZU:
	case AArch64_INS_FDIV:
	case AArch64_INS_FDIVR:
	case AArch64_INS_FDOT:
	case AArch64_INS_FDUP:
	case AArch64_INS_FEXPA:
	case AArch64_INS_FJCVTZS:
	case AArch64_INS_FLOGB:
	case AArch64_INS_FMADD:
	case AArch64_INS_FMAD:
	case AArch64_INS_FMAX:
	case AArch64_INS_FMAXNM:
	case AArch64_INS_FMAXNMP:
	case AArch64_INS_FMAXNMQV:
	case AArch64_INS_FMAXNMV:
	case AArch64_INS_FMAXP:
	case AArch64_INS_FMAXQV:
	case AArch64_INS_FMAXV:
	case AArch64_INS_FMIN:
	case AArch64_INS_FMINNM:
	case AArch64_INS_FMINNMP:
	case AArch64_INS_FMINNMQV:
	case AArch64_INS_FMINNMV:
	case AArch64_INS_FMINP:
	case AArch64_INS_FMINQV:
	case AArch64_INS_FMINV:
	case AArch64_INS_FMLAL2:
	case AArch64_INS_FMLALB:
	case AArch64_INS_FMLALT:
	case AArch64_INS_FMLAL:
	case AArch64_INS_FMLA:
	case AArch64_INS_FMLSL2:
	case AArch64_INS_FMLSLB:
	case AArch64_INS_FMLSLT:
	case AArch64_INS_FMLSL:
	case AArch64_INS_FMLS:
	case AArch64_INS_FMMLA:
	case AArch64_INS_FMOPA:
	case AArch64_INS_FMOPS:
	case AArch64_INS_FMOV:
	case AArch64_INS_FMSB:
	case AArch64_INS_FMSUB:
	case AArch64_INS_FMUL:
	case AArch64_INS_FMULX:
	case AArch64_INS_FNEG:
	case AArch64_INS_FNMADD:
	case AArch64_INS_FNMAD:
	case AArch64_INS_FNMLA:
	case AArch64_INS_FNMLS:
	case AArch64_INS_FNMSB:
	case AArch64_INS_FNMSUB:
	case AArch64_INS_FNMUL:
	case AArch64_INS_FRECPE:
	case AArch64_INS_FRECPS:
	case AArch64_INS_FRECPX:
	case AArch64_INS_FRINT32X:
	case AArch64_INS_FRINT32Z:
	case AArch64_INS_FRINT64X:
	case AArch64_INS_FRINT64Z:
	case AArch64_INS_FRINTA:
	case AArch64_INS_FRINTI:
	case AArch64_INS_FRINTM:
	case AArch64_INS_FRINTN:
	case AArch64_INS_FRINTP:
	case AArch64_INS_FRINTX:
	case AArch64_INS_FRINTZ:
	case AArch64_INS_FRSQRTE:
	case AArch64_INS_FRSQRTS:
	case AArch64_INS_FSCALE:
	case AArch64_INS_FSQRT:
	case AArch64_INS_FSUB:
	case AArch64_INS_FSUBR:
	case AArch64_INS_FTMAD:
	case AArch64_INS_FTSMUL:
	case AArch64_INS_FTSSEL:
	case AArch64_INS_FVDOT:
	case AArch64_INS_LD1B:
	case AArch64_INS_LD1D:
	case AArch64_INS_LD1H:
	case AArch64_INS_LD1Q:
	case AArch64_INS_LD1SB:
	case AArch64_INS_LD1SH:
	case AArch64_INS_LD1SW:
	case AArch64_INS_LD1W:
	case AArch64_INS_LDFF1B:
	case AArch64_INS_LDFF1D:
	case AArch64_INS_LDFF1H:
	case AArch64_INS_LDFF1SB:
	case AArch64_INS_LDFF1SH:
	case AArch64_INS_LDFF1SW:
	case AArch64_INS_LDFF1W:
	case AArch64_INS_GMI:
	case AArch64_INS_HISTCNT:
	case AArch64_INS_HISTSEG:
	// case AArch64_INS_HLT:
	// case AArch64_INS_HVC:
	case AArch64_INS_INCB:
	case AArch64_INS_INCD:
	case AArch64_INS_INCH:
	case AArch64_INS_INCP:
	case AArch64_INS_INCW:
	case AArch64_INS_INDEX:
	case AArch64_INS_INSR:
	case AArch64_INS_INS:
	case AArch64_INS_IRG:
	// case AArch64_INS_ISB:
	case AArch64_INS_LASTA:
	case AArch64_INS_LASTB:
	case AArch64_INS_LD1:
	case AArch64_INS_LD1RB:
	case AArch64_INS_LD1RD:
	case AArch64_INS_LD1RH:
	case AArch64_INS_LD1ROB:
	case AArch64_INS_LD1ROD:
	case AArch64_INS_LD1ROH:
	case AArch64_INS_LD1ROW:
	case AArch64_INS_LD1RQB:
	case AArch64_INS_LD1RQD:
	case AArch64_INS_LD1RQH:
	case AArch64_INS_LD1RQW:
	case AArch64_INS_LD1RSB:
	case AArch64_INS_LD1RSH:
	case AArch64_INS_LD1RSW:
	case AArch64_INS_LD1RW:
	case AArch64_INS_LD1R:
	case AArch64_INS_LD2B:
	case AArch64_INS_LD2D:
	case AArch64_INS_LD2H:
	case AArch64_INS_LD2Q:
	case AArch64_INS_LD2R:
	case AArch64_INS_LD2:
	case AArch64_INS_LD2W:
	case AArch64_INS_LD3B:
	case AArch64_INS_LD3D:
	case AArch64_INS_LD3H:
	case AArch64_INS_LD3Q:
	case AArch64_INS_LD3R:
	case AArch64_INS_LD3:
	case AArch64_INS_LD3W:
	case AArch64_INS_LD4B:
	case AArch64_INS_LD4D:
	case AArch64_INS_LD4:
	case AArch64_INS_LD4H:
	case AArch64_INS_LD4Q:
	case AArch64_INS_LD4R:
	case AArch64_INS_LD4W:
	case AArch64_INS_LD64B:
	case AArch64_INS_LDADDAB:
	case AArch64_INS_LDADDAH:
	case AArch64_INS_LDADDALB:
	case AArch64_INS_LDADDALH:
	case AArch64_INS_LDADDAL:
	case AArch64_INS_LDADDA:
	case AArch64_INS_LDADDB:
	case AArch64_INS_LDADDH:
	case AArch64_INS_LDADDLB:
	case AArch64_INS_LDADDLH:
	case AArch64_INS_LDADDL:
	case AArch64_INS_LDADD:
	case AArch64_INS_LDAP1:
	case AArch64_INS_LDAPRB:
	case AArch64_INS_LDAPRH:
	case AArch64_INS_LDAPR:
	case AArch64_INS_LDAPURB:
	case AArch64_INS_LDAPURH:
	case AArch64_INS_LDAPURSB:
	case AArch64_INS_LDAPURSH:
	case AArch64_INS_LDAPURSW:
	case AArch64_INS_LDAPUR:
	case AArch64_INS_LDARB:
	case AArch64_INS_LDARH:
	case AArch64_INS_LDAR:
	case AArch64_INS_LDAXP:
	case AArch64_INS_LDAXRB:
	case AArch64_INS_LDAXRH:
	case AArch64_INS_LDAXR:
	case AArch64_INS_LDCLRAB:
	case AArch64_INS_LDCLRAH:
	case AArch64_INS_LDCLRALB:
	case AArch64_INS_LDCLRALH:
	case AArch64_INS_LDCLRAL:
	case AArch64_INS_LDCLRA:
	case AArch64_INS_LDCLRB:
	case AArch64_INS_LDCLRH:
	case AArch64_INS_LDCLRLB:
	case AArch64_INS_LDCLRLH:
	case AArch64_INS_LDCLRL:
	case AArch64_INS_LDCLRP:
	case AArch64_INS_LDCLRPA:
	case AArch64_INS_LDCLRPAL:
	case AArch64_INS_LDCLRPL:
	case AArch64_INS_LDCLR:
	case AArch64_INS_LDEORAB:
	case AArch64_INS_LDEORAH:
	case AArch64_INS_LDEORALB:
	case AArch64_INS_LDEORALH:
	case AArch64_INS_LDEORAL:
	case AArch64_INS_LDEORA:
	case AArch64_INS_LDEORB:
	case AArch64_INS_LDEORH:
	case AArch64_INS_LDEORLB:
	case AArch64_INS_LDEORLH:
	case AArch64_INS_LDEORL:
	case AArch64_INS_LDEOR:
	case AArch64_INS_LDG:
	case AArch64_INS_LDGM:
	case AArch64_INS_LDIAPP:
	case AArch64_INS_LDLARB:
	case AArch64_INS_LDLARH:
	case AArch64_INS_LDLAR:
	case AArch64_INS_LDNF1B:
	case AArch64_INS_LDNF1D:
	case AArch64_INS_LDNF1H:
	case AArch64_INS_LDNF1SB:
	case AArch64_INS_LDNF1SH:
	case AArch64_INS_LDNF1SW:
	case AArch64_INS_LDNF1W:
	case AArch64_INS_LDNP:
	case AArch64_INS_LDNT1B:
	case AArch64_INS_LDNT1D:
	case AArch64_INS_LDNT1H:
	case AArch64_INS_LDNT1SB:
	case AArch64_INS_LDNT1SH:
	case AArch64_INS_LDNT1SW:
	case AArch64_INS_LDNT1W:
	case AArch64_INS_LDP:
	case AArch64_INS_LDPSW:
	case AArch64_INS_LDRAA:
	case AArch64_INS_LDRAB:
	case AArch64_INS_LDRB:
	case AArch64_INS_LDR:
	case AArch64_INS_LDRH:
	case AArch64_INS_LDRSB:
	case AArch64_INS_LDRSH:
	case AArch64_INS_LDRSW:
	case AArch64_INS_LDSETAB:
	case AArch64_INS_LDSETAH:
	case AArch64_INS_LDSETALB:
	case AArch64_INS_LDSETALH:
	case AArch64_INS_LDSETAL:
	case AArch64_INS_LDSETA:
	case AArch64_INS_LDSETB:
	case AArch64_INS_LDSETH:
	case AArch64_INS_LDSETLB:
	case AArch64_INS_LDSETLH:
	case AArch64_INS_LDSETL:
	case AArch64_INS_LDSETP:
	case AArch64_INS_LDSETPA:
	case AArch64_INS_LDSETPAL:
	case AArch64_INS_LDSETPL:
	case AArch64_INS_LDSET:
	case AArch64_INS_LDSMAXAB:
	case AArch64_INS_LDSMAXAH:
	case AArch64_INS_LDSMAXALB:
	case AArch64_INS_LDSMAXALH:
	case AArch64_INS_LDSMAXAL:
	case AArch64_INS_LDSMAXA:
	case AArch64_INS_LDSMAXB:
	case AArch64_INS_LDSMAXH:
	case AArch64_INS_LDSMAXLB:
	case AArch64_INS_LDSMAXLH:
	case AArch64_INS_LDSMAXL:
	case AArch64_INS_LDSMAX:
	case AArch64_INS_LDSMINAB:
	case AArch64_INS_LDSMINAH:
	case AArch64_INS_LDSMINALB:
	case AArch64_INS_LDSMINALH:
	case AArch64_INS_LDSMINAL:
	case AArch64_INS_LDSMINA:
	case AArch64_INS_LDSMINB:
	case AArch64_INS_LDSMINH:
	case AArch64_INS_LDSMINLB:
	case AArch64_INS_LDSMINLH:
	case AArch64_INS_LDSMINL:
	case AArch64_INS_LDSMIN:
	case AArch64_INS_LDTRB:
	case AArch64_INS_LDTRH:
	case AArch64_INS_LDTRSB:
	case AArch64_INS_LDTRSH:
	case AArch64_INS_LDTRSW:
	case AArch64_INS_LDTR:
	case AArch64_INS_LDUMAXAB:
	case AArch64_INS_LDUMAXAH:
	case AArch64_INS_LDUMAXALB:
	case AArch64_INS_LDUMAXALH:
	case AArch64_INS_LDUMAXAL:
	case AArch64_INS_LDUMAXA:
	case AArch64_INS_LDUMAXB:
	case AArch64_INS_LDUMAXH:
	case AArch64_INS_LDUMAXLB:
	case AArch64_INS_LDUMAXLH:
	case AArch64_INS_LDUMAXL:
	case AArch64_INS_LDUMAX:
	case AArch64_INS_LDUMINAB:
	case AArch64_INS_LDUMINAH:
	case AArch64_INS_LDUMINALB:
	case AArch64_INS_LDUMINALH:
	case AArch64_INS_LDUMINAL:
	case AArch64_INS_LDUMINA:
	case AArch64_INS_LDUMINB:
	case AArch64_INS_LDUMINH:
	case AArch64_INS_LDUMINLB:
	case AArch64_INS_LDUMINLH:
	case AArch64_INS_LDUMINL:
	case AArch64_INS_LDUMIN:
	case AArch64_INS_LDURB:
	case AArch64_INS_LDUR:
	case AArch64_INS_LDURH:
	case AArch64_INS_LDURSB:
	case AArch64_INS_LDURSH:
	case AArch64_INS_LDURSW:
	case AArch64_INS_LDXP:
	case AArch64_INS_LDXRB:
	case AArch64_INS_LDXRH:
	case AArch64_INS_LDXR:
	case AArch64_INS_LSLR:
	case AArch64_INS_LSL:
	case AArch64_INS_LSRR:
	case AArch64_INS_LSR:
	case AArch64_INS_LUTI2:
	case AArch64_INS_LUTI4:
	case AArch64_INS_MADD:
	case AArch64_INS_MAD:
	case AArch64_INS_MATCH:
	case AArch64_INS_MLA:
	case AArch64_INS_MLS:
	case AArch64_INS_SETGE:
	case AArch64_INS_SETGEN:
	case AArch64_INS_SETGET:
	case AArch64_INS_SETGETN:
	case AArch64_INS_MOVAZ:
	case AArch64_INS_MOVI:
	case AArch64_INS_MOVK:
	case AArch64_INS_MOVN:
	case AArch64_INS_MOVPRFX:
	case AArch64_INS_MOVT:
	case AArch64_INS_MOVZ:
	// case AArch64_INS_MRRS:
	case AArch64_INS_MRS:
	case AArch64_INS_MSB:
	case AArch64_INS_MSR:
	// case AArch64_INS_MSRR:
	case AArch64_INS_MSUB:
	case AArch64_INS_MUL:
	case AArch64_INS_MVNI:
	case AArch64_INS_NANDS:
	case AArch64_INS_NAND:
	case AArch64_INS_NBSL:
	case AArch64_INS_NEG:
	case AArch64_INS_NMATCH:
	case AArch64_INS_NORS:
	case AArch64_INS_NOR:
	case AArch64_INS_NOT:
	case AArch64_INS_ORNS:
	case AArch64_INS_ORN:
	case AArch64_INS_ORQV:
	case AArch64_INS_ORRS:
	case AArch64_INS_ORR:
	case AArch64_INS_ORV:
	// case AArch64_INS_PACDA:
	// case AArch64_INS_PACDB:
	// case AArch64_INS_PACDZA:
	// case AArch64_INS_PACDZB:
	// case AArch64_INS_PACGA:
	// case AArch64_INS_PACIA:
	// case AArch64_INS_PACIB:
	// case AArch64_INS_PACIZA:
	// case AArch64_INS_PACIZB:
	case AArch64_INS_PEXT:
	case AArch64_INS_PFALSE:
	case AArch64_INS_PFIRST:
	case AArch64_INS_PMOV:
	case AArch64_INS_PMULLB:
	case AArch64_INS_PMULLT:
	case AArch64_INS_PMULL2:
	case AArch64_INS_PMULL:
	case AArch64_INS_PMUL:
	case AArch64_INS_PNEXT:
	// case AArch64_INS_PRFB:
	// case AArch64_INS_PRFD:
	// case AArch64_INS_PRFH:
	// case AArch64_INS_PRFM:
	// case AArch64_INS_PRFUM:
	// case AArch64_INS_PRFW:
	case AArch64_INS_PSEL:
	case AArch64_INS_PTEST:
	case AArch64_INS_PTRUES:
	case AArch64_INS_PTRUE:
	case AArch64_INS_PUNPKHI:
	case AArch64_INS_PUNPKLO:
	case AArch64_INS_RADDHNB:
	case AArch64_INS_RADDHNT:
	case AArch64_INS_RADDHN:
	case AArch64_INS_RADDHN2:
	case AArch64_INS_RAX1:
	case AArch64_INS_RBIT:
	case AArch64_INS_RCWCAS:
	case AArch64_INS_RCWCASA:
	case AArch64_INS_RCWCASAL:
	case AArch64_INS_RCWCASL:
	case AArch64_INS_RCWCASP:
	case AArch64_INS_RCWCASPA:
	case AArch64_INS_RCWCASPAL:
	case AArch64_INS_RCWCASPL:
	case AArch64_INS_RCWCLR:
	case AArch64_INS_RCWCLRA:
	case AArch64_INS_RCWCLRAL:
	case AArch64_INS_RCWCLRL:
	case AArch64_INS_RCWCLRP:
	case AArch64_INS_RCWCLRPA:
	case AArch64_INS_RCWCLRPAL:
	case AArch64_INS_RCWCLRPL:
	case AArch64_INS_RCWSCLR:
	case AArch64_INS_RCWSCLRA:
	case AArch64_INS_RCWSCLRAL:
	case AArch64_INS_RCWSCLRL:
	case AArch64_INS_RCWSCLRP:
	case AArch64_INS_RCWSCLRPA:
	case AArch64_INS_RCWSCLRPAL:
	case AArch64_INS_RCWSCLRPL:
	case AArch64_INS_RCWSCAS:
	case AArch64_INS_RCWSCASA:
	case AArch64_INS_RCWSCASAL:
	case AArch64_INS_RCWSCASL:
	case AArch64_INS_RCWSCASP:
	case AArch64_INS_RCWSCASPA:
	case AArch64_INS_RCWSCASPAL:
	case AArch64_INS_RCWSCASPL:
	case AArch64_INS_RCWSET:
	case AArch64_INS_RCWSETA:
	case AArch64_INS_RCWSETAL:
	case AArch64_INS_RCWSETL:
	case AArch64_INS_RCWSETP:
	case AArch64_INS_RCWSETPA:
	case AArch64_INS_RCWSETPAL:
	case AArch64_INS_RCWSETPL:
	case AArch64_INS_RCWSSET:
	case AArch64_INS_RCWSSETA:
	case AArch64_INS_RCWSSETAL:
	case AArch64_INS_RCWSSETL:
	case AArch64_INS_RCWSSETP:
	case AArch64_INS_RCWSSETPA:
	case AArch64_INS_RCWSSETPAL:
	case AArch64_INS_RCWSSETPL:
	case AArch64_INS_RCWSWP:
	case AArch64_INS_RCWSWPA:
	case AArch64_INS_RCWSWPAL:
	case AArch64_INS_RCWSWPL:
	case AArch64_INS_RCWSWPP:
	case AArch64_INS_RCWSWPPA:
	case AArch64_INS_RCWSWPPAL:
	case AArch64_INS_RCWSWPPL:
	case AArch64_INS_RCWSSWP:
	case AArch64_INS_RCWSSWPA:
	case AArch64_INS_RCWSSWPAL:
	case AArch64_INS_RCWSSWPL:
	case AArch64_INS_RCWSSWPP:
	case AArch64_INS_RCWSSWPPA:
	case AArch64_INS_RCWSSWPPAL:
	case AArch64_INS_RCWSSWPPL:
	case AArch64_INS_RDFFRS:
	case AArch64_INS_RDFFR:
	case AArch64_INS_RDSVL:
	case AArch64_INS_RDVL:
	case AArch64_INS_RET:
	case AArch64_INS_RETAA:
	case AArch64_INS_RETAB:
	case AArch64_INS_REV16:
	case AArch64_INS_REV32:
	case AArch64_INS_REV64:
	case AArch64_INS_REVB:
	case AArch64_INS_REVD:
	case AArch64_INS_REVH:
	case AArch64_INS_REVW:
	case AArch64_INS_REV:
	case AArch64_INS_RMIF:
	case AArch64_INS_ROR:
	// case AArch64_INS_RPRFM:
	case AArch64_INS_RSHRNB:
	case AArch64_INS_RSHRNT:
	case AArch64_INS_RSHRN2:
	case AArch64_INS_RSHRN:
	case AArch64_INS_RSUBHNB:
	case AArch64_INS_RSUBHNT:
	case AArch64_INS_RSUBHN:
	case AArch64_INS_RSUBHN2:
	case AArch64_INS_SABALB:
	case AArch64_INS_SABALT:
	case AArch64_INS_SABAL2:
	case AArch64_INS_SABAL:
	case AArch64_INS_SABA:
	case AArch64_INS_SABDLB:
	case AArch64_INS_SABDLT:
	case AArch64_INS_SABDL2:
	case AArch64_INS_SABDL:
	case AArch64_INS_SABD:
	case AArch64_INS_SADALP:
	case AArch64_INS_SADDLBT:
	case AArch64_INS_SADDLB:
	case AArch64_INS_SADDLP:
	case AArch64_INS_SADDLT:
	case AArch64_INS_SADDLV:
	case AArch64_INS_SADDL2:
	case AArch64_INS_SADDL:
	case AArch64_INS_SADDV:
	case AArch64_INS_SADDWB:
	case AArch64_INS_SADDWT:
	case AArch64_INS_SADDW2:
	case AArch64_INS_SADDW:
	case AArch64_INS_SB:
	case AArch64_INS_SBCLB:
	case AArch64_INS_SBCLT:
	case AArch64_INS_SBCS:
	case AArch64_INS_SBC:
	case AArch64_INS_SBFM:
	case AArch64_INS_SCLAMP:
	case AArch64_INS_SCVTF:
	case AArch64_INS_SDIVR:
	case AArch64_INS_SDIV:
	case AArch64_INS_SDOT:
	case AArch64_INS_SEL:
	case AArch64_INS_SETE:
	case AArch64_INS_SETEN:
	case AArch64_INS_SETET:
	case AArch64_INS_SETETN:
	case AArch64_INS_SETF16:
	case AArch64_INS_SETF8:
	case AArch64_INS_SETFFR:
	case AArch64_INS_SETGM:
	case AArch64_INS_SETGMN:
	case AArch64_INS_SETGMT:
	case AArch64_INS_SETGMTN:
	case AArch64_INS_SETGP:
	case AArch64_INS_SETGPN:
	case AArch64_INS_SETGPT:
	case AArch64_INS_SETGPTN:
	case AArch64_INS_SETM:
	case AArch64_INS_SETMN:
	case AArch64_INS_SETMT:
	case AArch64_INS_SETMTN:
	case AArch64_INS_SETP:
	case AArch64_INS_SETPN:
	case AArch64_INS_SETPT:
	case AArch64_INS_SETPTN:
	case AArch64_INS_SHA1C:
	case AArch64_INS_SHA1H:
	case AArch64_INS_SHA1M:
	case AArch64_INS_SHA1P:
	case AArch64_INS_SHA1SU0:
	case AArch64_INS_SHA1SU1:
	case AArch64_INS_SHA256H2:
	case AArch64_INS_SHA256H:
	case AArch64_INS_SHA256SU0:
	case AArch64_INS_SHA256SU1:
	case AArch64_INS_SHA512H:
	case AArch64_INS_SHA512H2:
	case AArch64_INS_SHA512SU0:
	case AArch64_INS_SHA512SU1:
	case AArch64_INS_SHADD:
	case AArch64_INS_SHLL2:
	case AArch64_INS_SHLL:
	case AArch64_INS_SHL:
	case AArch64_INS_SHRNB:
	case AArch64_INS_SHRNT:
	case AArch64_INS_SHRN2:
	case AArch64_INS_SHRN:
	case AArch64_INS_SHSUBR:
	case AArch64_INS_SHSUB:
	case AArch64_INS_SLI:
	case AArch64_INS_SM3PARTW1:
	case AArch64_INS_SM3PARTW2:
	case AArch64_INS_SM3SS1:
	case AArch64_INS_SM3TT1A:
	case AArch64_INS_SM3TT1B:
	case AArch64_INS_SM3TT2A:
	case AArch64_INS_SM3TT2B:
	case AArch64_INS_SM4E:
	case AArch64_INS_SM4EKEY:
	case AArch64_INS_SMADDL:
	case AArch64_INS_SMAXP:
	case AArch64_INS_SMAXQV:
	case AArch64_INS_SMAXV:
	case AArch64_INS_SMAX:
	// case AArch64_INS_SMC:
	case AArch64_INS_SMINP:
	case AArch64_INS_SMINQV:
	case AArch64_INS_SMINV:
	case AArch64_INS_SMIN:
	case AArch64_INS_SMLALB:
	case AArch64_INS_SMLALL:
	case AArch64_INS_SMLALT:
	case AArch64_INS_SMLAL:
	case AArch64_INS_SMLAL2:
	case AArch64_INS_SMLSLB:
	case AArch64_INS_SMLSLL:
	case AArch64_INS_SMLSLT:
	case AArch64_INS_SMLSL:
	case AArch64_INS_SMLSL2:
	case AArch64_INS_SMMLA:
	case AArch64_INS_SMOPA:
	case AArch64_INS_SMOPS:
	case AArch64_INS_SMOV:
	case AArch64_INS_SMSUBL:
	case AArch64_INS_SMULH:
	case AArch64_INS_SMULLB:
	case AArch64_INS_SMULLT:
	case AArch64_INS_SMULL2:
	case AArch64_INS_SMULL:
	case AArch64_INS_SPLICE:
	case AArch64_INS_SQABS:
	case AArch64_INS_SQADD:
	case AArch64_INS_SQCADD:
	case AArch64_INS_SQCVTN:
	case AArch64_INS_SQCVTUN:
	case AArch64_INS_SQCVTU:
	case AArch64_INS_SQCVT:
	case AArch64_INS_SQDECB:
	case AArch64_INS_SQDECD:
	case AArch64_INS_SQDECH:
	case AArch64_INS_SQDECP:
	case AArch64_INS_SQDECW:
	case AArch64_INS_SQDMLALBT:
	case AArch64_INS_SQDMLALB:
	case AArch64_INS_SQDMLALT:
	case AArch64_INS_SQDMLAL:
	case AArch64_INS_SQDMLAL2:
	case AArch64_INS_SQDMLSLBT:
	case AArch64_INS_SQDMLSLB:
	case AArch64_INS_SQDMLSLT:
	case AArch64_INS_SQDMLSL:
	case AArch64_INS_SQDMLSL2:
	case AArch64_INS_SQDMULH:
	case AArch64_INS_SQDMULLB:
	case AArch64_INS_SQDMULLT:
	case AArch64_INS_SQDMULL:
	case AArch64_INS_SQDMULL2:
	case AArch64_INS_SQINCB:
	case AArch64_INS_SQINCD:
	case AArch64_INS_SQINCH:
	case AArch64_INS_SQINCP:
	case AArch64_INS_SQINCW:
	case AArch64_INS_SQNEG:
	case AArch64_INS_SQRDCMLAH:
	case AArch64_INS_SQRDMLAH:
	case AArch64_INS_SQRDMLSH:
	case AArch64_INS_SQRDMULH:
	case AArch64_INS_SQRSHLR:
	case AArch64_INS_SQRSHL:
	case AArch64_INS_SQRSHRNB:
	case AArch64_INS_SQRSHRNT:
	case AArch64_INS_SQRSHRN:
	case AArch64_INS_SQRSHRN2:
	case AArch64_INS_SQRSHRUNB:
	case AArch64_INS_SQRSHRUNT:
	case AArch64_INS_SQRSHRUN:
	case AArch64_INS_SQRSHRUN2:
	case AArch64_INS_SQRSHRU:
	case AArch64_INS_SQRSHR:
	case AArch64_INS_SQSHLR:
	case AArch64_INS_SQSHLU:
	case AArch64_INS_SQSHL:
	case AArch64_INS_SQSHRNB:
	case AArch64_INS_SQSHRNT:
	case AArch64_INS_SQSHRN:
	case AArch64_INS_SQSHRN2:
	case AArch64_INS_SQSHRUNB:
	case AArch64_INS_SQSHRUNT:
	case AArch64_INS_SQSHRUN:
	case AArch64_INS_SQSHRUN2:
	case AArch64_INS_SQSUBR:
	case AArch64_INS_SQSUB:
	case AArch64_INS_SQXTNB:
	case AArch64_INS_SQXTNT:
	case AArch64_INS_SQXTN2:
	case AArch64_INS_SQXTN:
	case AArch64_INS_SQXTUNB:
	case AArch64_INS_SQXTUNT:
	case AArch64_INS_SQXTUN2:
	case AArch64_INS_SQXTUN:
	case AArch64_INS_SRHADD:
	case AArch64_INS_SRI:
	case AArch64_INS_SRSHLR:
	case AArch64_INS_SRSHL:
	case AArch64_INS_SRSHR:
	case AArch64_INS_SRSRA:
	case AArch64_INS_SSHLLB:
	case AArch64_INS_SSHLLT:
	case AArch64_INS_SSHLL2:
	case AArch64_INS_SSHLL:
	case AArch64_INS_SSHL:
	case AArch64_INS_SSHR:
	case AArch64_INS_SSRA:
	case AArch64_INS_ST1B:
	case AArch64_INS_ST1D:
	case AArch64_INS_ST1H:
	case AArch64_INS_ST1Q:
	case AArch64_INS_ST1W:
	case AArch64_INS_SSUBLBT:
	case AArch64_INS_SSUBLB:
	case AArch64_INS_SSUBLTB:
	case AArch64_INS_SSUBLT:
	case AArch64_INS_SSUBL2:
	case AArch64_INS_SSUBL:
	case AArch64_INS_SSUBWB:
	case AArch64_INS_SSUBWT:
	case AArch64_INS_SSUBW2:
	case AArch64_INS_SSUBW:
	case AArch64_INS_ST1:
	case AArch64_INS_ST2B:
	case AArch64_INS_ST2D:
	case AArch64_INS_ST2G:
	case AArch64_INS_ST2H:
	case AArch64_INS_ST2Q:
	case AArch64_INS_ST2:
	case AArch64_INS_ST2W:
	case AArch64_INS_ST3B:
	case AArch64_INS_ST3D:
	case AArch64_INS_ST3H:
	case AArch64_INS_ST3Q:
	case AArch64_INS_ST3:
	case AArch64_INS_ST3W:
	case AArch64_INS_ST4B:
	case AArch64_INS_ST4D:
	case AArch64_INS_ST4:
	case AArch64_INS_ST4H:
	case AArch64_INS_ST4Q:
	case AArch64_INS_ST4W:
	case AArch64_INS_ST64B:
	case AArch64_INS_ST64BV:
	case AArch64_INS_ST64BV0:
	case AArch64_INS_STGM:
	case AArch64_INS_STG:
	case AArch64_INS_STGP:
	case AArch64_INS_STILP:
	case AArch64_INS_STL1:
	case AArch64_INS_STLLRB:
	case AArch64_INS_STLLRH:
	case AArch64_INS_STLLR:
	case AArch64_INS_STLRB:
	case AArch64_INS_STLRH:
	case AArch64_INS_STLR:
	case AArch64_INS_STLURB:
	case AArch64_INS_STLURH:
	case AArch64_INS_STLUR:
	case AArch64_INS_STLXP:
	case AArch64_INS_STLXRB:
	case AArch64_INS_STLXRH:
	case AArch64_INS_STLXR:
	case AArch64_INS_STNP:
	case AArch64_INS_STNT1B:
	case AArch64_INS_STNT1D:
	case AArch64_INS_STNT1H:
	case AArch64_INS_STNT1W:
	case AArch64_INS_STP:
	case AArch64_INS_STRB:
	case AArch64_INS_STR:
	case AArch64_INS_STRH:
	case AArch64_INS_STTRB:
	case AArch64_INS_STTRH:
	case AArch64_INS_STTR:
	case AArch64_INS_STURB:
	case AArch64_INS_STUR:
	case AArch64_INS_STURH:
	case AArch64_INS_STXP:
	case AArch64_INS_STXRB:
	case AArch64_INS_STXRH:
	case AArch64_INS_STXR:
	case AArch64_INS_STZ2G:
	case AArch64_INS_STZGM:
	case AArch64_INS_STZG:
	case AArch64_INS_SUBG:
	case AArch64_INS_SUBHNB:
	case AArch64_INS_SUBHNT:
	case AArch64_INS_SUBHN:
	case AArch64_INS_SUBHN2:
	case AArch64_INS_SUBP:
	case AArch64_INS_SUBPS:
	case AArch64_INS_SUBR:
	case AArch64_INS_SUBS:
	case AArch64_INS_SUB:
	case AArch64_INS_SUDOT:
	case AArch64_INS_SUMLALL:
	case AArch64_INS_SUMOPA:
	case AArch64_INS_SUMOPS:
	case AArch64_INS_SUNPKHI:
	case AArch64_INS_SUNPKLO:
	case AArch64_INS_SUNPK:
	case AArch64_INS_SUQADD:
	case AArch64_INS_SUVDOT:
	// case AArch64_INS_SVC:
	case AArch64_INS_SVDOT:
	case AArch64_INS_SWPAB:
	case AArch64_INS_SWPAH:
	case AArch64_INS_SWPALB:
	case AArch64_INS_SWPALH:
	case AArch64_INS_SWPAL:
	case AArch64_INS_SWPA:
	case AArch64_INS_SWPB:
	case AArch64_INS_SWPH:
	case AArch64_INS_SWPLB:
	case AArch64_INS_SWPLH:
	case AArch64_INS_SWPL:
	case AArch64_INS_SWPP:
	case AArch64_INS_SWPPA:
	case AArch64_INS_SWPPAL:
	case AArch64_INS_SWPPL:
	case AArch64_INS_SWP:
	case AArch64_INS_SXTB:
	case AArch64_INS_SXTH:
	case AArch64_INS_SXTW:
	// case AArch64_INS_SYSL:
	// case AArch64_INS_SYSP:
	// case AArch64_INS_SYS:
	case AArch64_INS_TBLQ:
	case AArch64_INS_TBL:
	case AArch64_INS_TBNZ:
	case AArch64_INS_TBXQ:
	case AArch64_INS_TBX:
	case AArch64_INS_TBZ:
	case AArch64_INS_TCANCEL:
	case AArch64_INS_TCOMMIT:
	case AArch64_INS_TRCIT:
	case AArch64_INS_TRN1:
	case AArch64_INS_TRN2:
	case AArch64_INS_TSB:
	case AArch64_INS_TSTART:
	case AArch64_INS_TTEST:
	case AArch64_INS_UABALB:
	case AArch64_INS_UABALT:
	case AArch64_INS_UABAL2:
	case AArch64_INS_UABAL:
	case AArch64_INS_UABA:
	case AArch64_INS_UABDLB:
	case AArch64_INS_UABDLT:
	case AArch64_INS_UABDL2:
	case AArch64_INS_UABDL:
	case AArch64_INS_UABD:
	case AArch64_INS_UADALP:
	case AArch64_INS_UADDLB:
	case AArch64_INS_UADDLP:
	case AArch64_INS_UADDLT:
	case AArch64_INS_UADDLV:
	case AArch64_INS_UADDL2:
	case AArch64_INS_UADDL:
	case AArch64_INS_UADDV:
	case AArch64_INS_UADDWB:
	case AArch64_INS_UADDWT:
	case AArch64_INS_UADDW2:
	case AArch64_INS_UADDW:
	case AArch64_INS_UBFM:
	case AArch64_INS_UCLAMP:
	case AArch64_INS_UCVTF:
	case AArch64_INS_UDF:
	case AArch64_INS_UDIVR:
	case AArch64_INS_UDIV:
	case AArch64_INS_UDOT:
	case AArch64_INS_UHADD:
	case AArch64_INS_UHSUBR:
	case AArch64_INS_UHSUB:
	case AArch64_INS_UMADDL:
	case AArch64_INS_UMAXP:
	case AArch64_INS_UMAXQV:
	case AArch64_INS_UMAXV:
	case AArch64_INS_UMAX:
	case AArch64_INS_UMINP:
	case AArch64_INS_UMINQV:
	case AArch64_INS_UMINV:
	case AArch64_INS_UMIN:
	case AArch64_INS_UMLALB:
	case AArch64_INS_UMLALL:
	case AArch64_INS_UMLALT:
	case AArch64_INS_UMLAL:
	case AArch64_INS_UMLAL2:
	case AArch64_INS_UMLSLB:
	case AArch64_INS_UMLSLL:
	case AArch64_INS_UMLSLT:
	case AArch64_INS_UMLSL:
	case AArch64_INS_UMLSL2:
	case AArch64_INS_UMMLA:
	case AArch64_INS_UMOPA:
	case AArch64_INS_UMOPS:
	case AArch64_INS_UMOV:
	case AArch64_INS_UMSUBL:
	case AArch64_INS_UMULH:
	case AArch64_INS_UMULLB:
	case AArch64_INS_UMULLT:
	case AArch64_INS_UMULL2:
	case AArch64_INS_UMULL:
	case AArch64_INS_UQADD:
	case AArch64_INS_UQCVTN:
	case AArch64_INS_UQCVT:
	case AArch64_INS_UQDECB:
	case AArch64_INS_UQDECD:
	case AArch64_INS_UQDECH:
	case AArch64_INS_UQDECP:
	case AArch64_INS_UQDECW:
	case AArch64_INS_UQINCB:
	case AArch64_INS_UQINCD:
	case AArch64_INS_UQINCH:
	case AArch64_INS_UQINCP:
	case AArch64_INS_UQINCW:
	case AArch64_INS_UQRSHLR:
	case AArch64_INS_UQRSHL:
	case AArch64_INS_UQRSHRNB:
	case AArch64_INS_UQRSHRNT:
	case AArch64_INS_UQRSHRN:
	case AArch64_INS_UQRSHRN2:
	case AArch64_INS_UQRSHR:
	case AArch64_INS_UQSHLR:
	case AArch64_INS_UQSHL:
	case AArch64_INS_UQSHRNB:
	case AArch64_INS_UQSHRNT:
	case AArch64_INS_UQSHRN:
	case AArch64_INS_UQSHRN2:
	case AArch64_INS_UQSUBR:
	case AArch64_INS_UQSUB:
	case AArch64_INS_UQXTNB:
	case AArch64_INS_UQXTNT:
	case AArch64_INS_UQXTN2:
	case AArch64_INS_UQXTN:
	case AArch64_INS_URECPE:
	case AArch64_INS_URHADD:
	case AArch64_INS_URSHLR:
	case AArch64_INS_URSHL:
	case AArch64_INS_URSHR:
	case AArch64_INS_URSQRTE:
	case AArch64_INS_URSRA:
	case AArch64_INS_USDOT:
	case AArch64_INS_USHLLB:
	case AArch64_INS_USHLLT:
	case AArch64_INS_USHLL2:
	case AArch64_INS_USHLL:
	case AArch64_INS_USHL:
	case AArch64_INS_USHR:
	case AArch64_INS_USMLALL:
	case AArch64_INS_USMMLA:
	case AArch64_INS_USMOPA:
	case AArch64_INS_USMOPS:
	case AArch64_INS_USQADD:
	case AArch64_INS_USRA:
	case AArch64_INS_USUBLB:
	case AArch64_INS_USUBLT:
	case AArch64_INS_USUBL2:
	case AArch64_INS_USUBL:
	case AArch64_INS_USUBWB:
	case AArch64_INS_USUBWT:
	case AArch64_INS_USUBW2:
	case AArch64_INS_USUBW:
	case AArch64_INS_USVDOT:
	case AArch64_INS_UUNPKHI:
	case AArch64_INS_UUNPKLO:
	case AArch64_INS_UUNPK:
	case AArch64_INS_UVDOT:
	case AArch64_INS_UXTB:
	case AArch64_INS_UXTH:
	case AArch64_INS_UXTW:
	case AArch64_INS_UZP1:
	case AArch64_INS_UZP2:
	case AArch64_INS_UZPQ1:
	case AArch64_INS_UZPQ2:
	case AArch64_INS_UZP:
	// case AArch64_INS_WFET:
	// case AArch64_INS_WFIT:
	// case AArch64_INS_WHILEGE:
	// case AArch64_INS_WHILEGT:
	// case AArch64_INS_WHILEHI:
	// case AArch64_INS_WHILEHS:
	// case AArch64_INS_WHILELE:
	// case AArch64_INS_WHILELO:
	// case AArch64_INS_WHILELS:
	// case AArch64_INS_WHILELT:
	// case AArch64_INS_WHILERW:
	// case AArch64_INS_WHILEWR:
	case AArch64_INS_WRFFR:
	case AArch64_INS_XAFLAG:
	case AArch64_INS_XAR:
	case AArch64_INS_XPACD:
	case AArch64_INS_XPACI:
	case AArch64_INS_XTN2:
	case AArch64_INS_XTN:
	case AArch64_INS_ZERO:
	case AArch64_INS_ZIP1:
	case AArch64_INS_ZIP2:
	case AArch64_INS_ZIPQ1:
	case AArch64_INS_ZIPQ2:
	case AArch64_INS_ZIP:
    // case AArch64_INS_ALIAS_CFP:
    // case AArch64_INS_ALIAS_DVP:
    // case AArch64_INS_ALIAS_COSP:
    // case AArch64_INS_ALIAS_CPP:
    // case AArch64_INS_ALIAS_IC:
    // case AArch64_INS_ALIAS_DC:
    // case AArch64_INS_ALIAS_AT:
    // case AArch64_INS_ALIAS_TLBI:
    // case AArch64_INS_ALIAS_TLBIP:
    // case AArch64_INS_ALIAS_RPRFM:
    // case AArch64_INS_ALIAS_LSL:
    // case AArch64_INS_ALIAS_SBFX:
    // case AArch64_INS_ALIAS_UBFX:
    // case AArch64_INS_ALIAS_SBFIZ:
    // case AArch64_INS_ALIAS_UBFIZ:
    // case AArch64_INS_ALIAS_BFC:
    // case AArch64_INS_ALIAS_BFI:
    // case AArch64_INS_ALIAS_BFXIL:
        return true;
    default:
        return false;
    }
}
