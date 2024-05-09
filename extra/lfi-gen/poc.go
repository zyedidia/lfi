package main

func posObliviousPass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			builder.Locate(op)
			if inst.Name == "adrp" || inst.Name == "adr" {
				builder.Add(NewNode(&Inst{
					Name: "mov",
					Args: []Arg{
						loReg(inst.Args[0].(Reg)),
						loReg(scratchReg),
					},
				}))
				inst.Args[0] = scratchReg
			} else if len(inst.Args) >= 1 {
				if r, ok := inst.Args[0].(Reg); (ok && r == "sp") || !ok {
					op = op.Next
					continue
				}

				if inst.Name == "ldp" {
					op = op.Next
					continue
				}
				if inst.Name == "stp" && inst.Args[0].(Reg) == retReg {
					builder.Locate(op)
					builder.AddBefore(NewNode(&Inst{
						Name: "mov",
						Args: []Arg{
							loReg(Reg("x24")),
							loReg(retReg),
						},
					}))
					inst.Args[0] = Reg("x24")
					op = op.Next
					continue
				}
				if inst.Name == "stp" && inst.Args[1].(Reg) == retReg {
					builder.Locate(op)
					builder.AddBefore(NewNode(&Inst{
						Name: "mov",
						Args: []Arg{
							loReg(Reg("x24")),
							loReg(retReg),
						},
					}))
					inst.Args[1] = Reg("x24")
					op = op.Next
					continue
				}
				if inst.Name == "str" && inst.Args[0].(Reg) == "x30" {
					builder.Locate(op)
					builder.AddBefore(NewNode(&Inst{
						Name: "mov",
						Args: []Arg{
							loReg(Reg("x24")),
							loReg(retReg),
						},
					}))
					inst.Args[0] = Reg("x24")
					op = op.Next
					continue
				}
				// reading from sp into another register
				// TODO: this currently causes the read to use x18 as a scratch
				// register, which may not verify properly if the instruction
				// writing to x18 is an arbitrary add.
				for _, a := range inst.Args[1:] {
					if r, ok := a.(Reg); ok && r == "sp" || r == "x30" {
						builder.Add(NewNode(&Inst{
							Name: "mov",
							Args: []Arg{
								loReg(inst.Args[0].(Reg)),
								loReg(resReg),
							},
						}))
						inst.Args[0] = resReg
					}
				}
			}
		}
		op = op.Next
	}
}
