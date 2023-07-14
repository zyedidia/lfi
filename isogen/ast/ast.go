package ast

import (
	"io"

	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/participle/v2/lexer"
)

var lex = lexer.MustSimple([]lexer.SimpleRule{
	{`Ident`, `[_@.a-zA-Z][a-zA-Z_\d@.+\d]*`},
	{`Number`, `[-+]?(0x)?[0-9a-fA-F.+\-]+\b`},
	{`Punct`, `[{},:()\[\]#!+\-]`},
	{`Newline`, `\r?\n`},
	{"comment", `//.*|/\*.*?\*/|;.*`},
	{"whitespace", `\s+`},
})

var parser = participle.MustBuild[Inst](participle.Lexer(lex), participle.Elide("comment", "whitespace"), participle.UseLookahead(10))

type Inst struct {
	Pos lexer.Position

	Label *string `(@(Ident | Number) ':')?`
	Name  string  `@Ident`
	Args  []*Arg  `( @@ ( "," @@ )* )? (Newline*|EOF)`
}

type Arg struct {
	Mem4       *MemAddr4   `  @@`
	Mem3       *MemAddr3   `| @@`
	Mem2       *MemAddr2   `| @@`
	Mem1       *MemAddr1   `| @@`
	Vector     *Vector     `| @@`
	Extend     *ExtendArg  `| @@`
	RegOrLabel *RegOrLabel `| @@`
	Imm        *Imm        `| @@`
}

// Vector structure {v1.h, v2.h}
type Vector struct {
	Vals    []*RegOrLabel `"{" @@ ( "," @@ )* "}"`
	Indexed *string       `@('[' Number ']')?`
}

// [Xn{, #i}]
type MemAddr1 struct {
	Reg string `"[" @Ident`
	Imm *Imm   `("," @@)? "]"`
}

// [Xn], #i
// Xn += i after access
type MemAddr2 struct {
	Reg string `"[" @Ident "]"`
	Imm string `"," "#"? @(Number)`
}

// [Xn, #i]!
// Xn += i before access
type MemAddr3 struct {
	Reg string `"[" @Ident`
	Imm string `"," "#"? @(Number) "]" "!"`
}

// [Xn, Wm, {s,u}xtw{ #i|s}]
// [Xn, Xm sxtx{ #i|s}]
type MemAddr4 struct {
	Reg1   string     `"[" @Ident`
	Reg2   string     `"," @Ident`
	Extend *ExtendArg `("," @@)? "]"`
}

type ExtendArg struct {
	Op  string  `@("lsl" | "lsr" | "msl" | "asr" | "ror" | "uxtw" | "sxth" | "sxtw" | "sxtx" | "sxtb" | "uxth" | "uxtb" | "uxtx")`
	Imm *string `('#'? @((Number | '-' | '+' | '(' | ')')+))?`
}

type Imm struct {
	Num   *string `('#'? @((Number | '-' | '+' | '(' | ')')+))`
	Reloc *Reloc  `| @@`
}

type Reloc struct {
	Type string `'#'? ':' @Ident ':'`
	Var  string `@Ident`
}

type RegOrLabel struct {
	Indexed *string `@(Ident '[' Number ']')`
	Val     *string `| @Ident`
}

func Parse(name string, r io.Reader) (*Inst, error) {
	return parser.Parse(name, r)
}
