package main

import (
	"bytes"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strings"
)

var testflags = map[string][]string{
	"poc.s":          []string{"--poc"},
	"sysexternal.s":  []string{"--sys-external"},
	"storesonly.s":   []string{"--sandbox=stores"},
	"nosegue.s":      []string{"--no-segue"},
	"bundle32.s":     []string{"--cfi=bundle32"},
	"singlethread.s": []string{"--single-thread", "--sandbox=bundle-jumps"},
	"bundlejumps.s":  []string{"--sandbox=bundle-jumps"},
	"decl.s":         []string{"--decl"},
	"meter.s":        []string{"--meter=branch"},
	"variable.s":     []string{"--p2size=variable"},
}

func fatal(err ...interface{}) {
	fmt.Fprintln(os.Stderr, err...)
	os.Exit(1)
}

func run(command string, flags []string, stdin string) (string, error) {
	buf := &bytes.Buffer{}
	cmd := exec.Command(command, flags...)
	cmd.Stderr = os.Stderr
	cmd.Stdout = buf
	cmd.Stdin = strings.NewReader(stdin)
	err := cmd.Run()
	if err != nil {
		return "", err
	}
	return buf.String(), nil
}

func main() {
	arch := flag.String("arch", runtime.GOARCH, "target architecture")

	flag.Parse()
	args := flag.Args()

	if len(args) < 2 {
		fatal("no input")
	}

	lfigen := args[0]
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
		tests := strings.Split(all, "------")

		flags := testflags[filepath.Base(input)]
		flags = append(flags, "-a", *arch)
		for _, t := range tests {
			parts := strings.Split(t, ">>>")
			parts[1] = strings.TrimSpace(parts[1])
			out, err := run(lfigen, flags, parts[0])
			if err != nil {
				fmt.Fprintf(os.Stderr, "TEST %d (%s) FAIL:\n", ntest, input)
				fmt.Println(parts[0])
				failed++
				continue
			}
			out = strings.TrimSpace(out)
			if out != parts[1] {
				fmt.Fprintf(os.Stderr, "TEST %d (%s) FAIL:\n", ntest, input)
				fmt.Println(parts[0])
				fmt.Fprintln(os.Stderr, "GOT:")
				fmt.Fprintln(os.Stderr, out)
				failed++
			} else {
				passed++
			}
			ntest++
		}
	}

	if failed > 0 {
		fmt.Fprintf(os.Stderr, "%s: FAILED: %d\n", *arch, failed)
		os.Exit(1)
	}
	fmt.Fprintf(os.Stderr, "%s: PASSED %d test cases\n", *arch, passed)
}
