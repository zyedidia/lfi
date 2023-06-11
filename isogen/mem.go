package main

import "fmt"

func fixAddr(a AddrMode, inst Inst, op, reg string, next []Inst) []Inst {
	if a.SingleReg() {
		// this addressing mode is fine
		next = append(next, inst)
		return next
	}
	switch m := a.(type) {
	case *MemArg5:
		if m.Extend != nil {
			next = append(next, &Modify4{
				Op:   "add",
				Dest: resReg,
				SrcA: m.Reg1,
				SrcB: m.Reg2,
				SrcC: m.Extend.String(),
			})
		} else {
			next = append(next, &Modify3{
				Op:   "add",
				Dest: resReg,
				SrcA: m.Reg1,
				SrcB: m.Reg2,
			})
		}
		stats.AddrModeFixups++
		next = append(next, &Load{
			Op:   op,
			Dest: reg,
			Addr: &MemArg1{
				Reg: resReg,
			},
		})
	}
	return next
}

func fixAddrModesPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		switch m := inst.(type) {
		case *Store:
			next = fixAddr(m.Addr, inst, m.Op, m.Src, next)
			continue
		case *Load:
			next = fixAddr(m.Addr, inst, m.Op, m.Dest, next)
			continue
		}
		next = append(next, inst)
	}
	return next
}

func sandboxAddr(a AddrMode, inst Inst, next []Inst, load bool) []Inst {
	if !a.SingleReg() {
		fmt.Println("warning: bad addressing mode", inst)
		next = append(next, inst)
		return next
	}
	if special[a.GetReg()] || a.GetReg() == "sp" {
		next = append(next, inst)
		return next
	}
	next = append(next, &AddUxtw{resReg, segmentReg, loReg(a.GetReg())})
	next = append(next, inst)
	switch a.(type) {
	case *MemArg2, *MemArg3:
		next = append(next, &Modify2{"mov", a.GetReg(), resReg})
		stats.PostAddrMoves++
	}
	a.SetReg(resReg)
	if load {
		stats.LoadMasks++
	} else {
		stats.StoreMasks++
	}
	return next
}

func memoryPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		switch m := inst.(type) {
		case *Store:
			next = sandboxAddr(m.Addr, inst, next, false)
		case *StoreM:
			next = sandboxAddr(m.Addr, inst, next, false)
		case *Load:
			next = sandboxAddr(m.Addr, inst, next, true)
		case *LoadM:
			next = sandboxAddr(m.Addr, inst, next, true)
		default:
			next = append(next, inst)
		}
	}
	return next
}
