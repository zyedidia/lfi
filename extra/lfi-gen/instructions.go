package main

var basicloads = map[string]bool{
	"ldr":    true,
	"ldrb":   true,
	"ldrh":   true,
	"ldrub":  true,
	"ldruh":  true,
	"ldrsw":  true,
	"ldrs":   true,
	"ldrsb":  true,
	"ldrsh":  true,
	"ldrusb": true,
	"ldrush": true,
	"prfm":   true,
}

var basicstores = map[string]bool{
	"str":  true,
	"strb": true,
	"strh": true,
}

var loads = map[string]bool{
	"ldr":    true,
	"ldur":   true,
	"ldrb":   true,
	"ldrh":   true,
	"ldrub":  true,
	"ldruh":  true,
	"ldrsw":  true,
	"ldursw": true,
	"ldrs":   true,
	"ldurs":  true,
	"ldrsb":  true,
	"ldrsh":  true,
	"ldrusb": true,
	"ldrush": true,
	"ldurh":  true,
	"ldurb":  true,
	"ldursh": true,
	"ldursb": true,

	"ldar":   true,
	"ldxr":   true,
	"ldaxr":  true,
	"ldarb":  true,
	"ldxrb":  true,
	"ldaxrb": true,
	"ldarh":  true,
	"ldxrh":  true,
	"ldaxrh": true,
	"ldtr":   true,
	"ldtrb":  true,
	"ldtrh":  true,
	"ldtrs":  true,
	"ldtrsb": true,
	"ldtrsh": true,
	"ldtrsw": true,

	"ld1":  true,
	"ld1r": true,
	"ld2":  true,
	"ld3":  true,
	"ld4":  true,

	"prfm":  true,
	"prfum": true,
}

var calls = map[string]bool{
	"blr": true,
	"bl":  true,
}

var stores = map[string]bool{
	"str":   true,
	"stur":  true,
	"strb":  true,
	"strh":  true,
	"sturb": true,
	"sturh": true,

	"sttr":  true,
	"sttrb": true,
	"sttrh": true,
	"stlr":  true,
	"stlrb": true,
	"stlrh": true,

	"st1": true,
	"st2": true,
	"st3": true,
	"st4": true,
}

var exstores = map[string]bool{
	"stxr":   true,
	"stlxr":  true,
	"stxrb":  true,
	"stlxrb": true,
	"stxrh":  true,
	"stlxrh": true,
}

var multiexstores = map[string]bool{
	"stxp":  true,
	"stlxp": true,
}

var multiloads = map[string]bool{
	"ldp":   true,
	"ldpsw": true,
	"ldnp":  true,

	"ldxp":  true,
	"ldaxp": true,
}

var multistores = map[string]bool{
	"stp":  true,
	"stnp": true,
}

var indbranches = map[string]bool{
	"blr": true,
	"br":  true,
	"ret": true,
}

var branches = map[string]bool{
	"b":    true,
	"b.eq": true,
	"b.ne": true,
	"b.cs": true,
	"b.hs": true,
	"b.cc": true,
	"b.lo": true,
	"b.mi": true,
	"b.pl": true,
	"b.vs": true,
	"b.vc": true,
	"b.hi": true,
	"b.ls": true,
	"b.ge": true,
	"b.lt": true,
	"b.gt": true,
	"b.le": true,
	"b.al": true,
	"bl":   true,
	"blr":  true,
	"br":   true,
	"ret":  true,
	"cbnz": true,
	"cbz":  true,
	"tbnz": true,
	"tbz":  true,
}

func IsStore(op Op) bool {
	if i, ok := op.(*Inst); ok {
		return stores[i.Name] || multistores[i.Name] || multiexstores[i.Name] || exstores[i.Name]
	}
	return false
}

func IsBranch(op Op) bool {
	if i, ok := op.(*Inst); ok {
		return branches[i.Name]
	}
	return false
}

func IsIndirectBranch(op Op) bool {
	if i, ok := op.(*Inst); ok {
		return indbranches[i.Name]
	}
	return false
}

func IsDirectBranch(op Op) bool {
	if i, ok := op.(*Inst); ok {
		return branches[i.Name] && !indbranches[i.Name]
	}
	return false
}

func IsLFISyscall(op Op) bool {
	if i, ok := op.(*Inst); ok {
		return i.Name == "blr" && i.Args[0].(Reg) == retReg
	}
	return false
}
