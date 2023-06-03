package main

var special = map[string]bool{
	"lr":  true,
	"fp":  true,
	"x30": true,
}

func sandboxSp(next []Inst) []Inst {
	next = append(next, &Modify2{"mov", resReg, "sp"})
	next = append(next, &Movk{resReg, segmentId})
	next = append(next, &Modify2{"mov", "sp", resReg})
	stats.ResMasks++
	return next
}

func sandboxLr(next []Inst) []Inst {
	next = append(next, &Movk{"x30", segmentId})
	next = append(next, &Modify3{"bic", "x30", "x30", bundleMask})
	stats.ResMasks++
	return next
}

func sandboxDest(dest string, next []Inst) []Inst {
	if dest == "sp" {
		next = sandboxSp(next)
	} else if dest == "lr" || dest == "x30" {
		next = sandboxLr(next)
	}
	return next
}

func specialRegPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		next = append(next, inst)
		switch inst := inst.(type) {
		case *Modify2:
			next = sandboxDest(inst.Dest, next)
		case *Modify3:
			next = sandboxDest(inst.Dest, next)
		case *Modify4:
			next = sandboxDest(inst.Dest, next)
		case *Load:
			next = sandboxDest(inst.Dest, next)
		case *LoadM:
			next = sandboxDest(inst.DestA, next)
			next = sandboxDest(inst.DestB, next)
		}
	}
	return next
}
