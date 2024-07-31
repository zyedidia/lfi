package main

import (
	"bytes"
	"flag"
	"fmt"
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

func run(command string, flags ...string) (string, error) {
	buf := &bytes.Buffer{}
	cmd := exec.Command(command, flags...)
	cmd.Stderr = buf
	cmd.Stdout = buf
	cmd.Stdin = os.Stdin
	err := cmd.Run()
	return buf.String(), err
}

func main() {
	flag.Parse()
	args := flag.Args()

	if len(args) < 2 {
		fatal("no input")
	}

	lfiverify := args[0]
	inputs := args[1:]

	failed := 0
	passed := 0
	ntest := 0
	for _, input := range inputs {
		data, err := os.ReadFile(input)
		if err != nil {
			fatal(err)
		}

		all := string(data)
		tests := strings.Split(all, "---")

		for _, t := range tests {
			tmp, err := os.CreateTemp(os.TempDir(), "lfitest*.s")
			if err != nil {
				log.Fatal("create temp: ", err)
			}
			asmdata := fmt.Sprintf(".globl _start\n_start:\n%s", t)
			tmp.WriteString(asmdata)
			tmp.Close()
			bin := filepath.Join(os.TempDir(), "out.elf")
			out, err := run("aarch64-linux-gnu-gcc", "-march=armv8.1-a", "-nostdlib", "-z", "separate-code", tmp.Name(), "-o", bin)
			if err != nil {
				log.Fatal("error compiling:", out)
			}
			out, err = run(lfiverify, bin)
			var success bool
			if strings.Contains(input, "fail") {
				success = err != nil
			} else {
				success = err == nil
			}
			if !success {
				fmt.Fprintf(os.Stderr, "TEST %d (%s) FAIL:\n", ntest, input)
				fmt.Println(t)
				fmt.Println("output:", out)
				failed++
			} else {
				passed++
			}
			os.Remove(tmp.Name())
			os.Remove(bin)
			ntest++
		}
	}

	if failed > 0 {
		fmt.Fprintf(os.Stderr, "FAILED: %d\n", failed)
		os.Exit(1)
	}
	fmt.Fprintf(os.Stderr, "PASSED %d test cases\n", passed)
}
