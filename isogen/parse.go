package main

import (
	"bufio"
	"fmt"
	"io"
	"strings"

	"github.com/zyedidia/isolator/isogen/ast"
)

func getImm(imm *ast.Imm) Imm {
	if imm.Num != nil {
		return Number(*imm.Num)
	} else {
		return Reloc{
			Type: imm.Reloc.Type,
			Var:  imm.Reloc.Var,
		}
	}
}

func ParseInst(line string, loc string) (*Label, *Inst, error) {
	ast, err := ast.Parse(loc, strings.NewReader(line))
	if err != nil {
		return nil, nil, err
	}
	var label *Label
	if ast.Label != nil {
		l := Label(*ast.Label)
		label = &l
	}
	inst := &Inst{
		Name: ast.Name,
	}
	for _, arg := range ast.Args {
		if arg.Mem1 != nil {
			var imm Imm = nil
			if arg.Mem1.Imm != nil {
				imm = getImm(arg.Mem1.Imm)
			}
			inst.Args = append(inst.Args, MemAddr{
				Reg: Reg(arg.Mem1.Reg),
				Imm: imm,
			})
		} else if arg.Mem2 != nil {
			inst.Args = append(inst.Args, MemAddrPost{
				Reg: Reg(arg.Mem2.Reg),
				Imm: arg.Mem2.Imm,
			})
		} else if arg.Mem3 != nil {
			inst.Args = append(inst.Args, MemAddrPre{
				Reg: Reg(arg.Mem3.Reg),
				Imm: arg.Mem3.Imm,
			})
		} else if arg.Mem4 != nil {
			var ex *Extend = nil
			if arg.Mem4.Extend != nil {
				ex = &Extend{
					Op:  arg.Mem4.Extend.Op,
					Imm: arg.Mem4.Extend.Imm,
				}
			}
			inst.Args = append(inst.Args, MemAddrComplex{
				Reg1:   Reg(arg.Mem4.Reg1),
				Reg2:   Reg(arg.Mem4.Reg2),
				Extend: ex,
			})
		} else if arg.Extend != nil {
			inst.Args = append(inst.Args, Extend{
				Op:  arg.Extend.Op,
				Imm: arg.Extend.Imm,
			})
		} else if arg.Vector != nil {
			v := Vector{}
			for _, r := range arg.Vector.Vals {
				if r.Val != nil {
					v.Vals = append(v.Vals, Reg(*r.Val))
				} else {
					v.Vals = append(v.Vals, Reg(*r.Indexed))
				}
			}
			v.Indexed = arg.Vector.Indexed
			inst.Args = append(inst.Args, v)
		} else if arg.RegOrLabel != nil {
			if arg.RegOrLabel.Val != nil {
				if IsReg(*arg.RegOrLabel.Val) {
					inst.Args = append(inst.Args, Reg(*arg.RegOrLabel.Val))
				} else {
					inst.Args = append(inst.Args, Label(*arg.RegOrLabel.Val))
				}
			} else {
				inst.Args = append(inst.Args, Reg(*arg.RegOrLabel.Indexed))
			}
		} else if arg.Imm != nil {
			inst.Args = append(inst.Args, getImm(arg.Imm))
		}
	}
	return label, inst, nil
}

func ParseOp(list *OpList, line string, loc string) error {
	if strings.HasSuffix(line, ":") {
		list.PushBack(NewNode(Label(line[:len(line)-1])))
		return nil
	}
	if strings.HasPrefix(line, ".") {
		list.PushBack(NewNode(Directive{
			Val: line,
		}))
		return nil
	}
	if strings.HasPrefix(line, "#") || strings.HasPrefix(line, "\\") {
		list.PushBack(NewNode(Unknown(line)))
		return nil
	}

	label, inst, err := ParseInst(line, loc)
	if err != nil {
		return err
	}
	if label != nil {
		list.PushBack(NewNode(*label))
	}
	list.PushBack(NewNode(inst))
	return nil
}

func ParseFile(in io.Reader, name string) (*OpList, error) {
	var list OpList
	scanner := bufio.NewScanner(in)
	buf := make([]byte, 0, 64*1024)
	scanner.Buffer(buf, 1024*1024)
	n := 1
	for scanner.Scan() {
		// TODO: this is hacky
		line := scanner.Text()
		if !strings.Contains(line, "\"") {
			before, _, _ := strings.Cut(scanner.Text(), "//")
			line = strings.TrimSpace(before)
		} else {
			line = strings.TrimSpace(line)
		}
		if line == "" || strings.HasPrefix(line, "//") {
			n++
			continue
		}
		err := ParseOp(&list, line, fmt.Sprintf("%s:%d", name, n))
		if err != nil {
			return nil, fmt.Errorf("%s:%d: %w", name, n, err)
		}
		n++
	}
	return &list, scanner.Err()
}
