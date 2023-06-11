package main

import (
	"bytes"
	"fmt"
)

type Stats struct {
	BranchMasks    int
	LoadMasks      int
	StoreMasks     int
	AddrModeFixups int
	PostAddrMoves  int
	ResMasks       int
}

func (s Stats) String() string {
	b := &bytes.Buffer{}
	fmt.Fprintf(b, "branch masks: %d\n", s.BranchMasks)
	fmt.Fprintf(b, "load masks: %d\n", s.LoadMasks)
	fmt.Fprintf(b, "store masks: %d\n", s.StoreMasks)
	fmt.Fprintf(b, "addr mode fixups: %d\n", s.AddrModeFixups)
	fmt.Fprintf(b, "post addr moves: %d\n", s.PostAddrMoves)
	fmt.Fprintf(b, "reserved reg masks: %d\n", s.ResMasks)
	return b.String()
}

var stats Stats
