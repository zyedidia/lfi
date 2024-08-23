package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
	"math/rand"
	"path/filepath"
)

// Random seed for generating instructions
const SeedVal int64 = 907
// Number of instructions to be generated
const NumInstr int = 10000


type Node struct {
	id uint16
	v  uint8
	lo uint16
	hi uint16
	parents []uint16
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



func main() {
	rand.Seed(SeedVal)


	flag.Parse()
	args := flag.Args()

	if len(args) <= 1 {
		fmt.Fprintf(os.Stderr, "usage: bdd lfi.bdd out.bin\n")
		os.Exit(1)
	}
	fdat, err := os.ReadFile(args[0])
	if err != nil {
		log.Fatal(err)
	}
	dat := string(fdat)
	lines := strings.Split(dat, "\n")

	n, _ := parseHeader(lines[0])

	nodes := make([]Node, 0, n)
	
	IdToIndex := make(map[int]int)
	
	// Parse the nodes
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
			id: uint16(id),		// uint16(nodeId[id]),
			v:  uint8(v),
			lo: uint16(lo),		// uint16(nodeId[lo]),
			hi: uint16(hi),		// uint16(nodeId[hi]),
			parents: make([]uint16, 0, n),
			loOrig: uint32(lo),
			hiOrig: uint32(hi),
			isTerminal: false,
			isTerminallo: true,
			isTerminalhi: true,
		})
		IdToIndex[id] = len(nodes) - 1
		
	}

	// Locate the end return values that generate a valid (non-zero length) instruction
	// Denotes an array of triples: (nodeIndex, retVal, bit)
	var endNodes [][]uint16
	
	for i, n1 := range nodes {
		isParent := false
		
		for j, n2 := range nodes {

			// Add parent node to array of parents
			if n1.lo == n2.id || n1.hi == n2.id {
				isParent = true
				nodes[j].parents = append(nodes[j].parents, uint16(i))
			}
			
			// Locate (lack of) terminal nodes
			if n1.lo == n2.id {
				nodes[i].isTerminallo = false
			}
			if n1.hi == n2.id {
				nodes[i].isTerminalhi = false
			}
		}
		nodes[i].isTerminal = !isParent

		// Add relevant (non-zero) terminal nodes to list of triples
		if nodes[i].isTerminallo && n1.lo != 0 {
			endNodes = append(endNodes, []uint16{uint16(i), n1.lo, 0})
		}
		if nodes[i].isTerminalhi && n1.hi != 0 {
			endNodes = append(endNodes, []uint16{uint16(i), n1.hi, 1})
		}

	}

	

	outputText := &bytes.Buffer{}

	// Generate the specified number of instructions
	for range NumInstr {
		// Pick a random terminal node
		endIndex := rand.Int() % len(endNodes)
		endTriple := endNodes[endIndex]

		// Create an instruction of the proper length, and populate the 1st known bit
		outBytes := make([]uint8, endTriple[1])
		curNode := nodes[endTriple[0]]
		outBytes[curNode.v / 8] |= uint8(endTriple[2] << (7 - (curNode.v % 8)))

		// Populate the rest of the instruction with the relevant bits
		for len(curNode.parents) > 0 {
			// Pick a random node from the parent list
			nextIndex := rand.Int() % len(curNode.parents)
			nextNode := nodes[curNode.parents[nextIndex]]


			// We only really need to consider the 1 bit as that is the only case a bit is modified
			if nextNode.hi == curNode.id {
				outBytes[nextNode.v / 8] |= uint8(1 << (7 - (nextNode.v % 8)))
			}

			curNode = nextNode

		}

		// Print the random instruction to the writer
		_, err := outputText.Write(outBytes)
		if err != nil { log.Fatal(err) }
		

	}

	// Output the set of instructions to the specified file
	dir, err := os.Getwd()
	if err != nil {	log.Fatal(err) }
	f, err := os.Create(filepath.Join(dir, args[1]))
	if err != nil { log.Fatal(err) }

	_, err = f.WriteString(outputText.String())
	if err != nil { log.Fatal(err) }

	f.Close()
}
