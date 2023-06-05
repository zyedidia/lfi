package main

import (
	"fmt"
	"io"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"

	"github.com/kballard/go-shellquote"
	"github.com/spf13/pflag"
)

var isoflags = []string{"-ffixed-x20", "-ffixed-x21", "-falign-labels=8", "-falign-jumps=8", "-falign-functions=8"}

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

func temp() string {
	tmp, err := os.CreateTemp("", "isocc.*.S")
	if err != nil {
		fatal(err)
	}
	tmp.Close()
	return tmp.Name()
}

func addFlags(flags []string, prefix string, values *[]string) []string {
	if values == nil {
		return flags
	}
	for _, val := range *values {
		flags = append(flags, prefix+val)
	}
	return flags
}

func main() {
	xcc := pflag.String("Xcc", "", "extra c compiler flags")
	defines := pflag.StringSliceP("define", "D", nil, "defines")
	includes := pflag.StringSliceP("include", "I", nil, "includes")
	opt := pflag.StringP("opt", "O", "0", "optimization level")
	debug := pflag.BoolP("debug", "g", false, "include debugging information")
	out := pflag.StringP("output", "o", "a.out", "output file")
	compile := pflag.BoolP("emit-obj", "c", false, "compile but do not link")
	assemble := pflag.BoolP("emit-asm", "S", false, "emit assembly code")
	verbose := pflag.BoolP("verbose", "V", false, "verbose information")
	keep := pflag.Bool("keep", false, "do not remove temporary files")
	fflag := pflag.StringSliceP("f", "f", nil, "-f flags passed to gcc")
	mflag := pflag.StringSliceP("m", "m", nil, "-m flags passed to gcc")
	idirafterflag := pflag.StringSlice("idirafter", nil, "-idirafter flags passed to gcc")
	pflag.Parse()
	args := pflag.Args()

	if len(args) < 1 {
		fmt.Println("no input provided")
		fmt.Println("Usage of isocc:")
		fmt.Println("  isocc [OPTIONS] FILE")
		fmt.Println()
		pflag.PrintDefaults()
		os.Exit(0)
	}

	target := args[0]
	base := strings.TrimSuffix(target, filepath.Ext(target))
	targetasm := base + ".S"
	targeto := base + ".o"
	*includes = append(*includes, filepath.Dir(target))

	cc := os.Getenv("ISOCC")
	if cc == "" {
		cc = "aarch64-none-elf-gcc"
	}

	if *verbose {
		log.SetOutput(os.Stdout)
		log.SetFlags(0)
	} else {
		log.SetOutput(io.Discard)
	}

	extra, err := shellquote.Split(*xcc)
	if err != nil {
		fatal(err)
	}

	// TODO: pass the flags directly and just look for files ending in .S, .o, or .c for the input (excluding ones that come after -o)
	// TODO: put the temp file in the same directory as the target
	// TODO: in parser, skip lines beginning with # or \ (make them opaque or directives or something)

	asm := target
	if filepath.Ext(target) != ".s" && filepath.Ext(target) != ".S" {
		asm = temp()
		stage1 := []string{
			"-S",
			"-o", asm,
			"-O" + *opt,
		}
		stage1 = addFlags(stage1, "-I", includes)
		stage1 = addFlags(stage1, "-D", defines)
		stage1 = addFlags(stage1, "-f", fflag)
		stage1 = addFlags(stage1, "-m", mflag)
		stage1 = addFlags(stage1, "-idirafter", idirafterflag)
		if *debug {
			stage1 = append(stage1, "-g")
		}
		stage1 = append(stage1, extra...)
		stage1 = append(stage1, isoflags...)
		stage1 = append(stage1, args...)

		run(cc, stage1...)

		if !*keep {
			defer os.Remove(asm)
		}
	}

	iso := temp()
	if !*keep {
		defer os.Remove(iso)
	}
	run("cp", asm, iso)
	// run("isogen", asm, "-o", iso)

	if !*assemble {
		if *compile && *out == "" {
			*out = targeto
		}

		stage2 := []string{
			"-o", *out,
			"-O" + *opt,
			iso,
		}
		if *debug {
			stage2 = append(stage2, "-g")
		}
		if *compile {
			stage2 = append(stage2, "-c")
		}
		stage2 = addFlags(stage2, "-I", includes)
		stage2 = addFlags(stage2, "-D", defines)
		stage2 = addFlags(stage2, "-f", fflag)
		stage2 = addFlags(stage2, "-m", mflag)
		stage2 = addFlags(stage2, "-idirafter", idirafterflag)
		stage2 = append(stage2, extra...)
		run(cc, stage2...)
	} else {
		run("cp", iso, targetasm)
	}
}
