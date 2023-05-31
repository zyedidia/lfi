package main

import (
	"flag"
	"fmt"
	"log"
	"os"

	"golang.org/x/arch/arm64/arm64asm"
)

func main() {
	flag.Parse()
	args := flag.Args()

	if len(args) < 1 {
		log.Fatal("no input")
	}

	target := args[0]

	data, err := os.ReadFile(target)
	if err != nil {
		log.Fatal(err)
	}

	for len(data) > 0 {
		inst, err := arm64asm.Decode(data)
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println(arm64asm.GNUSyntax(inst))

		data = data[4:]
	}
}
