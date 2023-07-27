package main

import (
	"debug/elf"
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

func isReg(a arm.Arg, reg arm.Reg) bool {
	if r, ok := a.(arm.Reg); ok {
		return r == reg
	}
	return false
}

func isSystemReg(a arm.Arg, reg arm.Systemreg) bool {
	if r, ok := a.(arm.Systemreg); ok {
		return r == reg
	}
	return false
}

func isZero(arr []byte) bool {
	for _, b := range arr {
		if b != 0 {
			return false
		}
	}
	return true
}

func checkMem(mem arm.Arg, inst Inst) {
	switch arg := mem.(type) {
	case arm.MemImmediate:
		if arg.Base == arm.RegSP(segmentReg) && arg.Imm == 0 {
			return
		}
		if !dataRegs[arm.Reg(arg.Base)] {
			fail(inst, "must use reserved data register for memory access")
		}
	case arm.MemExtend:
		if arg.Base != arm.RegSP(segmentReg) {
			if dataRegs[arm.Reg(arg.Base)] && arg.Base != arm.RegSP(arm.SP) {
				if arg.Amount == 0 && loRegs[arg.Index] && (arg.Extend == arm.Uxtw || arg.Extend == arm.Sxtw) {
					return
				}
			}

			fail(inst, "base reg must be segment reg")
			return
		}
		if !loRegs[arg.Index] {
			fail(inst, "index reg must be 32-bit")
			return
		}
		if arg.Extend != arm.Uxtw || arg.Amount != 0 {
			fail(inst, "extend must be uxtw #0")
			return
		}
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

func checkModReg(inst Inst, insts []Inst, i int, modReg arm.Reg, sp bool) {
	if fixedRegs[modReg] {
		fail(inst, "modifying fixed register")
	}
	var next1, next2 *Inst
	if i+1 < len(insts) {
		next1 = &insts[i+1]
	}
	if i+2 < len(insts) {
		next2 = &insts[i+2]
	}
	if restrictedRegs[modReg] {
		if !sp && (modReg == arm.XZR || modReg == arm.WZR) {
			return
		} else if sp && modReg == arm.SP {
			// allow 'add sp, segmentReg, loResReg, uxtw' (required during guard sequence)
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
			// mov loResReg, wsp is allowed
			checkMov(inst, loResReg, arm.WSP)
			if inst.Op == arm.MOV && inst.Args[1].(arm.RegSP) == arm.RegSP(arm.WSP) {
				return
			}
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
		fail(inst, "modifying restricted register without guards")
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

func main() {
	flag.Parse()
	args := flag.Args()

	if len(args) < 1 {
		log.Fatal("no input")
	}

	target := args[0]

	f, err := os.Open(target)
	if err != nil {
		log.Fatal(err)
	}

	e, err := elf.NewFile(f)
	if err != nil {
		log.Fatal(err)
	}

	var insts []Inst

	for _, p := range e.Progs {
		if p.Type != elf.PT_LOAD || (p.Flags&elf.PF_X == 0) {
			continue
		}
		data := make([]byte, p.Filesz)
		_, err := p.ReadAt(data, 0)
		if err != nil {
			log.Fatal(err)
		}
		addr := p.Vaddr
		for len(data) > 0 {
			if !isZero(data[:4]) {
				inst, err := arm.Decode(data)
				if err != nil {
					fmt.Printf("unknown instruction at %x: %v, %s\n", addr, data[:4], err)
					failed = true
				} else {
					insts = append(insts, Inst{
						Inst: inst,
						Addr: int64(addr),
					})
				}
				// fmt.Printf("%x: %s\n", addr, arm.GNUSyntax(inst))
			}
			addr += 4
			data = data[4:]
		}
	}

	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		if !allowed[inst.Op] {
			fail(inst, "instruction disallowed")
			continue
		}

		// * BLR/BR must use resReg or retReg
		// * RET must use retReg
		// * loads/stores must use data reg, or used masking address mode
		// * fixed registers cannot be modified
		// * reserved registers cannot be modified without masks
		switch inst.Op {
		case arm.MSR:
			if r, ok := inst.Args[0].(arm.Systemreg); !ok || !legalSysRegs[r] {
				fail(inst, "attempt to access illegal system reg")
			}
		case arm.MRS:
			if r, ok := inst.Args[1].(arm.Systemreg); !ok || !legalSysRegs[r] {
				fail(inst, "attempt to access illegal system reg")
			}
		case arm.BLR, arm.BR:
			if !isReg(inst.Args[0], resReg) && !isReg(inst.Args[0], retReg) {
				fail(inst, "indirect branch on non-reserved reg")
			}
		case arm.RET:
			if !isReg(inst.Args[0], retReg) {
				fail(inst, "return to invalid register")
			}
		}

		if multiexstores[inst.Op] {
			mustArgs(4, inst)
			checkMem(inst.Args[3], inst)
		} else if exstores[inst.Op] || multistores[inst.Op] || multiloads[inst.Op] {
			mustArgs(3, inst)
			checkMem(inst.Args[2], inst)
		} else if stores[inst.Op] || loads[inst.Op] {
			mustArgs(2, inst)
			checkMem(inst.Args[1], inst)
		}

		if (!exstores[inst.Op] && !multiexstores[inst.Op] && stores[inst.Op]) || branches[inst.Op] || nomodify[inst.Op] {
			// instructions that cannot modify their operands
			// since we already checked that stores have a proper base reg,
			// the post/pre-index addressing modes cannot modify fixed
			// registers in bad ways.
			continue
		}

		var modReg arm.Reg
		var sp bool
		switch r := inst.Args[0].(type) {
		case arm.Reg:
			modReg = r
		case arm.RegSP:
			modReg = arm.Reg(r)
			sp = true
		default:
			// does not modify a GPR
			continue
		}

		checkModReg(inst, insts, i, modReg, sp)

		if multiloads[inst.Op] {
			modReg = inst.Args[1].(arm.Reg)
			checkModReg(inst, insts, i, modReg, sp)
		}
	}

	if failed {
		fmt.Fprintln(os.Stderr, "verification failed")
		os.Exit(1)
	}
}
