package main

import (
	"log"
	"strconv"
)

func isMaskAny(inst *Inst, optReg Reg) bool {
	if len(inst.Args) != 4 {
		return false
	}
	r1, ok1 := inst.Args[0].(Reg)
	r2, ok2 := inst.Args[1].(Reg)
	_, ok3 := inst.Args[2].(Reg)
	ex, ok := inst.Args[3].(Extend)
	if ok1 && ok2 && ok3 && ok {
		return inst.Name == "add" &&
			r1 == optReg &&
			r2 == segmentReg &&
			ex.Op == "uxtw" &&
			ex.Imm == nil
	}
	return false
}

var preExtendable = map[string]bool{
	"add":  true,
	"sub":  true,
	"madd": true,
	"mov":  true,
}

func unused(start *OpNode, reg Reg) bool {
	op := start
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if branches[inst.Name] {
				if calls[inst.Name] && tempReg[reg] {
					return true
				}
				return false
			}
			clobbered := false
			for i, a := range inst.Args {
				switch a := a.(type) {
				case Reg:
					if hiReg(a) == reg {
						if i == 0 {
							if loads[inst.Name] || preExtendable[inst.Name] {
								clobbered = true
								continue
							}
						}
						return false
					}
				case MemAddr:
					if hiReg(a.Reg) == reg {
						return false
					}
				case MemAddrPre:
					if hiReg(a.Reg) == reg {
						return false
					}
				case MemAddrPost:
					if hiReg(a.Reg) == reg {
						return false
					}
				case MemAddrComplex:
					if hiReg(a.Reg1) == reg || hiReg(a.Reg2) == reg {
						return false
					}
				}
			}
			if clobbered {
				return true
			}
		} else {
			break
		}
		op = op.Next
	}
	return false
}

func preExtensionPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if isMaskAny(inst, resReg) || isMaskAny(inst, optReg) || isMaskAny(inst, optReg2) {
				o := op.Prev
				if inner, ok := o.Value.(*Inst); ok {
					if branches[inner.Name] {
						op = op.Next
						continue
					}
					if mod, _ := isModify(o, inner, loReg(scratchReg)); mod {
						op = op.Next
						continue
					}
					// check if the add uxtw guarded register is modified
					if mod, addr := isModify(o, inner, hiReg(inst.Args[2].(Reg))); mod && !addr {
						if !preExtendable[inner.Name] && !loads[inner.Name] {
							op = op.Next
							continue
						}
						if loads[inner.Name] {
							var imm Imm
							switch m := inner.Args[1].(type) {
							case MemAddr:
								imm = m.Imm
							case MemAddrPre:
								imm = Number(m.Imm)
							case MemAddrPost:
								imm = Number(m.Imm)
							}
							if imm != nil {
								switch i := imm.(type) {
								case Number:
									x, err := strconv.Atoi(string(i))
									if err != nil || x >= 16384 {
										op = op.Next
										continue
									}
								case Reloc:
									if i.Type != "lo12" && i.Type != "got_lo12" {
										op = op.Next
										continue
									}
								default:
									log.Fatal("invalid immediate")
								}
							}
						}
						if !unused(op.Next, hiReg(inst.Args[2].(Reg))) {
							op = op.Next
							continue
						}
						if !loads[inner.Name] {
							for i, a := range inner.Args {
								if r, ok := a.(Reg); ok {
									inner.Args[i] = loReg(r)
								}
							}
						}
						inner.Args[0] = loReg(scratchReg)
						b.Locate(o)
						inst.Args[2] = scratchReg
						inst.Args[3] = nil
						inst.Args = inst.Args[:3]
						op = op.Next
						continue
					} else if addr {
						op = op.Next
						continue
					}
				}
			}
		}

		op = op.Next
	}
}
