package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"os"

	"github.com/gofrs/flock"
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

func (s Stats) AccumulateFrom(file string) (Stats, error) {
	f, err := os.Open(file)
	if os.IsNotExist(err) {
		return s, nil
	}
	if err != nil {
		return s, err
	}
	defer f.Close()
	dec := json.NewDecoder(f)
	var old Stats
	err = dec.Decode(&old)
	if err != nil {
		return s, err
	}
	s = Stats{
		BranchMasks:    s.BranchMasks + old.BranchMasks,
		LoadMasks:      s.LoadMasks + old.LoadMasks,
		StoreMasks:     s.StoreMasks + old.StoreMasks,
		AddrModeFixups: s.AddrModeFixups + old.AddrModeFixups,
		PostAddrMoves:  s.PostAddrMoves + old.PostAddrMoves,
		ResMasks:       s.ResMasks + old.ResMasks,
	}
	return s, nil
}

func (s Stats) AccumulateTo(file string) (err error) {
	lock := flock.New("/tmp/isolator.lock")
	lock.Lock()
	defer lock.Unlock()

	s, err = s.AccumulateFrom(file)
	if err != nil {
		return err
	}
	f, err := os.Create(file)
	if err != nil {
		return err
	}
	defer f.Close()
	enc := json.NewEncoder(f)
	return enc.Encode(s)
}

var stats Stats
