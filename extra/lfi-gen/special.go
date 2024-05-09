package main

import (
	"log"
)

func sandboxSp(builder *Builder) {
	builder.Add(NewNode(&Inst{
		Name: "mov",
		Args: []Arg{
			loReg(scratchReg),
			Reg("wsp"),
		},
	}))

	builder.Add(NewNode(&Inst{
		Name: "add",
		Args: []Arg{
			Reg("sp"),
			segmentReg,
			scratchReg,
		},
	}))
}

func sandboxLr(builder *Builder) {
	builder.Add(NewNode(&Inst{
		Name: "add",
		Args: []Arg{
			Reg("x30"),
			segmentReg,
			Reg("w30"),
			Extend{Op: "uxtw"},
		},
	}))
}

func sandboxDest(dest Reg, builder *Builder) {
	if dest == Reg("sp") {
		sandboxSp(builder)
	} else if dest == Reg("x30") || dest == Reg("lr") {
		sandboxLr(builder)
	}
}

func specialRegPass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
instloop:
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			builder.Locate(op)
			if inst.Name == "add" || inst.Name == "sub" {
				if r, ok := inst.Args[0].(Reg); ok && r == "sp" {
					if r2, ok := inst.Args[1].(Reg); ok && r2 == "sp" && len(inst.Args) < 4 {
						// only apply optimizations when there is no shift modifier
						o := op
						for o != nil {
							if inner, ok := o.Value.(*Inst); ok {
								if loads[inner.Name] || multiloads[inner.Name] || stores[inner.Name] || multistores[inner.Name] {
									var m Arg
									if loads[inner.Name] || stores[inner.Name] {
										m = inner.Args[1]
									} else {
										m = inner.Args[2]
									}
									var base Reg
									switch m := m.(type) {
									case MemAddr:
										base = m.Reg
									case MemAddrPost:
										base = m.Reg
									case MemAddrPre:
										base = m.Reg
									}
									if base == "sp" {
										op = op.Next
										continue instloop
									}
								} else if branches[inner.Name] {
									break
								}
							}
							o = o.Next
						}
					}
					inst.Args[0] = loReg(scratchReg)
					inst.Args[1] = loReg(inst.Args[1].(Reg))
					if r, ok := inst.Args[2].(Reg); ok {
						inst.Args[2] = loReg(r)
					}
					op = builder.Add(NewNode(&Inst{
						Name: "add",
						Args: []Arg{
							Reg("sp"),
							segmentReg,
							scratchReg,
						},
					}))
					op = op.Next
					continue
				}
			}
			if loads[inst.Name] {
				if r, ok := inst.Args[0].(Reg); ok {
					if inst.Name == "ldr" {
						// allow 'ldr [sys, #n]' without rewriting
						if m, ok := inst.Args[1].(MemAddr); ok && r == retReg && m.Reg == sysReg {
							op = op.Next
							continue
						}
					}
					sandboxDest(r, builder)
				}
			} else if multiloads[inst.Name] {
				if r, ok := inst.Args[0].(Reg); ok {
					sandboxDest(r, builder)
				}
				if r, ok := inst.Args[1].(Reg); ok {
					sandboxDest(r, builder)
				}
			} else if !IsStore(op.Value) && !IsBranch(op.Value) && len(inst.Args) > 0 {
				if r, ok := inst.Args[0].(Reg); ok {
					sandboxDest(r, builder)
				}
			}
			op = builder.cur
		}

		op = op.Next
	}
}

func fixupReservedPass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if multiloads[inst.Name] {
				builder.Locate(op)
				r1, o1 := inst.Args[0].(Reg)
				r2, o2 := inst.Args[1].(Reg)
				if o1 && o2 && reserved[r1] && reserved[r2] {
					builder.list.Remove(op)
				} else if o1 && reserved[r1] {
					inst.Args[0] = Reg("xzr")
				} else if o2 && reserved[r2] {
					inst.Args[1] = Reg("xzr")
				} else {
					if o1 && sandboxed(r1) {
						if r1 == spReg {
							log.Fatal("error: loading into stack pointer")
						}
						builder.Add(NewNode(&Inst{
							Name: "add",
							Args: []Arg{
								r1,
								segmentReg,
								loReg(r1),
								Extend{
									Op: "uxtw",
								},
							},
						}))
					}
					if o2 && sandboxed(r2) {
						if r2 == spReg {
							log.Fatal("error: loading into stack pointer")
						}
						builder.Add(NewNode(&Inst{
							Name: "add",
							Args: []Arg{
								r2,
								segmentReg,
								loReg(r2),
								Extend{
									Op: "uxtw",
								},
							},
						}))
					}
				}
			}
		}
		op = op.Next
	}
}
