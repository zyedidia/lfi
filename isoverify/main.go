package main

import (
	"flag"
	"fmt"
	"log"
	"os"

	arm "golang.org/x/arch/arm64/arm64asm"
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

const (
	branchReg  = arm.X21
	sandboxReg = arm.X20
)

var restrictedRegs = map[arm.Reg]bool{
	arm.X30: true,
	arm.W30: true,
	arm.H30: true,
	arm.B30: true,

	arm.X21: true,
	arm.W21: true,
	arm.H21: true,
	arm.B21: true,

	arm.X20: true,
	arm.W20: true,
	arm.H20: true,
	arm.B20: true,

	arm.SP:  true,
	arm.WSP: true,
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
			log.Fatal(err)
		}

		insts = append(insts, Inst{
			Inst: inst,
			Addr: addr,
		})

		addr += 4
		data = data[4:]
	}

	for _, inst := range insts {
		if !allowed[inst.Op] {
			fail(inst, "instruction disallowed")
			continue
		}
		switch inst.Op {
		case arm.BLR:
			reg := inst.Args[0].(arm.Reg)
			if reg != branchReg {
				fail(inst, fmt.Sprintf("indirect branch must use register %s", branchReg.String()))
				continue
			}
		case arm.BR:
			reg := inst.Args[0].(arm.Reg)
			if reg != branchReg {
				fail(inst, fmt.Sprintf("indirect branch must use register %s", branchReg.String()))
				continue
			}
		}
		// TODO: make sure only access to sandbox reg is via 'mov wX, wY'
		// TODO: make sure writes to lr/sp are followed by masking
		// TODO: make sure loads/stores use the dedicated reg
		// TODO: make sure loads/stores do not use fancy addressing modes
	}

	if failed {
		fmt.Fprintln(os.Stderr, "verification failed")
		os.Exit(1)
	}
}
