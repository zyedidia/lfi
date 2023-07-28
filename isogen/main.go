package main

import (
	"fmt"
	"io"
	"log"
	"os"

	"github.com/spf13/pflag"
)

func showOps(w io.Writer, list *OpList) {
	op := list.Front
	for op != nil {
		// if op.Leader {
		// 	fmt.Print("leader: ")
		// }
		fmt.Fprintf(w, "%v\n", op.Value)
		op = op.Next
	}
}

var instrument = pflag.Bool("inst", false, "add instrumentation for profiling")

func main() {
	out := pflag.StringP("output", "o", "", "output file")
	hoist := pflag.BoolP("hoist", "r", true, "apply guard hoisting optimization")

	pflag.Parse()
	args := pflag.Args()
	if len(args) < 1 {
		log.Fatal("no input")
	}

	f, err := os.Open(args[0])
	if err != nil {
		log.Fatal(err)
	}
	ops, err := ParseFile(f, args[0])
	if err != nil {
		log.Fatal(err)
	}

	// MarkLeaders(*ops)

	branchPass(ops)
	fixupReservedPass(ops)
	if *hoist {
		rangePass(ops)
	}
	memPass(ops)
	syscallPass(ops)
	specialRegPass(ops)
	if *instrument {
		instrumentPass(ops)
	}
	branchFixupPass(ops)

	var w io.Writer
	if *out != "" {
		f, err := os.Create(*out)
		if err != nil {
			log.Fatal(err)
		}
		w = f
		defer f.Close()
	} else {
		w = os.Stdout
	}
	showOps(w, ops)
}
