package main

import "strings"

func gasPass(ops *OpList) {
	btiPass(ops)
	markLabels(ops)
	markJumps(ops)
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

func markLabels(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if _, ok := op.Value.(Label); ok {
			builder.Locate(op)
			op = builder.Add(NewNode(Label("1023")))
		} else if d, ok := op.Value.(Directive); ok {
			if strings.HasPrefix(d.Val, ".section") {
				builder.Locate(op)
				op = builder.Add(NewNode(Label("1023")))
			}
		}
		op = op.Next
	}
}

func markJumps(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if IsBranch(inst) {
				builder.Locate(op)
				label := builder.AddBefore(NewNode(Label("1024")))

				// now find the instruction right before the branch to pull it in
				prev := label.Prev
				if prev != nil {
					if inst, ok := prev.Value.(*Inst); ok && !IsBranch(inst) {
						builder.Locate(prev)
					}
				}

				sub := builder.AddBefore(NewNode(&Inst{
					Name: "subs",
					Args: []Arg{
						gasReg,
						gasReg,
						Label("#(1024f - 1023b)"),
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
