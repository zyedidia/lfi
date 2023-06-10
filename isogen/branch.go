package main

func branchPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		switch b := inst.(type) {
		case *Branch:
			// br/blr
			next = append(next, &AddUxtw{resReg, segmentReg, loReg(b.Target)})
			next = append(next, &Branch{Op: b.Op, Target: resReg})
			stats.BranchMasks++
			continue
		}
		next = append(next, inst)
	}
	return next
}
