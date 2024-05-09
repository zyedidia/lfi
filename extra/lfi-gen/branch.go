package main

import (
	"fmt"
	"strings"
)

func branchPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			// leave 'blr x30'/'br x30' untouched (used for runtime calls)
			if (inst.Name == "br" || inst.Name == "blr") && inst.Args[0].(Reg) != "x30" {
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
					if abs(n.IdxEstimate-op.IdxEstimate) >= 8000 {
						switch inst.Name {
						case "tbz":
							inst.Name = "tbnz"
						case "tbnz":
							inst.Name = "tbz"
						}

						tmplabel := Label(fmt.Sprintf(".LFI_FIXUP%d", ln))
						inst.Args[2] = tmplabel
						ln++

						b.Locate(op)

						if gas {
							// have to insert a gas sequence for the new branch
							b.Add(NewNode(&Directive{
								Val: ".p2align 4",
							}))
							b.Add(NewNode(&Inst{
								Name: "sub",
								Args: []Arg{
									gasReg,
									gasReg,
									Number("0"),
								},
							}))
							if *gasRel && *precise {
								b.Add(NewNode(&Inst{
									Name: "sub",
									Args: []Arg{
										gasReg,
										gasReg,
										Number("0"),
									},
								}))
							}
							b.Add(NewNode(&Inst{
								Name: "tbz",
								Args: []Arg{
									gasReg,
									Number("63"),
									Label("1024f"),
								},
							}))
							if *gasRel && *precise {
								b.Add(NewNode(&Inst{Name: "nop"}))
							}
							b.Add(NewNode(&Inst{
								Name: "brk",
								Args: []Arg{
									Number("0"),
								},
							}))
							b.Add(NewNode(Label("1024")))
						}

						b.Add(NewNode(&Inst{"b", []Arg{l}}))
						op = b.Add(NewNode(tmplabel))
					}
				}
			}
		}
		op = op.Next
	}
}

func oppCond(name string) string {
	switch name {
	case "cbz":
		return "cbnz"
	case "cbnz":
		return "cbz"
	case "tbz":
		return "tbnz"
	case "tbnz":
		return "tbz"
	case "b.ge":
		return "b.lt"
	case "b.lt":
		return "b.ge"
	case "b.eq":
		return "b.ne"
	case "b.ne":
		return "b.eq"
	case "b.cs", "b.hs":
		return "b.cc"
	case "b.cc", "b.lo":
		return "b.cs"
	case "b.mi":
		return "b.pl"
	case "b.pl":
		return "b.mi"
	case "b.vs":
		return "b.vc"
	case "b.vc":
		return "b.vs"
	case "b.hi":
		return "b.ls"
	case "b.ls":
		return "b.hi"
	case "b.gt":
		return "b.le"
	case "b.le":
		return "b.gt"
	}
	return "error"
}

func branchPrecisePass(ops *OpList) {
	labels := make(map[Label]*OpNode)
	FindLabels(labels, *ops)

	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			var l Label
			var li int
			if strings.HasPrefix(inst.Name, "b.") {
				l = inst.Args[0].(Label)
				li = 0
			} else if inst.Name == "cbz" || inst.Name == "cbnz" {
				l = inst.Args[1].(Label)
				li = 1
			} else if inst.Name == "tbz" || inst.Name == "tbnz" {
				l = inst.Args[2].(Label)
				li = 2
			} else {
				op = op.Next
				continue
			}
			if n, ok := labels[l]; ok {
				if n.IdxEstimate < op.IdxEstimate {
					// backwards branch, rewrite into forwards branch
					inst.Name = oppCond(inst.Name)
					b.Locate(op)
					newLabel := Label(fmt.Sprintf(".LFI_NOTTAKEN%d", ln))
					ln++
					inst.Args[li] = newLabel
					b.Add(NewNode(&Inst{
						Name: "b",
						Args: []Arg{
							l,
						},
					}))
					b.Add(NewNode(newLabel))
				}
			}
		}
		op = op.Next
	}
}

func alignLabelsPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if _, ok := op.Value.(Label); ok {
			if op.Next != nil {
				if _, ok := op.Next.Value.(*Inst); ok {
					b.Locate(op)
					b.AddBefore(NewNode(&Directive{
						Val: ".p2align 4",
					}))
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
