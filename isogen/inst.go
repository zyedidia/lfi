package main

import "fmt"

// opaque directive
// .val
type Directive struct {
	Val string
}

func (i *Directive) String() string {
	return i.Val
}

// name:
type Label struct {
	Name string
}

func (i *Label) String() string {
	return i.Name + ":"
}

// br/blr/bl target
type Branch struct {
	Op     string // br or blr
	Target string
}

func (i *Branch) String() string {
	return fmt.Sprintf("%s %s", i.Op, i.Target)
}

// ldr dest, [addr]
type Load struct {
	Op   string
	Dest string
	Addr AddrMode
}

func (i *Load) String() string {
	return fmt.Sprintf("%s %s, %s", i.Op, i.Dest, i.Addr)
}

// ldp desta, destb, [addr]
type LoadM struct {
	Op    string
	DestA string
	DestB string
	Addr  AddrMode
}

func (i *LoadM) String() string {
	return fmt.Sprintf("%s %s, %s, %s", i.Op, i.DestA, i.DestB, i.Addr)
}

// str src, [addr]
type Store struct {
	Op   string
	Src  string
	Addr AddrMode
}

func (i *Store) String() string {
	return fmt.Sprintf("%s %s, %s", i.Op, i.Src, i.Addr)
}

// stp srca, srcb, [addr]
type StoreM struct {
	Op   string
	SrcA string
	SrcB string
	Addr AddrMode
}

func (i *StoreM) String() string {
	return fmt.Sprintf("%s %s, %s, %s", i.Op, i.SrcA, i.SrcB, i.Addr)
}

// xx dest, srca, srcb, srcc
type Modify4 struct {
	Op   string
	Dest string
	SrcA string
	SrcB string
	SrcC string
}

func (i *Modify4) String() string {
	return fmt.Sprintf("%s %s, %s, %s, %s", i.Op, i.Dest, i.SrcA, i.SrcB, i.SrcC)
}

// xx dest, srca, srcb
type Modify3 struct {
	Op   string
	Dest string
	SrcA string
	SrcB string
}

func (i *Modify3) String() string {
	return fmt.Sprintf("%s %s, %s, %s", i.Op, i.Dest, i.SrcA, i.SrcB)
}

// xx dest, src
type Modify2 struct {
	Op   string
	Dest string
	Src  string
}

func (i *Modify2) String() string {
	return fmt.Sprintf("%s %s, %s", i.Op, i.Dest, i.Src)
}

// add Xn, Xm, Wn, uxtw
type AddUxtw struct {
	Dest string
	SrcA string
	SrcB string
}

func (i *AddUxtw) String() string {
	return fmt.Sprintf("add %s, %s, %s, uxtw", i.Dest, i.SrcA, i.SrcB)
}

// movk dest, imm, lsl #32
type Movk struct {
	Dest string
	Imm  string
}

func (i *Movk) String() string {
	// return fmt.Sprintf("movk %s, %s, lsl #32", i.Dest, i.Imm)
	return "nop"
}

type Opaque struct {
	Val string
}

func (i *Opaque) String() string {
	return i.Val
}

// One of the above instructions
type Inst interface {
	String() string
}

// One of MemArgN
type AddrMode interface {
	String() string
	GetReg() string
	SingleReg() bool
	SetReg(r string)
}
