package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"strings"

	"github.com/alecthomas/repr"
	"github.com/spf13/pflag"
)

const (
	resReg     = "x20"
	segmentReg = "x21"
)

func loReg(r string) string {
	return "w" + r[1:]
}

func parseInst(in string, loc string) Inst {
	in = strings.TrimSpace(in)
	if strings.HasSuffix(in, ":") {
		return &Label{
			Name: in[:len(in)-1],
		}
	}
	if strings.HasPrefix(in, ".") || strings.HasPrefix(in, "#") || strings.HasPrefix(in, "\\") {
		return &Directive{
			Val: in,
		}
	}

	fields := strings.Fields(in)
	if len(fields) <= 0 {
		return &Opaque{
			Val: in,
		}
	}

	switch fields[0] {
	case "umov", "ins":
		return &Opaque{
			Val: in,
		}
	}

	ast, err := armParser.Parse(loc, strings.NewReader(in))
	if err != nil {
		return &Opaque{
			Val: in,
		}
	}

	switch ast.Name {
	case "br", "blr", "bl":
		return &Branch{
			Op:     ast.Name,
			Target: ast.Args[0].Na.Get(),
		}
	case "ldp", "ldpsw":
		return &LoadM{
			Op:    ast.Name,
			DestA: *ast.Args[0].Na.Name,
			DestB: *ast.Args[1].Na.Name,
			Addr:  getAddrMode(ast.Args[2]),
		}
	case "ldr", "ldur", "ldrb", "ldrh", "ldrub", "ldruh", "ldrsw", "ldursw", "ldrs", "ldurs", "ldrsb", "ldrsh", "ldrusb", "ldrush":
		return &Load{
			Op:   ast.Name,
			Dest: *ast.Args[0].Na.Name,
			Addr: getAddrMode(ast.Args[1]),
		}
	case "stp":
		return &StoreM{
			Op:   ast.Name,
			SrcA: *ast.Args[0].Na.Name,
			SrcB: *ast.Args[1].Na.Name,
			Addr: getAddrMode(ast.Args[2]),
		}
	case "str", "stur", "strb", "strh", "sturb", "sturh":
		return &Store{
			Op:   ast.Name,
			Src:  *ast.Args[0].Na.Name,
			Addr: getAddrMode(ast.Args[1]),
		}
	case "add", "sub", "and", "orr":
		if len(ast.Args) == 4 {
			srcc := ""
			if ast.Args[3].Ea != nil {
				srcc = ast.Args[3].Ea.String()
			} else {
				srcc = ast.Args[3].Na.Get()
			}
			return &Modify4{
				Op:   ast.Name,
				Dest: ast.Args[0].Na.Get(),
				SrcA: ast.Args[1].Na.Get(),
				SrcB: ast.Args[2].Na.Get(),
				SrcC: srcc,
			}
		}
		return &Modify3{
			Op:   ast.Name,
			Dest: ast.Args[0].Na.Get(),
			SrcA: ast.Args[1].Na.Get(),
			SrcB: ast.Args[2].Na.Get(),
		}
	}

	return &Opaque{
		Val: in,
	}
}

func parseInsts(in io.Reader, name string) ([]Inst, error) {
	var insts []Inst
	scanner := bufio.NewScanner(in)
	line := 1
	for scanner.Scan() {
		insts = append(insts, parseInst(scanner.Text(), fmt.Sprintf("%s:%d", name, line)))
		line++
	}
	return insts, scanner.Err()
}

func main() {
	showstat := pflag.BoolP("stats", "s", false, "show stats")
	out := pflag.StringP("output", "o", "", "output assembly file")
	dotest := pflag.BoolP("test", "t", false, "test")

	pflag.Parse()
	args := pflag.Args()

	if *dotest {
		test()
		return
	}

	var in io.Reader
	var name string
	if len(args) == 0 {
		in = os.Stdin
		name = "stdin"
	} else {
		f, err := os.Open(args[0])
		if err != nil {
			log.Fatal(err)
		}
		in = f
		name = args[0]
		defer f.Close()
	}

	insts, err := parseInsts(in, name)
	if err != nil {
		log.Fatal(err)
	}

	insts = branchPass(insts)
	insts = specialRegPass(insts)
	insts = fixAddrModesPass(insts)
	insts = memoryPass(insts)

	var w io.Writer
	if *out != "" {
		f, err := os.Create(*out)
		if err != nil {
			log.Fatal(err)
		}
		w = f
		defer f.Close()
	} else {
		w = os.Stdout
	}

	for _, inst := range insts {
		fmt.Fprintln(w, inst.String())
	}

	if *showstat {
		fmt.Fprint(os.Stderr, stats)
	}
}

func test() {
	ast, err := armParser.Parse("stdin", os.Stdin)
	if err != nil {
		log.Fatal(err)
	}
	repr.Println(ast)
}
