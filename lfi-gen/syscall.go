package main

import "fmt"

func addSyscall(offset int, native bool, b *Builder) *OpNode {
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

	if native {
		b.Add(NewNode(&Inst{
			Name: "str",
			Args: []Arg{
				Reg("x21"),
				MemAddrPre{
					Reg: Reg("sp"),
					Imm: "-16",
				},
			},
		}))

		b.Add(NewNode(&Inst{
			Name: "adr",
			Args: []Arg{
				segmentReg,
				Number("0"),
			},
		}))

		b.Add(NewNode(&Inst{
			Name: "and",
			Args: []Arg{
				segmentReg,
				segmentReg,
				Number("#0xffffffff00000000"),
			},
		}))
	}

	var imm Imm
	if offset != 0 {
		imm = Number(fmt.Sprintf("%d", offset))
	}

	sysPageReg := segmentReg
	if *hideSys {
		sysPageReg = sysReg
	}

	b.Add(NewNode(&Inst{
		Name: "ldr",
		Args: []Arg{
			retReg,
			MemAddr{
				Reg: sysPageReg,
				Imm: imm,
			},
		},
	}))

	b.Add(NewNode(&Inst{
		Name: "blr",
		Args: []Arg{retReg},
	}))

	if native {
		b.Add(NewNode(&Inst{
			Name: "ldr",
			Args: []Arg{
				Reg("x21"),
				MemAddrPost{
					Reg: Reg("sp"),
					Imm: "16",
				},
			},
		}))
	}

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

	if !native {
		b.Add(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				Reg("x30"),
				segmentReg,
				Reg("w30"),
				Extend{
					Op: "uxtw",
				},
			},
		}))
	}

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
				n := addSyscall(8, false, b)
				op = n
			}
		}
		op = op.Next
	}
}

func syscallPass(native bool, ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok && inst.Name == "svc" {
			b.Locate(op)
			n := addSyscall(0, native, b)
			b.list.Remove(op)
			op = n
		}
		op = op.Next
	}
}
