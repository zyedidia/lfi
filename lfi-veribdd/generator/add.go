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
	id uint16
	v  uint8
	lo uint16
	hi uint16
	loOrig uint32
	hiOrig uint32
	isTerminal bool
	isTerminallo bool
	isTerminalhi bool
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
	for _, n := range nodes {
		fmt.Fprintf(w, "%d [label=\"%d\"]\n", n.id, n.v)
		fmt.Fprintf(w, "%d -> %d [style=dotted];\n", n.id, n.lo)
		fmt.Fprintf(w, "%d -> %d [style=filled];\n", n.id, n.hi)
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



func writeCv2(nodes []Node, maxRank int, w io.Writer){
	fmt.Fprintln(w,"#include <stdint.h>")
	fmt.Fprintln(w,"#include <stdbool.h>")
	fmt.Fprintln(w,"static int evaluate(uint8_t *input){")
	
	entry := 0
	for _, n := range nodes {
		if n.v == 0 {
			entry = int(n.id)
			break
		}
	}
	fmt.Fprintf(w, "\tgoto node%d;\n", entry)
	
	
	// fmt.Fprintf(w, "node0: return false;\n")
	// fmt.Fprintf(w, "node1: return true;\n")
	for _, n := range nodes {
		/* if i < 2  {
			continue
		} */
		/* if n.isTerminal {
			fmt.Fprintf(w, "node%d:\n", n.id)
			fmt.Fprintf(w, "\tif((input>>%d) & 0x1)\n", n.v)
			fmt.Fprintf(w, "\t\treturn %d;\n", n.hi)
			fmt.Fprintf(w, "\telse \n\t\treturn %d;\n", n.lo)
		} else {
			fmt.Fprintf(w, "node%d:\n", n.id)
			fmt.Fprintf(w, "\tif((input>>%d) & 0x1)\n", n.v)
			fmt.Fprintf(w, "\t\tgoto node%d;\n", n.hi)
			fmt.Fprintf(w, "\telse \n\t\tgoto node%d;\n", n.lo)
		} */
		
		
		fmt.Fprintf(w, "node%d:\n", n.id)
		fmt.Fprintf(w, "\tif((input[%d]>>%d) & 0x1)\n", n.v/8, 7 - (n.v % 8))
		if n.isTerminalhi {
			fmt.Fprintf(w, "\t\treturn %d;\n", n.hi) 
		} else {
			fmt.Fprintf(w, "\t\tgoto node%d;\n", n.hi) 
		}
		if n.isTerminallo {
			fmt.Fprintf(w, "\telse \n\t\treturn %d;\n", n.lo) 
		} else {
			fmt.Fprintf(w, "\telse \n\t\tgoto node%d;\n", n.lo)
		}
		
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

	n, maxRank := parseHeader(lines[0])

	// nodes := make([]Node, 2, n)
	nodes := make([]Node, 0, n)
	nodeId := make(map[int]int) /*{
		0: 0,
		1: 1,
	} */
	
	counter := 0
	for _, l := range lines[2:] {
		parts := strings.Fields(l)
		if len(parts) != 4 {
			continue
		} 
		id := toInt(parts[0])
		if _, ok := nodeId[id]; !ok {
			nodeId[id] = counter
			counter++
		}
		v := toInt(parts[1])
		lo := toInt(parts[2])
		if _, ok := nodeId[lo]; !ok {
			nodeId[lo] = counter
			counter++
		}
		hi := toInt(parts[3])
		if _, ok := nodeId[hi]; !ok {
			nodeId[hi] = counter
			counter++
		}

		nodes = append(nodes, Node{
			id: uint16(id),		// uint16(nodeId[id]),
			v:  uint8(v),
			lo: uint16(lo),		// uint16(nodeId[lo]),
			hi: uint16(hi),		// uint16(nodeId[hi]),
			loOrig: uint32(lo),
			hiOrig: uint32(hi),
			isTerminal: false,
			isTerminallo: true,
			isTerminalhi: true,
		})
		// nodeId[id] = len(nodes) - 1
		
		// fmt.Println(nodeId[id])
	}
	
	for i, n1 := range nodes {
		isParent := false
		// n1.isTerminallo = true
		// n1.isTerminalhi = true
		// fmt.Println(n1.id)
		for _, n2 := range nodes {
			if n1.lo == n2.id || n1.hi == n2.id {
				isParent = true
				// fmt.Println("Hello")
			}
			
			if n1.lo == n2.id {
				nodes[i].isTerminallo = false
			}
			
			if n1.hi == n2.id {
				nodes[i].isTerminalhi = false
			}
		}
		nodes[i].isTerminal = !isParent
	}
	
	// nodes[2:]
	/* for i, node := range nodes[:] {
		nodes[i].lo= uint16(nodeId[int(node.loOrig)])
		nodes[i].hi= uint16(nodeId[int(node.hiOrig)])
	} */
	

	if *dot {
		writeDot(nodes, os.Stdout)
	} else if *binary {
		writeBinary(nodes, os.Stdout)
	} else {
		// writeC(nodes, os.Stdout)
		writeCv2(nodes, maxRank, os.Stdout)
	}
}
