package main

import (
	"fmt"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/participle/v2/lexer"
)

var armLexer = lexer.MustSimple([]lexer.SimpleRule{
	{`Ident`, `[_@.a-zA-Z][.a-zA-Z_\-\d+]*`},
	{`Number`, `[-+]?(0x)?[.0-9a-fA-F+\-:][.0-9a-zA-Z_+\-:]*\b`},
	{`Punct`, `[,:()\[\]#!]`},
	{`Newline`, `\r?\n`},
	{"comment", `//.*|/\*.*?\*/`},
	{"whitespace", `\s+`},
})

var armParser = participle.MustBuild[ArmInst](participle.Lexer(armLexer), participle.Elide("comment", "whitespace"), participle.UseLookahead(100))

type ArmInst struct {
	Pos lexer.Position

	Name string `@Ident`
	Args []*Arg `( @@ ( "," @@ )* )? (Newline*|EOF)`
}

type Arg struct {
	Ma5 *MemArg5   `  @@`
	Ma3 *MemArg3   `| @@`
	Ma2 *MemArg2   `| @@`
	Ma1 *MemArg1   `| @@`
	Ea  *ExtendArg `| @@`
	Na  *NormalArg `| @@`
}

func getAddrMode(a *Arg) AddrMode {
	switch {
	case a.Ma1 != nil:
		return a.Ma1
	case a.Ma2 != nil:
		return a.Ma2
	case a.Ma3 != nil:
		return a.Ma3
	case a.Ma5 != nil:
		return a.Ma5
	}
	panic("unreachable")
}

type ExtendArg struct {
	Op  string  `@("lsl" | "lsr" | "msl" | "asr" | "uxtw" | "sxth" | "sxtw" | "sxtx" | "sxtb" | "uxth" | "uxtb" | "uxtx")`
	Imm *string `  @("#"? Number)?`
}

func (a *ExtendArg) String() string {
	imm := ""
	if a.Imm != nil {
		imm = " " + *a.Imm
	}
	return fmt.Sprintf("%s%s", a.Op, imm)
}

// [Xn{, #i}]
type MemArg1 struct {
	Reg string  `"[" @Ident`
	Imm *string `("," "#"? @(Number))? "]"`
}

func (m *MemArg1) String() string {
	imm := ""
	if m.Imm != nil {
		imm = fmt.Sprintf(", %s", *m.Imm)
	}
	return fmt.Sprintf("[%s%s]", m.Reg, imm)
}

// [Xn], #i
// Xn += i after access
type MemArg2 struct {
	Reg string `"[" @Ident "]"`
	Imm string `"," "#"? @(Number)`
}

func (m *MemArg2) String() string {
	return fmt.Sprintf("[%s], %s", m.Reg, m.Imm)
}

// [Xn, #i]!
// Xn += i before access
type MemArg3 struct {
	Reg string `"[" @Ident`
	Imm string `"," "#"? @(Number) "]" "!"`
}

func (m *MemArg3) String() string {
	return fmt.Sprintf("[%s, %s]!", m.Reg, m.Imm)
}

// [Xn, Wm, {s,u}xtw{ #i|s}]
// [Xn, Xm sxtx{ #i|s}]
type MemArg5 struct {
	Reg1   string     `"[" @Ident`
	Reg2   string     `"," @Ident`
	Extend *ExtendArg `("," @@)? "]"`
}

func (m *MemArg5) String() string {
	ea := ""
	if m.Extend != nil {
		ea = ", " + m.Extend.String()
	}
	return fmt.Sprintf("[%s, %s%s]", m.Reg1, m.Reg2, ea)
}

func (m *MemArg1) SingleReg() bool {
	return true
}
func (m *MemArg2) SingleReg() bool {
	return true
}
func (m *MemArg3) SingleReg() bool {
	return true
}
func (m *MemArg5) SingleReg() bool {
	return false
}
func (m *MemArg1) GetReg() string {
	return m.Reg
}
func (m *MemArg2) GetReg() string {
	return m.Reg
}
func (m *MemArg3) GetReg() string {
	return m.Reg
}
func (m *MemArg5) GetReg() string {
	return m.Reg1
}
func (m *MemArg1) SetReg(r string) {
	m.Reg = r
}
func (m *MemArg2) SetReg(r string) {
	m.Reg = r
}
func (m *MemArg3) SetReg(r string) {
	m.Reg = r
}
func (m *MemArg5) SetReg(r string) {
	m.Reg1 = r
}

type NormalArg struct {
	Name *string `@(Ident ("[" Number "]")?)`
	Imm  *string `| "#"? @Number`
}

func (a *NormalArg) Get() string {
	if a.Name != nil {
		return *a.Name
	} else if a.Imm != nil {
		return *a.Imm
	}
	return ""
}
