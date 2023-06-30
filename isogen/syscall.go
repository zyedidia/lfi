package main

func syscallPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		switch inst.(type) {
		case *Svc:
			next = append(next, &Branch{Op: "blr", Target: syscallReg})
		default:
			next = append(next, inst)
		}
	}
	return next
}
