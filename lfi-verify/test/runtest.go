package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"runtime"
	"strings"
)

var verbose = flag.Bool("V", false, "verbose")

func fatal(err ...interface{}) {
	fmt.Fprintln(os.Stderr, err...)
	os.Exit(1)
}

var compilers = map[string]string{
	"arm64": "aarch64-none-elf-gcc -march=armv8.1-a+sve -nostdlib -z separate-code %s -o %s",
	"amd64": "x86_64-linux-gnu-gcc -nostdlib -z separate-code %s -o %s",
}

func run(command string, flags ...string) (string, error) {
	buf := &bytes.Buffer{}
	cmd := exec.Command(command, flags...)
	if *verbose {
		fmt.Fprintln(os.Stderr, cmd)
	}
	cmd.Stderr = buf
	cmd.Stdout = buf
	cmd.Stdin = os.Stdin
	err := cmd.Run()
	return buf.String(), err
}

func getflags(test string) string {
	lines := strings.Split(test, "\n")
	for _, l := range lines {
		_, after, found := strings.Cut(l, "// flags:")
		if found {
			return after
		}
	}
	return ""
}

func main() {
	arch := flag.String("arch", runtime.GOARCH, "architecture")
	flag.Parse()
	args := flag.Args()

	if len(args) < 2 {
		fatal("no input")
	}

	if _, ok := compilers[*arch]; !ok {
		fatal("unsupported architecture", *arch)
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
			outtmp, err := os.CreateTemp(os.TempDir(), "lfiout*.elf")
			if err != nil {
				log.Fatal("create output temp: ", err)
			}
			outtmp.Close()
			bin := outtmp.Name()
			out, err := run("sh", "-c", fmt.Sprintf(compilers[*arch], tmp.Name(), bin))
			if err != nil {
				log.Fatal("error compiling:", out)
			}
			flags := getflags(t)
			out, err = run("sh", "-c", fmt.Sprintf("%s -a %s %s %s", lfiverify, *arch, flags, bin))
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
