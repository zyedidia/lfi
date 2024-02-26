package main

import "fmt"

func gasPass(ops *OpList) {
	btiPass(ops)
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

func markJumps(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if IsDirectBranch(inst) {
				builder.Locate(op)
				label := builder.AddBefore(NewNode(Label("1024")))
				// now find the instruction right before the branch
				if label.Prev != nil {
					for inst, ok = label.Prev.Value.(*Inst); !ok; inst, ok = label.Prev.Value.(*Inst) {
						label = label.Prev
					}
				}
				if label.Prev != nil && ok && !IsBranch(label.Prev.Value.(*Inst)) {
					builder.Locate(label.Prev)
				}
				sub := builder.AddBefore(NewNode(&Inst{
					Name: "subs",
					Args: []Arg{
						gasReg,
						gasReg,
						Label(fmt.Sprintf("#(1024f - %s)", string(inst.Args[0].(Label)))),
					},
				}))
				builder.AddBefore(NewNode(&Directive{
					Val: ".p2align 5",
				}))
				builder.Locate(sub)
				builder.Add(NewNode(&Inst{
					Name: "bcc",
					Args: []Arg{
						Label("#(1 << 20 - 4)"),
					},
				}))
			} else if IsBranch(inst) {
				// indirect branch
				builder.Locate(op)
				builder.AddBefore(NewNode(Label("1024")))
				op := builder.AddBefore(NewNode(&Inst{
					Name: "adr",
					Args: []Arg{
						loReg(scratchReg),
						Label("1024f"),
					},
				}))
				builder.Locate(op)
				builder.AddBefore(NewNode(&Directive{
					Val: ".p2align 5",
				}))
				builder.Add(NewNode(&Inst{
					Name: "sub",
					Args: []Arg{
						loReg(scratchReg),
						loReg(scratchReg),
						loReg(inst.Args[0].(Reg)),
					},
				}))
				builder.Add(NewNode(&Inst{
					Name: "subs",
					Args: []Arg{
						gasReg,
						gasReg,
						loReg(scratchReg),
						Extend{Op: "sxtw"},
					},
				}))
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
