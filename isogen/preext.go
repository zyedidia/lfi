package main

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
	"adds": true,
	"sub":  true,
	"subs": true,
	"madd": true,
	"adcs": true,
	"adc":  true,
	"mneg": true,
	"msub": true,
	"mul":  true,
	"neg":  true,
	"negs": true,
	"ngc":  true,
	"ngcs": true,
	"sbc":  true,
	"sbcs": true,
	"sdiv": true,
	"mov":  true,
	"mvn":  true,
	"orn":  true,
	"orr":  true,
	"ror":  true,
	"lsr":  true,
	"lsl":  true,
	"eor":  true,
	"eon":  true,
	"bic":  true,
	"bics": true,
	"asr":  true,
	"and":  true,
	"ands": true,
}

func preExtensionPass(ops *OpList) {
	op := ops.Front
	b := NewBuilder(ops)
outer:
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok {
			if isMaskAny(inst, resReg) || isMaskAny(inst, optReg) || isMaskAny(inst, optReg2) {
				o := op.Prev
				// break out of this loop if we find a branch or label
				for o != nil {
					if inner, ok := o.Value.(*Inst); ok {
						if branches[inner.Name] {
							break
						}
						// check if the add uxtw guarded register is modified
						if mod, addr := isModify(o, inner, hiReg(inst.Args[2].(Reg))); mod && !addr {
							if !preExtendable[inst.Name] && !multiloads[inst.Name] && !loads[inst.Name] {
								break
							}
							for i, a := range inner.Args {
								if r, ok := a.(Reg); ok {
									if r == hiReg(inst.Args[2].(Reg)) {
										inner.Args[i] = loReg(scratchReg)
									} else {
										inner.Args[i] = loReg(r)
									}
								}
							}
							b.Locate(o)
							b.Add(NewNode(&Inst{
								Name: "mov",
								Args: []Arg{
									hiReg(inst.Args[2].(Reg)),
									scratchReg,
								},
							}))
							inst.Args[2] = scratchReg
							inst.Args[3] = nil
							inst.Args = inst.Args[:3]
							continue outer
						} else if addr {
							break
						}
					} else if _, ok := op.Value.(Label); ok {
						break
					}
					o = o.Prev
				}
			}
		}

		op = op.Next
	}
}
