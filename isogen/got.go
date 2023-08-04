package main

func gotPass(ops *OpList) {
	op := ops.Front
	for op != nil {
		if inst, ok := op.Value.(*Inst); ok && inst.Name == "ldr" {
			if m, ok := inst.Args[1].(MemAddr); ok {
				if r, ok := m.Imm.(Reloc); ok {
					if r.Type == "got_lo12" {
						p := op.Prev.Value.(*Inst)
						if p.Name == "add" && len(p.Args) == 4 {
							op.Prev.Value = &Inst{
								Name: "mov",
								Args: []Arg{
									p.Args[0],
									hiReg(p.Args[2].(Reg)),
								},
							}
						}
						// b.list.Remove(op.Prev)
					}
				}
			}
		}
		op = op.Next
	}
}
