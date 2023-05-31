package main

import (
	"bufio"
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

// x19: segment mask
// x20: segment id
// x21: dedicated register for use by the sandbox

// must use bundles so that we can still use the 'ret' instruction, for
// function return speculation.

const (
	segmentMask = "x20"
	sandboxReg  = "x21"
	segmentId   = "x22"

	bundleMask = "#0x0f"
)

var sandboxRegs = map[string]bool{
	"sp": true,
	"fp": true,
}

// Instructions that may modify sp/fp and will be appropriately sandboxed. If
// different instructions are used, they will not be sandboxed and the verifier
// will reject the pattern.
var modifyInsns = map[string]bool{
	"add":  true,
	"adds": true,
	"sub":  true,
	"subs": true,
	"mov":  true,
	"movk": true,
	"movn": true,
	"movz": true,
	"mvn":  true,
	"ldr":  true,
}

func ensure(b bool) {
	if !b {
		panic("ensure failed")
	}
}

func field(s string, n int) string {
	fields := strings.Fields(s)
	ensure(len(fields) > n)
	return fields[n]
}

func isolate(out *bytes.Buffer, in string) {
	in = strings.TrimSpace(in)
	fields := strings.Fields(in)
	if len(fields) <= 0 {
		fmt.Fprintln(out, in)
		return
	}
	modified := ""
	switch fields[0] {
	case "ret":
		isolateRet(out, in)
	case "blr", "br":
		isolateBrBlr(out, in)
	case "bl":
		isolateBl(out, in)
	case "ldr", "str":
		isolateLdrStr(out, in)
	default:
		fmt.Fprintln(out, in)
	}
	if modifyInsns[fields[0]] && len(fields) > 1 {
		modified = strings.Trim(fields[1], " ,")
		if sandboxRegs[modified] {
			// TODO: optimization: if the modified reg is accessed with a
			// load/store before the next jump, then we don't have to do this since
			// that access will insure that the modified reg is valid.
			fmt.Fprintf(out, "mov %s, %s\n", sandboxReg, modified)
			fmt.Fprintf(out, "and %s, %s, %s\n", sandboxReg, sandboxReg, segmentMask)
			fmt.Fprintf(out, "orr %s, %s, %s\n", sandboxReg, sandboxReg, segmentId)
			fmt.Fprintf(out, "mov %s, %s\n", modified, sandboxReg)
		}
	}
}

func isolateRet(out *bytes.Buffer, in string) {
	fmt.Fprintln(out, ".p2align 4")
	fmt.Fprintf(out, "and lr, lr, %s\n", segmentMask)
	fmt.Fprintf(out, "bic lr, lr, %s\n", bundleMask)
	fmt.Fprintf(out, "orr lr, lr, %s\n", segmentId)
	fmt.Fprintln(out, "ret")
}

func isolateBrBlr(out *bytes.Buffer, in string) {
	fields := strings.Fields(in)
	ensure(len(fields) >= 2)
	op, reg := fields[0], fields[1]
	fmt.Fprintln(out, ".p2align 4")
	fmt.Fprintf(out, "and %s, %s, %s\n", reg, reg, segmentMask)
	fmt.Fprintf(out, "bic %s, %s, %s\n", reg, reg, bundleMask)
	fmt.Fprintf(out, "orr %s, %s, %s\n", reg, reg, segmentId)
	fmt.Fprintf(out, "%s %s\n", op, reg)
}

func isolateBl(out *bytes.Buffer, in string) {
	// TODO: optimization: may not have to insert as many nops if we track when
	// the last p2align was
	fmt.Fprintln(out, ".p2align 4")
	fmt.Fprintln(out, "nop")
	fmt.Fprintln(out, "nop")
	fmt.Fprintln(out, "nop")
	fmt.Fprintln(out, in)
}

type Addr struct {
	Reg string
}

func parseAddr(in string) Addr {
	ensure(in[0] == '[')
	in = in[1:]
	before, _, found := strings.Cut(in, "]")
	ensure(found)
	before, _, _ = strings.Cut(before, ",")
	return Addr{
		Reg: before,
	}
}

func isolateLdrStr(out *bytes.Buffer, in string) {
	parts := strings.SplitN(in, ",", 2)
	for i := range parts {
		parts[i] = strings.TrimSpace(parts[i])
	}
	ensure(len(parts) > 1)
	addr := parseAddr(parts[1])
	if !sandboxRegs[addr.Reg] {
		fmt.Fprintln(out, ".p2align 4")
		fmt.Fprintf(out, "and %s, %s, %s\n", addr.Reg, addr.Reg, segmentMask)
		fmt.Fprintf(out, "orr %s, %s, xzr\n", addr.Reg, addr.Reg)
	}
	fmt.Fprintln(out, in)
}

func isolateLdp(out *bytes.Buffer, in string) {
}

func isolateStp(out *bytes.Buffer, in string) {
}

func main() {
	flag.Parse()
	args := flag.Args()

	if len(args) <= 0 {
		log.Fatal("no input")
	}

	target := args[0]
	f, err := os.Open(target)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	out := &bytes.Buffer{}

	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		isolate(out, scanner.Text())
		// fmt.Fprintln(out, scanner.Text())
	}

	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

	fmt.Print(out.String())
}
