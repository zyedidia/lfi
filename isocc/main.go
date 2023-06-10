package main

import (
	"fmt"
	"io"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

var isoflags = []string{"-ffixed-x20", "-ffixed-x21"}

func fatal(err ...interface{}) {
	fmt.Fprintln(os.Stderr, err...)
	os.Exit(1)
}

func run(command string, args ...string) {
	cmd := exec.Command(command, args...)
	log.Println(cmd)
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	err := cmd.Run()
	if err != nil {
		fatal(err)
	}
}

func temp(dir string) string {
	tmp, err := os.CreateTemp(dir, ".isocc.*.s")
	if err != nil {
		fatal(err)
	}
	tmp.Close()
	return tmp.Name()
}

func main() {
	var out, target string
	var compile, assemble, verbose, keep bool
	var args []string
	for i := 1; i < len(os.Args); i++ {
		arg := os.Args[i]
		switch arg {
		case "-o":
			if i+1 >= len(os.Args) {
				fatal("-o needs an argument")
			}
			out = os.Args[i+1]
			i++
		case "-c":
			compile = true
		case "-S":
			assemble = true
		case "-V":
			verbose = true
		case "-K":
			keep = true
		default:
			switch {
			case strings.HasSuffix(arg, ".s"), strings.HasSuffix(arg, ".S"),
				strings.HasSuffix(arg, ".o"), strings.HasSuffix(arg, ".c"):
				target = arg
			default:
				args = append(args, arg)
			}
		}
	}

	base := strings.TrimSuffix(target, filepath.Ext(target))
	targetasm := base + ".s"
	targeto := base + ".o"
	targetdir := filepath.Dir(target)

	cc := os.Getenv("ISOCC")
	if cc == "" {
		cc = "aarch64-none-elf-gcc"
	}

	if verbose {
		log.SetOutput(os.Stdout)
		log.SetFlags(0)
	} else {
		log.SetOutput(io.Discard)
	}

	asm := target
	if filepath.Ext(target) == ".S" {
		asm = temp(targetdir)
		run("cpp", "-o", asm, target)
		if !keep {
			defer os.Remove(asm)
		}
	} else if filepath.Ext(target) != ".s" {
		asm = temp(targetdir)
		stage1 := []string{
			"-S",
			"-o", asm,
			target,
		}
		stage1 = append(stage1, args...)
		stage1 = append(stage1, isoflags...)

		run(cc, stage1...)

		if !keep {
			defer os.Remove(asm)
		}
	}

	iso := temp(targetdir)
	if !keep {
		defer os.Remove(iso)
	}
	// run("cp", asm, iso)
	run("isogen", asm, "-o", iso)

	if !assemble {
		if compile && out == "" {
			out = targeto
		} else if !compile && out == "" {
			out = "a.out"
		}

		stage2 := []string{
			"-o", out,
			iso,
		}
		if compile {
			stage2 = append(stage2, "-c")
		}
		stage2 = append(stage2, args...)
		stage2 = append(stage2, isoflags...)
		run(cc, stage2...)
	} else {
		run("cp", iso, targetasm)
	}
}
