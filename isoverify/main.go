package main

import (
	"flag"
	"fmt"
	"log"
	"os"

	arm "github.com/zyedidia/isolator/arm64/arm64asm"
)

type Inst struct {
	arm.Inst

	Addr int64
}

var failed = false

func fail(i Inst, msg string) {
	fmt.Fprintf(os.Stderr, "error at 0x%x: '%s': %s\n", i.Addr, i.String(), msg)
	failed = true
}

func mustBranchReg(reg arm.Reg, inst Inst) {
	if reg != branchReg {
		fail(inst, fmt.Sprintf("must use reserved branch register %s", branchReg))
	}
}

func mustRetReg(reg arm.Reg, inst Inst) {
	if reg != retReg {
		fail(inst, fmt.Sprintf("must use reserved return register %s", branchReg))
	}
}

func mustAligned(loc int64, align int64, inst Inst) {
	if loc%align != 0 {
		fail(inst, fmt.Sprintf("address must be aligned to %d", align))
	}
}

func mustNotAligned(loc int64, align int64, inst Inst) {
	if loc%align == 0 {
		fail(inst, fmt.Sprintf("address must not be aligned to %d", align))
	}
}

func mustArgs(n int, inst Inst) {
	nargs := 0
	for _, a := range inst.Args {
		if a != nil {
			nargs++
		}
	}
	if nargs != n {
		fail(inst, fmt.Sprintf("incorrect number of arguments, got %d, expected %d", nargs, n))
	}
}

func must(b bool, inst Inst, msg string) {
	if !b {
		fail(inst, msg)
	}
}

func checkMov(mov Inst, target arm.RegSP, src arm.RegSP, inst Inst) {
	// check for 'mov target, src'
	must(mov.Op == arm.MOV, inst, "must be a mov")
	if mov.Op != arm.MOV {
		return
	}
	must(mov.Args[0].(arm.RegSP) == target, inst, fmt.Sprintf("associated mov must store to %s", target))
	must(mov.Args[1].(arm.RegSP) == src, inst, fmt.Sprintf("associated mov must read from %s", src))
}

func checkBic(bic Inst, target arm.Reg, src arm.Reg, inst Inst) {
	// check for 'bic target, src, bundleMask'
	must(bic.Op == arm.AND, inst, fmt.Sprintf("must be a bic, but got %s", bic.Op))
	if bic.Op != arm.AND {
		return
	}
	must(bic.Args[0].(arm.RegSP) == arm.RegSP(target), inst, "associated bic must store to target register")
	must(bic.Args[1].(arm.Reg) == src, inst, "associated bic must read from source register")
	must(bic.Args[2].(arm.Imm64).Imm == ^bundleMask, inst, fmt.Sprintf("control reg mask must be %x", ^bundleMask))
}

func checkMovk(movk Inst, target arm.Reg, inst Inst) {
	// check for correct movk (movk reg, segmentId, lsl #32)
	must(movk.Op == arm.MOVK, movk, "must be a movk")
	if movk.Op != arm.MOVK {
		return
	}
	must(movk.Args[0].(arm.Reg) == target, inst, "associated movk must store to target register")
	immsh := movk.Args[1].(arm.ImmShift)
	must(immsh.Imm == segmentId, inst, fmt.Sprintf("associated movk must move segment ID (%x)", segmentId))
	must(immsh.Shift == 32, inst, "associated movk must shift by 32")
}

func checkMem(mem arm.Arg, inst Inst, prevInst *Inst) {
	switch arg := mem.(type) {
	case arm.MemImmediate:
		if arg.Mode == arm.AddrPostReg {
			fail(inst, "cannot use post register addressing mode")
		}
		if !dataRegs[arm.Reg(arg.Base)] {
			// cannot be a ctrlReg
			if ctrlRegs[arm.Reg(arg.Base)] {
				fail(inst, "cannot use a reserved control register for memory operation")
			}
			// needs movk and cannot be 8-aligned
			mustNotAligned(inst.Addr, 8, inst)
			if prevInst != nil && prevInst.Op == arm.MOVK {
				checkMovk(*prevInst, arm.Reg(arg.Base), inst)
			} else {
				fail(inst, "load of user reg requires preceding movk")
			}
		}
	case arm.MemExtend:
		fail(inst, "cannot use extended addressing mode")
	}
}

