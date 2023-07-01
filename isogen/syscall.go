package main

func syscallPass(insts []Inst) []Inst {
	var next []Inst
	for i := 0; i < len(insts); i++ {
		inst := insts[i]
		switch inst.(type) {
		case *Svc:
			next = append(next, &Store{Op: "str", Src: "x30", Addr: &MemArg3{
				Reg: "sp",
				Imm: "-16",
			}})
			next = append(next, &Branch{Op: "blr", Target: syscallReg})
			next = append(next, &Load{Op: "ldr", Dest: "x30", Addr: &MemArg2{
				Reg: "sp",
				Imm: "16",
			}})
		default:
			next = append(next, inst)
		}
	}
	return next
}
