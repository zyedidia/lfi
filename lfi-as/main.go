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

func fatal(err ...interface{}) {
	fmt.Fprintln(os.Stderr, err...)
	os.Exit(1)
}

func run(command string, args ...string) {
	cmd := exec.Command(command, args...)
	log.Println(cmd)
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	cmd.Stdin = os.Stdin
	err := cmd.Run()
	if err != nil {
		fatal(err)
	}
}

var temps []string

func temp(dir string) string {
	tmp, err := os.CreateTemp(dir, ".lfi.*.s")
	if err != nil {
		fatal(err)
	}
	tmp.Close()
	temps = append(temps, tmp.Name())
	return tmp.Name()
}

func main() {
	var in, out string
	var args, lfiflags []string
	var keep, verbose bool
	verbose = true

	as := filepath.Base(os.Args[0])

	for i := 1; i < len(os.Args); i++ {
		arg := os.Args[i]
		switch arg {
		case "-o":
			if i+1 >= len(os.Args) {
				fatal("-o needs an argument")
			}
			out = os.Args[i+1]
			i++
		case "-V":
			verbose = true
		case "-K":
			keep = true
		default:
			switch {
			case strings.HasSuffix(arg, ".s"), strings.HasSuffix(arg, ".S"):
				in = arg
			default:
				if strings.HasPrefix(arg, "-flfi") {
					lfiflags = append(lfiflags, arg[len("-flfi"):])
				}
				args = append(args, arg)
			}
		}
	}

	if verbose {
		log.SetOutput(os.Stderr)
	} else {
		log.SetOutput(io.Discard)
	}

	asmmc := temp(os.TempDir())
	run("llvm-mc", "-arch=aarch64", "-filetype=asm", "-o", asmmc, in)
	lfi := temp(os.TempDir())
	lfiflags = append(lfiflags, "-o", lfi, asmmc)
	run("lfi-gen", lfiflags...)

	asflags := []string{
		"-o", out,
		lfi,
	}
	asflags = append(asflags, args...)
	run(as, asflags...)

	if !keep {
		for _, t := range temps {
			os.Remove(t)
		}
	}
}