func checkModReg(inst Inst, insts []Inst, i int, modReg arm.Reg, couldSp bool) {
	if restrictedRegs[modReg] {
		var nextInst *Inst
		if i+1 < len(insts) {
			nextInst = &insts[i+1]
			for j := i + 2; j < len(insts) && nextInst.Op == arm.NOP; j++ {
				nextInst = &insts[j]
			}
		}
		// TODO: check that the sp modification sequence is complete
		if nextInst != nil && modReg == branchReg {
			if inst.Op == arm.AND {
				// must be 'bic modReg, Xn, bundleMask'
				// and must be followed by movk/nop movk
				checkBic(inst, branchReg, inst.Args[1].(arm.Reg), inst)
				checkMovk(*nextInst, branchReg, inst)
				return
			}
		}
		if nextInst != nil && modReg == retReg {
			if inst.Op == arm.AND {
				checkBic(inst, retReg, retReg, inst)
			} else if inst.Op == arm.MOVK {
				// must be followed by 'bic retReg, retReg, bundleMask'
				checkBic(*nextInst, retReg, retReg, inst)
			} else {
				// must be followed by 'movk retReg, segmentId, lsl #32'
				checkMovk(*nextInst, retReg, inst)
			}
			return
		}
		if couldSp && modReg == arm.SP {
			// must be 'mov sp, resReg' or be followed by 'mov resReg, sp'
			if inst.Op == arm.MOV {
				checkMov(inst, arm.RegSP(arm.SP), arm.RegSP(resReg), inst)
			} else if nextInst != nil && nextInst.Op == arm.MOV {
				checkMov(*nextInst, arm.RegSP(resReg), arm.RegSP(arm.SP), inst)
			} else {
				fail(inst, "modification to SP is not guarded")
			}
			return
		}
		if inst.Op == arm.MOVK {
			checkMovk(inst, modReg, inst)
			return
		}
		if nextInst != nil && modReg == resReg {
			// must be followed by movk
			checkMovk(*nextInst, resReg, inst)
			return
		}

		fail(inst, fmt.Sprintf("modifying special register %s without appropriate guards", arm.RegSP(modReg)))
	}
}

func main() {
	flag.Parse()
	args := flag.Args()

	if len(args) < 1 {
		log.Fatal("no input")
	}

	target := args[0]

	data, err := os.ReadFile(target)
	if err != nil {
		log.Fatal(err)
	}

	addr := int64(0)

	var insts []Inst

	for len(data) > 0 {
		inst, err := arm.Decode(data)
		if err != nil {
			fmt.Printf("unknown instruction at %x\n", addr)
			failed = true
		} else {
			insts = append(insts, Inst{
				Inst: inst,
				Addr: addr,
			})
		}

		addr += 4
		data = data[4:]
	}

	for i, inst := range insts {
		if !allowed[inst.Op] {
			fail(inst, "instruction disallowed")
			continue
		}
		var prevInst *Inst
		if i == 0 {
			prevInst = nil
		} else {
			prevInst = &insts[i-1]
		}
		// * make sure BLR and BL have aligned return addresses
		// * make sure BLR/BR use the branch reg
		// * make sure loads/stores either use the dedicated reg, or have a
		//   movk immediately before (if they use a user reg, make sure the access
		//   is aligned properly)
		// * make sure loads/stores do not use fancy addressing modes
		switch inst.Op {
		case arm.BLR:
			mustBranchReg(inst.Args[0].(arm.Reg), inst)
			mustAligned(inst.Addr+4, 8, inst)
		case arm.BR:
			mustBranchReg(inst.Args[0].(arm.Reg), inst)
		case arm.RET:
			mustRetReg(inst.Args[0].(arm.Reg), inst)
		case arm.BL:
			mustAligned(inst.Addr+4, 8, inst)
		case arm.LDR, arm.LDRB, arm.LDRH, arm.LDRSB, arm.LDRSH, arm.LDRSW,
			arm.LDUR, arm.LDURB, arm.LDURH, arm.LDURSH, arm.LDURSW, arm.STR,
			arm.STRB, arm.STRH, arm.STUR, arm.STURB, arm.STURH:
			mustArgs(2, inst)
			checkMem(inst.Args[1], inst, prevInst)
		case arm.LDP, arm.LDPSW, arm.STP:
			mustArgs(3, inst)
			checkMem(inst.Args[2], inst, prevInst)
		}

		if stores[inst.Op] || branches[inst.Op] || nomodify[inst.Op] {
			// stores cannot modify restricted registers in bad ways (we
			// already check if they modify ctrlRegs)
			// branches do not modify their operands
			continue
		}

		var modReg arm.Reg
		couldSp := false
		switch r := inst.Args[0].(type) {
		case arm.Reg:
			modReg = r
		case arm.RegSP:
			modReg = arm.Reg(r)
			couldSp = true
		default:
			fail(inst, "first arg was not a register")
		}

		checkModReg(inst, insts, i, modReg, couldSp)

		if inst.Op == arm.LDP || inst.Op == arm.LDPSW {
			modReg = inst.Args[1].(arm.Reg)
			checkModReg(inst, insts, i, modReg, false)
		}
	}

	if failed {
		fmt.Fprintln(os.Stderr, "verification failed")
		os.Exit(1)
	}
}
