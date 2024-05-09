package main

func FindLabels(labels map[Label]*OpNode, ops OpList) {
	op := ops.Front
	n := 0
	for op != nil {
		if l, ok := op.Value.(Label); ok {
			labels[l] = op
		}
		op.IdxEstimate = n
		op = op.Next
		n++
	}
}

func MarkLeaders(ops OpList) error {
	labels := make(map[Label]*OpNode)
	FindLabels(labels, ops)

	op := ops.Front
	op.Leader = true
	nextLeader := false
	for op != nil {
		op.Leader = nextLeader
		nextLeader = false
		if IsBranch(op.Value) {
			inst := op.Value.(*Inst)
			for _, a := range inst.Args {
				if l, ok := a.(Label); ok {
					if target, ok := labels[l]; ok {
						target.Leader = true
					} else {
						// return fmt.Errorf("label not found: %v", l)
					}
				}
			}
			nextLeader = true
		}
		op = op.Next
	}
	return nil
}
