package main

import "fmt"

func addSyscall(offset int, b *Builder) *OpNode {
	b.Add(NewNode(&Inst{
		Name: "str",
		Args: []Arg{
			Reg("x30"),
			MemAddrPre{
				Reg: Reg("sp"),
				Imm: "-16",
			},
		},
	}))

	var imm Imm
	if offset != 0 {
		imm = Number(fmt.Sprintf("%d", offset))
	}

	b.Add(NewNode(&Inst{
		Name: "ldr",
		Args: []Arg{
			retReg,
			MemAddr{
				Reg: segmentReg,
				Imm: imm,
			},
		},
	}))

	b.Add(NewNode(&Inst{
		Name: "blr",
		Args: []Arg{retReg},
	}))

	n := b.Add(NewNode(&Inst{
		Name: "ldr",
		Args: []Arg{
			Reg("x30"),
			MemAddrPost{
				Reg: Reg("sp"),
				Imm: "16",
			},
		},
	}))
	return n
}

func instrumentPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok && inst.Name == "add" && len(inst.Args) == 4 {
			r2, ok := inst.Args[1].(Reg)
			e, eok := inst.Args[3].(Extend)
			if ok && r2 == segmentReg && eok && e.Op == "uxtw" {
				b.Locate(op)
				n := addSyscall(8, b)
				op = n
			}
		}
		op = op.Next
	}
}

func syscallPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok && inst.Name == "svc" {
			b.Locate(op)
			n := addSyscall(0, b)
			b.list.Remove(op)
			op = n
		}
		op = op.Next
	}
}
