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
				builder.AddBefore(NewNode(Label("1024")))

				sub := builder.AddBefore(NewNode(&Inst{
					Name: "sub",
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
					Name: "tbz",
					Args: []Arg{
						gasReg,
						Number("63"),
						Label("1024f"),
					},
				}))
				builder.Add(NewNode(&Inst{
					Name: "brk",
					Args: []Arg{
						Number("0"),
					},
				}))
				builder.Locate(op)
				builder.Add(NewNode(Label("1023")))
			}
		}
		op = op.Next
	}
}
