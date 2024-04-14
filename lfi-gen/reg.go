package main

import "strings"

const (
	resReg     = Reg("x18")
	segmentReg = Reg("x21")
	scratchReg = Reg("x22")
	optReg     = Reg("x23")
	optReg2    = Reg("x24")
	spReg      = Reg("sp")
	retReg     = Reg("x30")
	gasReg     = Reg("x23")
	sysReg     = Reg("x25")
)

var sandboxedreg = map[Reg]bool{
	spReg:  true,
	resReg: true,
}
var rangereg = map[Reg]bool{
	optReg:  true,
	optReg2: true,
}

func sandboxed(r Reg) bool {
	if *opt >= 2 {
		return sandboxedreg[r] || rangereg[r]
	}
	return sandboxedreg[r]
}

var reserved = map[Reg]bool{
	segmentReg: true,
	resReg:     true,
	optReg:     true,
	optReg2:    true,
	scratchReg: true,
}

func hiReg(r Reg) Reg {
	if r == Reg("wsp") {
		return Reg("sp")
	}
	return "x" + r[1:]
}

func loReg(r Reg) Reg {
	if r == Reg("sp") {
		return Reg("wsp")
	}
	return "w" + r[1:]
}

var tempReg = map[Reg]bool{
	"x9":  true,
	"x10": true,
	"x11": true,
	"x12": true,
	"x13": true,
	"x14": true,
	"x15": true,
	"x16": true,
	"x17": true,
	"x18": true,
}

var regs = map[string]bool{
	"x0":  true,
	"x1":  true,
	"x2":  true,
	"x3":  true,
	"x4":  true,
	"x5":  true,
	"x6":  true,
	"x7":  true,
	"x8":  true,
	"x9":  true,
	"x10": true,
	"x11": true,
	"x12": true,
	"x13": true,
	"x14": true,
	"x15": true,
	"x16": true,
	"x17": true,
	"x18": true,
	"x19": true,
	"x20": true,
	"x21": true,
	"x22": true,
	"x23": true,
	"x24": true,
	"x25": true,
	"x26": true,
	"x27": true,
	"x28": true,
	"x29": true,
	"x30": true,
	"x31": true,
	"sp":  true,
	"w0":  true,
	"w1":  true,
	"w2":  true,
	"w3":  true,
	"w4":  true,
	"w5":  true,
	"w6":  true,
	"w7":  true,
	"w8":  true,
	"w9":  true,
	"w10": true,
	"w11": true,
	"w12": true,
	"w13": true,
	"w14": true,
	"w15": true,
	"w16": true,
	"w17": true,
	"w18": true,
	"w19": true,
	"w20": true,
	"w21": true,
	"w22": true,
	"w23": true,
	"w24": true,
	"w25": true,
	"w26": true,
	"w27": true,
	"w28": true,
	"w29": true,
	"w30": true,
	"w31": true,
	"wsp": true,
	"xzr": true,
	"wzr": true,
}

func IsReg(r string) bool {
	if strings.Contains(r, "[") {
		return true
	}
	return regs[r]
}
