package main

func syscallPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok && inst.Name == "svc" {
			b.Locate(op)

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

			b.Add(NewNode(&Inst{
				Name: "ldr",
				Args: []Arg{
					retReg,
					MemAddr{
						Reg: segmentReg,
						Imm: nil,
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
			b.list.Remove(op)
			op = n
		}
		op = op.Next
	}
}
