package main

func isMask(inst *Inst, reg Reg) bool {
	if len(inst.Args) != 4 {
		return false
	}
	r1, ok1 := inst.Args[0].(Reg)
	r2, ok2 := inst.Args[1].(Reg)
	r3, ok3 := inst.Args[2].(Reg)
	ex, ok := inst.Args[3].(*Extend)
	if ok1 && ok2 && ok3 && ok {
		return inst.Name == "add" &&
			r1 == optReg &&
			r2 == segmentReg &&
			r3 == loReg(reg) &&
			ex.Op == "uxtw" &&
			ex.Imm == nil
	}
	return false
}

func isModify(op *OpNode, inst *Inst, reg Reg) bool {
	if loads[inst.Name] {
		if r, ok := inst.Args[0].(Reg); ok && r == reg {
			return true
		}
		switch m := inst.Args[1].(type) {
		case MemAddrPre:
			return m.Reg == reg
		case MemAddrPost:
			return m.Reg == reg
		}
	} else if multiloads[inst.Name] {
		if r, ok := inst.Args[0].(Reg); ok && r == reg {
			return true
		}
		if r, ok := inst.Args[1].(Reg); ok && r == reg {
			return true
		}
		switch m := inst.Args[2].(type) {
		case MemAddrPre:
			return m.Reg == reg
		case MemAddrPost:
			return m.Reg == reg
		}
	} else if stores[inst.Name] {
		switch m := inst.Args[1].(type) {
		case MemAddrPre:
			return m.Reg == reg
		case MemAddrPost:
			return m.Reg == reg
		}
	} else if multistores[inst.Name] {
		switch m := inst.Args[2].(type) {
		case MemAddrPre:
			return m.Reg == reg
		case MemAddrPost:
			return m.Reg == reg
		}
	} else if !IsStore(op.Value) && len(inst.Args) > 0 {
		if r, ok := inst.Args[0].(Reg); ok && r == reg {
			return true
		}
	}
	return false
}

func rangeMask(op *OpNode, reg Reg, builder *Builder) {
	mask := NewNode(&Inst{
		Name: "add",
		Args: []Arg{
			optReg,
			segmentReg,
			loReg(reg),
			&Extend{Op: "uxtw"},
		},
	})
	n := op.Prev
loop:
	for n != nil {
		switch i := n.Value.(type) {
		case Label:
			builder.Locate(n)
			builder.Add(mask)
			break loop
		case *Inst:
			if isMask(i, reg) {
				break loop
			} else if isModify(n, i, reg) {
				builder.Locate(n)
				builder.Add(mask)
				break loop
			} else if calls[i.Name] {
				builder.Locate(n)
				builder.Add(mask)
				break loop
			}
		}
		n = n.Prev
	}
}

func sandboxMemAddrRange(op *OpNode, a *Arg, builder *Builder, reg Reg) {
	switch m := (*a).(type) {
	case MemAddr:
		if m.Reg != reg || m.Imm == nil {
			return
		}
		rangeMask(op, m.Reg, builder)
		*a = MemAddr{
			Reg: optReg,
			Imm: m.Imm,
		}
	case MemAddrComplex:
		if m.Reg1 != reg || m.Extend == nil {
			return
		}
		rangeMask(op, m.Reg1, builder)
		if m.Extend == nil {
			*a = MemAddrComplex{
				Reg1: optReg,
				Reg2: loReg(m.Reg2),
				Extend: &Extend{
					Op: "sxtw",
				},
			}
		} else {
			exop := "sxtw"
			if m.Extend.Op == "uxtw" {
				exop = "uxtw"
			}
			builder.Locate(op)
			builder.AddBefore(NewNode(&Inst{
				Name: "and",
				Args: []Arg{
					scratchReg,
					hiReg(m.Reg2),
					Number("0x0fffffff"),
				},
			}))
			*a = MemAddrComplex{
				Reg1: optReg,
				Reg2: loReg(scratchReg),
				Extend: &Extend{
					Op:  exop,
					Imm: m.Extend.Imm,
				},
			}
		}
	}
}

func getReg(a Arg) (Reg, bool) {
	switch m := a.(type) {
	case MemAddr:
		if m.Imm != nil {
			return m.Reg, true
		}
	case MemAddrComplex:
		if m.Extend != nil {
			return m.Reg1, true
		}
	}
	return "", false
}

func rangeAnalysisPass(ops *OpList) {
	var curLabel *OpNode
	op := ops.Front
	for op != nil {
		if _, ok := op.Value.(Label); ok {
			curLabel = op
		}
		if inst, ok := op.Value.(*Inst); ok {
			switch {
			case basicloads[inst.Name], basicstores[inst.Name], loads[inst.Name], stores[inst.Name]:
				r, ok := getReg(inst.Args[1])
				if ok && !sandboxed[r] {
					curLabel.memCounts[r]++
				}
			case multiloads[inst.Name], multistores[inst.Name]:
				r, ok := getReg(inst.Args[2])
				if ok && !sandboxed[r] {
					curLabel.memCounts[r]++
				}
			}
		}
		op = op.Next
	}
}

func rangePass(ops *OpList) {
	rangeAnalysisPass(ops)

	op := ops.Front
	builder := NewBuilder(ops)
	var curLabel *OpNode

	for op != nil {
		if _, ok := op.Value.(Label); ok {
			curLabel = op
			maxReg := Reg("")
			max := 1
			for k, v := range op.memCounts {
				if v > max {
					max = v
					maxReg = k
				}
			}
			op.rangeReg = maxReg
		}
		if inst, ok := op.Value.(*Inst); ok && curLabel != nil && curLabel.rangeReg != "" {
			builder.Locate(op)
			switch {
			case basicloads[inst.Name], basicstores[inst.Name]:
				sandboxMemAddrRange(op, &inst.Args[1], builder, curLabel.rangeReg)
			case loads[inst.Name], stores[inst.Name]:
				sandboxMemAddrRange(op, &inst.Args[1], builder, curLabel.rangeReg)
			case multiloads[inst.Name], multistores[inst.Name]:
				sandboxMemAddrRange(op, &inst.Args[2], builder, curLabel.rangeReg)
			}
		}
		op = op.Next
	}
}
