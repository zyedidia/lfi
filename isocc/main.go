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

var isoflags = []string{"-mllvm", "--aarch64-enable-compress-jump-tables=false", "-ffixed-x15", "-ffixed-x21", "-ffixed-x22", "-ffixed-x14", "-ffixed-x24", "-ffixed-x30", "-fuse-ld=lld"}

// var isoflags = []string{"-mllvm", "--aarch64-enable-compress-jump-tables=false", "-target", "aarch64-linux-gnu", "-ffixed-x15", "-ffixed-x21", "-ffixed-x22", "-ffixed-x14", "-ffixed-x24", "-ffixed-x30"}

// var isoflags = []string{"-ffixed-x22"}

// var isoflags = []string{}

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
	var compile, assemble, verbose, keep, lto bool
	var args, objs []string
	for i := 1; i < len(os.Args); i++ {
		arg := os.Args[i]
		switch arg {
		case "-flto", "-flto=full", "-flto=thin":
			lto = true
			args = append(args, arg)
		case "-MT":
			args = append(args, arg)
			if i+1 >= len(os.Args) {
				fatal("-MT needs an argument")
			}
			args = append(args, os.Args[i+1])
			i++
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
			case strings.HasSuffix(arg, ".s"), strings.HasSuffix(arg, ".S"), strings.HasSuffix(arg, ".c"):
				target = arg
			case strings.HasSuffix(arg, ".o"):
				objs = append(objs, arg)
			default:
				args = append(args, arg)
			}
		}
	}

	cc := os.Getenv("ISOCC")
	if cc == "" {
		cc = "clang"
	}

	if target == "" {
		var oldout string
		if lto {
			oldout = out
			out = temp(os.TempDir())
		} else if out == "" {
			out = "a.out"
		}
		all := []string{
			"-o", out,
		}
		all = append(all, objs...)
		all = append(all, args...)
		all = append(all, isoflags...)
		if !lto {
			run(cc, all...)
			return
		}
		all = append(all, "-Wl,--lto-emit-asm", "-Wl,-plugin-opt=--aarch64-enable-compress-jump-tables=false")
		run(cc, all...)
		target = out
		out = oldout
	}

	base := strings.TrimSuffix(target, filepath.Ext(target))
	targetasm := base + ".s"
	targeto := base + ".o"
	targetdir := filepath.Dir(target)

	if verbose {
		log.SetOutput(os.Stdout)
		log.SetFlags(0)
	} else {
		log.SetOutput(io.Discard)
	}

	asm := target
	if lto && compile {
		out = targeto

		flags := []string{
			"-c",
			"-o", out,
			target,
			"-Wno-unused-command-line-argument",
		}
		flags = append(flags, args...)
		flags = append(flags, isoflags...)
		run(cc, flags...)
		return
	} else if filepath.Ext(target) == ".S" {
		asm = temp(targetdir)
		stage1 := []string{
			"-E",
			"-o", asm,
			target,
		}
		stage1 = append(stage1, args...)
		stage1 = append(stage1, isoflags...)

		run(cc, stage1...)

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

	asmmc := temp(targetdir)
	run("llvm-mc", "-arch=aarch64", "-filetype=asm", "-o", asmmc, asm)
	// run("cp", asm, asmmc)

	iso := temp(targetdir)
	if !keep {
		defer os.Remove(iso)
	}
	// run("cp", asmmc, iso)
	// run("isogen", asmmc, "-o", iso, "-S", "/tmp/isocc.stats")
	run("isogen", asmmc, "-o", iso)

	if !assemble {
		if compile && out == "" {
			out = targeto
		} else if !compile && out == "" {
			out = "a.out"
		}

		stage2 := []string{
			"-o", out,
			iso,
			"-Wno-unused-command-line-argument",
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
