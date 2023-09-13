package main

func posObliviousPass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			builder.Locate(op)
			if inst.Name == "adr" || inst.Name == "adrp" {
				builder.Add(NewNode(&Inst{
					Name: "mov",
					Args: []Arg{
						loReg(inst.Args[0].(Reg)),
						loReg(resReg),
					},
				}))
				inst.Args[0] = resReg
			} else if len(inst.Args) >= 1 {
				if r, ok := inst.Args[0].(Reg); ok && r == "sp" {
					op = op.Next
					continue
				}
				for _, a := range inst.Args[1:] {
					if r, ok := a.(Reg); ok && r == "sp" {
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
