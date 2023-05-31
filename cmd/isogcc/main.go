package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
)

const (
	flags = "-falign-labels=16 -falign-jumps=16 -falign-functions=16 -ffixed-x20 -ffixed-x21"
)

func run(command string) {
	cmd := exec.Command("sh", "-c", command)
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	err := cmd.Run()
	if err != nil {
		log.Fatal(err)
	}
}

func temp() string {
	tmp, err := os.CreateTemp("", "isogcc.*.s")
	if err != nil {
		log.Fatal(err)
	}
	tmp.Close()
	return tmp.Name()
}

func main() {
	cc := flag.String("cc", "aarch64-none-elf-gcc", "c compiler")
	userflags := flag.String("flags", "", "c compiler flags")
	out := flag.String("o", "/dev/stdout", "output file")
	flag.Parse()
	args := flag.Args()
	if len(args) < 1 {
		log.Fatal("no input")
	}
	in := args[0]

	asm := temp()
	run(fmt.Sprintf("%s %s %s %s -S -o %s", *cc, flags, *userflags, in, asm))
	iso := temp()
	run(fmt.Sprintf("isolator %s > %s", asm, iso))
	run(fmt.Sprintf("%s %s %s %s -c -o %s", *cc, flags, *userflags, iso, *out))

	// os.Remove(asm)
	// os.Remove(iso)
}
