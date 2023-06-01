package main

import (
	"log"
	"os"

	"github.com/alecthomas/repr"
)

func main() {
	ast, err := armParser.Parse("stdin", os.Stdin)
	if err != nil {
		log.Fatal(err)
	}
	repr.Println(ast)
}
