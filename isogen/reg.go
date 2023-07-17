package main

import "strings"

const (
	resReg     = Reg("x15")
	segmentReg = Reg("x21")
	syscallReg = Reg("x22")
	scratchReg = Reg("x14")
	optReg     = Reg("x24")
	optReg2    = Reg("x23")
	spReg      = Reg("sp")
)

var sandboxed = map[Reg]bool{
	spReg:   true,
	resReg:  true,
	optReg:  true,
	optReg2: true,
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
}

func IsReg(r string) bool {
	if strings.Contains(r, "[") {
		return true
	}
	return regs[r]
}
