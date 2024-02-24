package main

func gasPass(ops *OpList) {
	markJumps(ops)
	btiPass(ops)
}

func btiPass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			builder.Locate(op)
			switch inst.Name {
			case "bl", "blr":
				builder.Add(NewNode(&Inst{
					Name: "bti",
				}))
			case "ret":
				builder.Add(NewNode(&Inst{
					Name: "br",
					Args: []Arg{
						Reg("x30"),
					},
				}))
				builder.list.Remove(op)
			}
		}
		op = op.Next
	}
}

func markJumps(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	builder.Locate(op)
	builder.AddBefore(NewNode(Label("1024")))
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if IsBranch(inst) {
				builder.Locate(op)
				label := builder.AddBefore(NewNode(Label("1024")))
				for inst, ok = label.Prev.Value.(*Inst); !ok; inst, ok = label.Prev.Value.(*Inst) {
					label = label.Prev
				}
				if !IsBranch(label.Prev.Value.(*Inst)) {
					builder.Locate(label.Prev)
				}
				sub := builder.AddBefore(NewNode(&Inst{
					Name: "subs",
					Args: []Arg{
						gasReg,
						gasReg,
						Label("#(1024f - 1024b)"),
					},
				}))
				builder.AddBefore(NewNode(&Directive{
					Val: ".p2align 4",
				}))
				builder.Locate(sub)
				builder.Add(NewNode(&Inst{
					Name: "bcc",
					Args: []Arg{
						Label("#(1 << 20 - 4)"),
					},
				}))
			}
		}
		op = op.Next
	}
}
