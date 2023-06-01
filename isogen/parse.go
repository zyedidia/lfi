package main

import (
	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/participle/v2/lexer"
)

var armLexer = lexer.MustSimple([]lexer.SimpleRule{
	{`Lsl`, `lsl`},
	{`Ident`, `[_@.a-zA-Z][a-zA-Z_\d]*`},
	{`Number`, `[-+]?(0x)?[0-9a-fA-F]+\b`},
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
	Ma3 *MemArg3   `  @@`
	Ma2 *MemArg2   `| @@`
	Ma1 *MemArg1   `| @@`
	Ma4 *MemArg4   `| @@`
	Ma5 *MemArg5   `| @@`
	Na  *NormalArg `| @@`
}

// [Xn{, #i}]
type MemArg1 struct {
	Reg string  `"[" @Ident`
	Imm *string `("," "#" @Number)? "]"`
}

// [Xn], #i
type MemArg2 struct {
	Reg string `"[" @Ident "]"`
	Imm string `"," "#" @Number`
}

// [Xn, #i]!
type MemArg3 struct {
	Reg string `"[" @Ident`
	Imm string `"," "#" @Number "]" "!"`
}

// [Xn, Xm{, lsl #i|s}]
type MemArg4 struct {
	Reg1  string  `"[" @Ident`
	Reg2  string  `"," @Ident`
	Shift *string `("," Lsl @("#"? Number))? "]"`
}

// [Xn, Wm, {s,u}xtw{ #i|s}]
// [Xn, Xm sxtx{ #i|s}]
type MemArg5 struct {
	Reg1 string  `"[" @Ident`
	Reg2 string  `"," @Ident`
	Op   string  `"," @Ident`
	Imm  *string `@("#"? Number)? "]"`
}

type NormalArg struct {
	Name *string `@Ident`
	Imm  *string `| "#"? @Number`
}
