package main

import (
	"bytes"
	"encoding/binary"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	v  uint8
	lo uint16
	hi uint16
}

func toInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		log.Fatal(err)
	}
	return i
}

func parseHeader(line string) (int, int) {
	sNodes, sVars, _ := strings.Cut(line, " ")
	return toInt(sNodes), toInt(sVars)
}

func writeDot(nodes []Node, w io.Writer) {
	fmt.Fprintln(w, "strict digraph take {")
	fmt.Fprintln(w, "rankdir=\"LR\";")
	for i, n := range nodes {
		fmt.Fprintf(w, "%d [label=\"%d\"]\n", i, n.v)
		fmt.Fprintf(w, "%d -> %d [style=dotted];\n", i, n.lo)
		fmt.Fprintf(w, "%d -> %d [style=filled];\n", i, n.hi)
	}
	fmt.Fprintln(w, "}")
}

func writeC(nodes []Node, w io.Writer){
	fmt.Fprintln(w,"#include <stdint.h>")
	fmt.Fprintln(w,"#include <stdbool.h>")
	fmt.Fprintln(w,"bool evaluate(uint32_t input){")
	fmt.Fprintf(w, "\tgoto node%d;\n", len(nodes) - 1)
	fmt.Fprintf(w, "node0: return false;\n")
	fmt.Fprintf(w, "node1: return true;\n")
	for i, n := range nodes {
		if i < 2  {
			continue
		}
		fmt.Fprintf(w, "node%d:\n", i)
		fmt.Fprintf(w, "\tif((input>>%d) & 0x1)\n", n.v)
		fmt.Fprintf(w, "\t\tgoto node%d;\n", n.hi)
		fmt.Fprintf(w, "\telse \n\t\tgoto node%d;\n", n.lo)
	}
	fmt.Fprintln(w, "}")
}


func writeBinary(nodes []Node, w io.Writer) {
	buf := &bytes.Buffer{}
	for _, n := range nodes {
		binary.Write(buf, binary.LittleEndian, uint16(n.v))
		binary.Write(buf, binary.LittleEndian, uint16(n.lo))
		binary.Write(buf, binary.LittleEndian, uint16(n.hi))
	}
	buf.WriteTo(w)
}

func main() {
	dot := flag.Bool("graph", false, "produce graphviz dot graph")
	binary := flag.Bool("binary", false, "produce binary repsentation/format")



	flag.Parse()
	args := flag.Args()

	if len(args) <= 0 {
		fmt.Fprintf(os.Stderr, "usage: bdd lfi.bdd\n")
		os.Exit(1)
	}
	fdat, err := os.ReadFile(args[0])
	if err != nil {
		log.Fatal(err)
	}
	dat := string(fdat)
	lines := strings.Split(dat, "\n")

	n, _ := parseHeader(lines[0])

	nodes := make([]Node, 2, n)
	nodeId := map[int]int{
		0: 0,
		1: 1,
	}

	for _, l := range lines[2:] {
		parts := strings.Fields(l)
		if len(parts) != 4 {
			continue
		}
		id := toInt(parts[0])
		v := toInt(parts[1])
		lo := toInt(parts[2])
		hi := toInt(parts[3])

		nodes = append(nodes, Node{
			v:  uint8(v),
			lo: uint16(nodeId[lo]),
			hi: uint16(nodeId[hi]),
		})
		nodeId[id] = len(nodes) - 1
	}

	if *dot {
		writeDot(nodes, os.Stdout)
	} else if *binary {
		writeBinary(nodes, os.Stdout)
	} else {
		writeC(nodes, os.Stdout)
	}
}
