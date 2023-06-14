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

func mustResReg(reg arm.Reg, inst Inst) {
	if reg != resReg {
		fail(inst, fmt.Sprintf("must use reserved register %s", resReg))
	}
}

func mustRetReg(reg arm.Reg, inst Inst) {
	if reg != retReg {
		fail(inst, fmt.Sprintf("must use reserved return register %s", retReg))
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

func must(b bool, inst Inst, msg string) bool {
	if !b {
		fail(inst, msg)
		return false
	}
	return true
}

func checkMov(inst Inst, dest, src arm.Reg) {
	if !must(inst.Op == arm.MOV, inst, "op must be mov") {
		return
	}
	must(inst.Args[0].(arm.RegSP) == arm.RegSP(dest), inst, fmt.Sprintf("dest must be %s", dest))
	must(inst.Args[1].(arm.RegSP) == arm.RegSP(src), inst, fmt.Sprintf("src must be %s", src))
}

func checkAddUxtw(inst Inst, target arm.Reg, src arm.Reg, checksrc bool) {
	if !must(inst.Op == arm.ADD, inst, fmt.Sprintf("must be add uxtw, but got %s", inst.Op)) {
		return
	}
	must(inst.Args[1].(arm.RegSP) == arm.RegSP(segmentReg), inst, "second argument must be segment reg")
	if r, ok := inst.Args[2].(arm.RegExtshiftAmount); !ok {
		fail(inst, "third argument must use uxtw")
	} else {
		must(r.ExtShift == arm.Uxtw, inst, "third argument must use uxtw")
		must(r.Amount == 0, inst, "uxtw must not have a shift immediate")
		must(loRegs[r.Reg], inst, "third argument must be W-register")
		if checksrc {
			must(r.Reg == src, inst, fmt.Sprintf("third argument must be %s", src))
		}
	}
}

func checkMem(mem arm.Arg, inst Inst, prevInst *Inst) {
	switch arg := mem.(type) {
	case arm.MemImmediate:
		if arg.Mode == arm.AddrPostReg {
			fail(inst, "cannot use post register addressing mode")
		}
		if !dataRegs[arm.Reg(arg.Base)] {
			// must be a data register
			fail(inst, fmt.Sprintf("must use data register (sp or %s) for memory access", resReg))
		}
	case arm.MemExtend:
		fail(inst, "cannot use extended addressing mode")
	}
}

func checkModReg(inst Inst, insts []Inst, i int, modReg arm.Reg, couldSp bool) {
	var next1, next2 *Inst
	if i+1 < len(insts) {
		next1 = &insts[i+1]
	}
	if i+2 < len(insts) {
		next2 = &insts[i+2]
	}
	if restrictedRegs[modReg] {
		if modReg == segmentReg {
			// it is never valid to modify the segment ID register
			fail(inst, "modifying the segment ID register is disallowed")
		} else if couldSp && modReg == arm.SP {
			if inst.Op == arm.ADD && inst.Args[1].(arm.RegSP) == arm.RegSP(segmentReg) {
				if r, ok := inst.Args[2].(arm.RegExtshiftAmount); ok {
					if r.ExtShift == arm.Uxtw && r.Reg == loResReg {
						return
					}
				}
			}

			// next two instructions must be
			// mov loResReg, wsp
			// add sp, segmentReg, loResReg, uxtw
			if next1 == nil || next2 == nil {
				fail(inst, "must be followed by guards")
			} else {
				checkMov(*next1, loResReg, arm.WSP)
				checkAddUxtw(*next2, arm.SP, loResReg, true)
			}
			return
		} else if inst.Op == arm.ADD {
			// must be 'add restricted, segmentReg, loReg, uxtw'
			var r arm.Reg
			checkAddUxtw(inst, modReg, r, false)
			return
		} else if modReg == loResReg {
			// mov resReg, wsp is allowed
			checkMov(inst, loResReg, arm.WSP)
			if inst.Op == arm.MOV && inst.Args[1].(arm.RegSP) == arm.RegSP(arm.WSP) {
				return
			}
			fail(inst, "modifying restricted register without appropriate guards")
		} else if modReg == retReg {
			// must be followed by
			// add retReg, segmentReg, loRetReg, uxtw
			if next1 == nil {
				fail(inst, "must be followed by guard instruction")
			} else {
				checkAddUxtw(*next1, retReg, loRetReg, true)
			}
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

	for i := 0; i < len(insts); i++ {
		inst := insts[i]
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
		// * make sure BLR/BR use the reserved reg
		// * make sure loads/stores use the reserved reg
		// * make sure loads/stores do not use fancy addressing modes
		switch inst.Op {
		case arm.BLR:
			mustResReg(inst.Args[0].(arm.Reg), inst)
		case arm.BR:
			mustResReg(inst.Args[0].(arm.Reg), inst)
		case arm.RET:
			mustRetReg(inst.Args[0].(arm.Reg), inst)
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
			// stores cannot modify restricted registers in bad ways
			// branches do not modify their operands
			continue
		}

		// make sure instructions do not modify reserved registers in bad ways
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
