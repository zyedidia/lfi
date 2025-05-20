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
	"arm64": "clang -fuse-ld=lld -target aarch64-linux -march=armv8.1-a+sve -nostdlib -z separate-code %s -o %s",
	"amd64": "clang -fuse-ld=lld -target x86_64-linux -nostdlib -z separate-code %s -o %s",
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
	input := args[1]

	failed := 0
	passed := 0
	ntest := 0

	data, err := os.ReadFile(input)
	if err != nil {
		fatal(err)
	}

	all := string(data)
	tests := strings.Split(all, "---")

	fmt.Printf("1..%d\n", len(tests))
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
			fmt.Printf("not ok %d\n", ntest+1)
			fmt.Fprintln(os.Stderr, asmdata)
			fmt.Fprintf(os.Stderr, "error compiling: %s\n", out)
			continue
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
			fmt.Printf("not ok %d\n", ntest+1)
			fmt.Fprintf(os.Stderr, "%s\n>>>\n%s", t, out)
			fmt.Fprintf(os.Stderr, ">>> (input)\n%s", asmdata)
			failed++
		} else {
			fmt.Printf("ok %d\n", ntest+1)
			passed++
		}
		if !*verbose {
			os.Remove(tmp.Name())
			os.Remove(bin)
		}
		ntest++
	}
}
