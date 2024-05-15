package main

import (
	"bytes"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"strings"
)

func fatal(err ...interface{}) {
	fmt.Fprintln(os.Stderr, err...)
	os.Exit(1)
}

func run(command, stdin string) (string, error) {
	buf := &bytes.Buffer{}
	cmd := exec.Command(command)
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

		for _, t := range tests {
			parts := strings.Split(t, ">>>")
			parts[1] = strings.TrimSpace(parts[1])
			out, err := run(lfigen, parts[0])
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
		fmt.Fprintf(os.Stderr, "FAILED: %d\n", failed)
		os.Exit(1)
	}
	fmt.Fprintf(os.Stderr, "PASSED: %d\n", passed)
}
