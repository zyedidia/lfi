package main

import "fmt"

func branchPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if inst.Name == "br" || inst.Name == "blr" {
				b.Locate(op)
				b.AddBefore(NewNode(&Inst{
					Name: "add",
					Args: []Arg{
						resReg,
						segmentReg,
						loReg(inst.Args[0].(Reg)),
						Extend{
							Op: "uxtw",
						},
					},
				}))
				inst.Args[0] = resReg
			}
		}
		op = op.Next
	}
}

var ln = 1

func branchFixupPass(ops *OpList) {
	labels := make(map[Label]*OpNode)
	FindLabels(labels, *ops)

	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if inst.Name == "tbz" || inst.Name == "tbnz" {
				l := inst.Args[2].(Label)

				if n, ok := labels[l]; ok {
					if abs(n.IdxEstimate-op.IdxEstimate) >= 16000 {
						switch inst.Name {
						case "tbz":
							inst.Name = "tbnz"
						case "tbnz":
							inst.Name = "tbz"
						}

						tmplabel := Label(fmt.Sprintf(".ISOL%d", ln))
						inst.Args[2] = tmplabel
						ln++

						b.Locate(op)
						b.Add(NewNode(&Inst{"b", []Arg{l}}))
						op = b.Add(NewNode(tmplabel))
					}
				}
			}
		}
		op = op.Next
	}
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}
