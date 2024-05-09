package main

import (
	"bytes"
	"fmt"
)

type Op interface {
	isOp()
}

type Block struct {
	Name string
	Ops  OpList
}

type Inst struct {
	Name string
	Args []Arg
}

func (*Inst) isOp() {}

type Arg interface {
	isArg()
}

type Reg string

type Vector struct {
	Vals    []Reg
	Indexed *string
}

type Imm interface {
	Arg
	isImm()
}

type Number string

type Label string

type Reloc struct {
	Type string
	Var  string
}

// [Xn{, #i}]
type MemAddr struct {
	Reg Reg
	Imm Imm // may be nil
}

// [Xn], #i
// Xn += i after access
type MemAddrPost struct {
	Reg Reg
	Imm string
}

// [Xn], Xm
// Xn += Xm after access
type MemAddrPostReg struct {
	Reg    Reg
	RegOff Reg
}

// [Xn, #i]!
// Xn += i before access
type MemAddrPre struct {
	Reg Reg
	Imm string
}

// [Xn, Wm, {s,u}xtw{ #i|s}]
// [Xn, Xm sxtx{ #i|s}]
type MemAddrComplex struct {
	Reg1   Reg
	Reg2   Reg
	Extend *Extend
}

type Extend struct {
	Op  string
	Imm *string
}

type Directive struct {
	Val string
}

type Unknown string

func (Reg) isArg()            {}
func (Label) isArg()          {}
func (Reloc) isArg()          {}
func (Number) isArg()         {}
func (MemAddr) isArg()        {}
func (MemAddrPost) isArg()    {}
func (MemAddrPostReg) isArg() {}
func (MemAddrPre) isArg()     {}
func (MemAddrComplex) isArg() {}
func (Extend) isArg()         {}
func (Vector) isArg()         {}

func (Reloc) isImm()  {}
func (Number) isImm() {}
func (Label) isImm()  {}

func (Directive) isOp() {}
func (Label) isOp()     {}
func (Unknown) isOp()   {}

func (i *Inst) String() string {
	buf := &bytes.Buffer{}
	fmt.Fprintf(buf, "%s ", i.Name)
	for j, a := range i.Args {
		if l, ok := a.(Label); ok {
			fmt.Fprint(buf, string(l))
		} else {
			fmt.Fprintf(buf, "%v", a)
		}
		if j != len(i.Args)-1 {
			fmt.Fprint(buf, ", ")
		}
	}
	return buf.String()
}

func (r Reg) String() string {
	return string(r)
}

func (n Number) String() string {
	return string(n)
}

func (l Label) String() string {
	return string(l) + ":"
}

func (d Directive) String() string {
	return string(d.Val)
}

func (r Reloc) String() string {
	return fmt.Sprintf(":%s:%s", r.Type, r.Var)
}

func (m MemAddr) String() string {
	if m.Imm != nil {
		return fmt.Sprintf("[%v, %v]", m.Reg, m.Imm)
	}
	return fmt.Sprintf("[%v]", m.Reg)
}

func (m MemAddrPre) String() string {
	return fmt.Sprintf("[%v, %v]!", m.Reg, m.Imm)
}

func (m MemAddrPost) String() string {
	return fmt.Sprintf("[%v], %v", m.Reg, m.Imm)
}

func (m MemAddrPostReg) String() string {
	return fmt.Sprintf("[%v], %v", m.Reg, m.RegOff)
}

func (m MemAddrComplex) String() string {
	if m.Extend != nil {
		if m.Extend.Imm != nil {
			return fmt.Sprintf("[%v, %v, %s %s]", m.Reg1, m.Reg2, m.Extend.Op, *m.Extend.Imm)
		} else {
			return fmt.Sprintf("[%v, %v, %s]", m.Reg1, m.Reg2, m.Extend.Op)
		}
	}
	return fmt.Sprintf("[%v, %v]", m.Reg1, m.Reg2)
}

func (e Extend) String() string {
	if e.Imm != nil {
		return fmt.Sprintf("%s %s", e.Op, *e.Imm)
	}
	return e.Op
}

func (v Vector) String() string {
	b := &bytes.Buffer{}
	b.WriteByte('{')
	for i, r := range v.Vals {
		b.WriteString(string(r))
		if i != len(v.Vals)-1 {
			b.WriteByte(',')
		}
	}
	b.WriteByte('}')
	if v.Indexed != nil {
		b.WriteString(*v.Indexed)
	}
	return b.String()
}
