package main

import (
	"bytes"
	"fmt"
	"os"
	"os/exec"
)

func fatal(err ...interface{}) {
	fmt.Fprintln(os.Stderr, err...)
	os.Exit(1)
}

func run(command string, flags ...string) string {
	buf := &bytes.Buffer{}
	cmd := exec.Command(command, flags...)
	cmd.Stdout = buf
	cmd.Stdin = os.Stdin
	err := cmd.Run()
	if err != nil {
		fatal(err)
	}
	return buf.String()
}

func main() {
	args := os.Args

	expected, err := os.ReadFile(args[1])
	if err != nil {
		fatal(err)
	}

	out := run(args[2], args[3:]...)

	if out != string(expected) {
		fmt.Println("expected:")
		fmt.Print(string(expected))
		fmt.Println("got:")
		fmt.Print(out)
		os.Exit(1)
	}
}
