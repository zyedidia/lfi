package main

import (
	"log"
	"strconv"
)

func sandboxMemAddr(a *Arg, builder *Builder) bool {
	switch m := (*a).(type) {
	case MemAddr:
		if sandboxed(m.Reg) {
			return true
		}
		if m.Reg == segmentReg {
			return false
		}
		if m.Imm == nil {
			*a = MemAddrComplex{
				Reg1: segmentReg,
				Reg2: loReg(m.Reg),
				Extend: &Extend{
					Op: "uxtw",
				},
			}
		} else {
			switch i := m.Imm.(type) {
			case Number:
				x, err := strconv.Atoi(string(i))
				if err != nil || x >= 4096 {
					return false
				}
			case Reloc:
				if i.Type != "lo12" {
					return false
				}
			default:
				return false
			}
			builder.AddBefore(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					loReg(scratchReg),
					loReg(m.Reg),
					m.Imm,
				},
			}))
			*a = MemAddrComplex{
				Reg1: segmentReg,
				Reg2: loReg(scratchReg),
				Extend: &Extend{
					Op: "uxtw",
				},
			}
		}
	case MemAddrPost:
		if sandboxed(m.Reg) {
			return true
		}
		*a = MemAddrComplex{
			Reg1: segmentReg,
			Reg2: loReg(m.Reg),
			Extend: &Extend{
				Op: "uxtw",
			},
		}
		builder.Add(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				m.Reg,
				m.Reg,
				Number(m.Imm),
			},
		}))
	case MemAddrPostReg:
		return false
	case MemAddrPre:
		if sandboxed(m.Reg) {
			return true
		}
		builder.AddBefore(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				m.Reg,
				m.Reg,
				Number(m.Imm),
			},
		}))
		*a = MemAddrComplex{
			Reg1: segmentReg,
			Reg2: loReg(m.Reg),
			Extend: &Extend{
				Op: "uxtw",
			},
		}
	case MemAddrComplex:
		if sandboxed(m.Reg1) {
			return true
		}
		if m.Extend == nil {
			builder.AddBefore(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					loReg(scratchReg),
					loReg(m.Reg1),
					loReg(m.Reg2),
				},
			}))
			*a = MemAddrComplex{
				Reg1: segmentReg,
				Reg2: loReg(scratchReg),
				Extend: &Extend{
					Op: "uxtw",
				},
			}
		} else {
			builder.AddBefore(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					loReg(scratchReg),
					loReg(m.Reg1),
					loReg(m.Reg2),
					m.Extend,
				},
			}))
			*a = MemAddrComplex{
				Reg1: segmentReg,
				Reg2: loReg(scratchReg),
				Extend: &Extend{
					Op: "uxtw",
				},
			}
		}
	default:
		log.Fatal("bad addressing mode")
	}
	return true
}

func sandboxMemAddrNoOpt(op *OpNode, a *Arg, builder *Builder) {
	switch m := (*a).(type) {
	case MemAddr:
		if sandboxed(m.Reg) {
			return
		}
		if m.Reg == segmentReg {
			// allow 'ldr [x21, #n]' without rewriting
			return
		}
		builder.AddBefore(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				resReg,
				segmentReg,
				loReg(m.Reg),
				Extend{Op: "uxtw"},
			},
		}))
		*a = MemAddr{
			Reg: resReg,
			Imm: m.Imm,
		}
	case MemAddrPre:
		if sandboxed(m.Reg) {
			return
		}
		builder.AddBefore(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				resReg,
				segmentReg,
				loReg(m.Reg),
				Extend{Op: "uxtw"},
			},
		}))
		*a = MemAddrPre{
			Reg: resReg,
			Imm: m.Imm,
		}
		builder.Locate(op)
		tReg := m.Reg
		sReg := resReg
		if *poc {
			tReg = loReg(tReg)
			sReg = loReg(sReg)
		}
		builder.Add(NewNode(&Inst{
			Name: "mov",
			Args: []Arg{
				tReg,
				sReg,
			},
		}))
	case MemAddrPost:
		if sandboxed(m.Reg) {
			return
		}
		builder.AddBefore(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				resReg,
				segmentReg,
				loReg(m.Reg),
				Extend{Op: "uxtw"},
			},
		}))
		*a = MemAddrPost{
			Reg: resReg,
			Imm: m.Imm,
		}
		builder.Locate(op)
		tReg := m.Reg
		sReg := resReg
		if *poc {
			tReg = loReg(tReg)
			sReg = loReg(sReg)
		}
		builder.Add(NewNode(&Inst{
			Name: "mov",
			Args: []Arg{
				tReg,
				sReg,
			},
		}))
	case MemAddrPostReg:
		builder.AddBefore(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				resReg,
				segmentReg,
				loReg(m.Reg),
				Extend{Op: "uxtw"},
			},
		}))
		*a = MemAddr{
			Reg: resReg,
		}
		builder.Locate(op)
		builder.Add(NewNode(&Inst{
			Name: "add",
			Args: []Arg{
				m.Reg,
				m.Reg,
				m.RegOff,
			},
		}))
	case MemAddrComplex:
		if sandboxed(m.Reg1) {
			return
		}
		if m.Extend == nil {
			builder.AddBefore(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					loReg(scratchReg),
					loReg(m.Reg1),
					loReg(m.Reg2),
				},
			}))
			builder.Add(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					resReg,
					segmentReg,
					loReg(scratchReg),
					Extend{Op: "uxtw"},
				},
			}))
			*a = MemAddr{
				Reg: resReg,
			}
		} else {
			builder.AddBefore(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					loReg(scratchReg),
					loReg(m.Reg1),
					loReg(m.Reg2),
					m.Extend,
				},
			}))
			builder.Add(NewNode(&Inst{
				Name: "add",
				Args: []Arg{
					resReg,
					segmentReg,
					loReg(scratchReg),
					Extend{Op: "uxtw"},
				},
			}))
			*a = MemAddr{
				Reg: resReg,
			}
		}
	default:
		log.Fatal("bad addressing mode")
	}
}

func memPass(ops *OpList) {
	op := ops.Front
	builder := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			builder.Locate(op)
			switch {
			case exstores[inst.Name]:
				sandboxMemAddrNoOpt(op, &inst.Args[2], builder)
			case multiexstores[inst.Name]:
				sandboxMemAddrNoOpt(op, &inst.Args[3], builder)
			case basicloads[inst.Name] && !*noloads:
				fallthrough
			case basicstores[inst.Name]:
				if *opt < 1 || !sandboxMemAddr(&inst.Args[1], builder) {
					sandboxMemAddrNoOpt(op, &inst.Args[1], builder)
				}
			case loads[inst.Name] && !*noloads:
				fallthrough
			case stores[inst.Name]:
				sandboxMemAddrNoOpt(op, &inst.Args[1], builder)
			case multiloads[inst.Name] && !*noloads:
				fallthrough
			case multistores[inst.Name]:
				sandboxMemAddrNoOpt(op, &inst.Args[2], builder)
			}
		}
		op = op.Next
	}
}
