package main

import "strings"

func gasDirectPass(ops *OpList) {
	btiPass(ops)
	markLabels(ops)
	markJumps(ops)
}

func gasRelativePass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			builder.Locate(op)
			if IsDirectBranch(inst) {
				builder.AddBefore(NewNode(&Directive{
					Val: ".p2align 4",
				}))
				builder.Add(NewNode(&Inst{
					Name: "sub",
					Args: []Arg{
						gasReg,
						gasReg,
						Number("0"),
					},
				}))
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
				builder.Add(NewNode(Label("1024")))
			} else if IsBranch(inst) {
				var target Reg
				if len(inst.Args) == 0 {
					target = Reg("x30")
				} else {
					target = inst.Args[0].(Reg)
				}
				// indirect branch
				builder.AddBefore(NewNode(&Directive{
					Val: ".p2align 4",
				}))
				builder.Add(NewNode(&Inst{
					Name: "adr",
					Args: []Arg{
						Reg("x24"),
						Label("1024f"),
					},
				}))
				builder.Add(NewNode(&Inst{
					Name: "sub",
					Args: []Arg{
						Reg("x24"),
						Reg("x24"),
						target,
					},
				}))
				t := "2"
				builder.Add(NewNode(&Inst{
					Name: "sub",
					Args: []Arg{
						gasReg,
						gasReg,
						Reg("x24"),
						&Extend{
							Op:  "asr",
							Imm: &t,
						},
					},
				}))
				builder.Add(NewNode(&Inst{
					Name: "tbz",
					Args: []Arg{
						gasReg,
						Number("63"),
						Label("1023f"),
					},
				}))
				builder.Add(NewNode(&Inst{
					Name: "brk",
					Args: []Arg{
						Number("0"),
					},
				}))
				builder.Add(NewNode(Label("1023")))
				// builder.Add(NewNode(&Inst{
				// 	Name: "bic",
				// 	Args: []Arg{
				// 		target,
				// 		target,
				// 		Number("0xf"),
				// 	},
				// }))
				builder.Add(NewNode(Label("1024")))
			}
		}
		op = op.Next
	}
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
						Label("#((1024f - 1023b) / 4)"),
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
