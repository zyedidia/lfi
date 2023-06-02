package main

func branchPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		switch b := inst.(type) {
		case *Branch:
			if b.Op == "bl" {
				// bl
				next = append(next, &Directive{p2align})
				next = append(next, &Opaque{Val: "nop"})
				next = append(next, &Branch{Op: "bl", Target: b.Target})
			} else {
				// br/blr
				next = append(next, &Modify3{"bic", resReg, b.Target, bundleMask})
				if b.Op == "blr" {
					next = append(next, &Directive{p2align})
				}
				next = append(next, &Movk{resReg, segmentId})
				next = append(next, &Branch{Op: b.Op, Target: resReg})
			}
			continue
		}
		next = append(next, inst)
	}
	return next
}
