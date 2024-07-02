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

type Node2 struct {
	shift uint8 // low 5 bits represent the ammount of location shifted (equivalent to v value in original Node struct), 
	// high 3 bits represent the size of the mask to be considered (0 -> size 1, 1 -> size 2, ... 7 -> size 8)
<<<<<<< HEAD
	size uint8
	v uint32 // value to be checked
=======
	v uint8 // value to be checked
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
	lo uint16 // goes to if mask check rejects
	hi uint16 // goes to if mask check accepts
	parents []int // list of parent nodes via index value
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


func writeC2(nodes []Node2, w io.Writer){
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
		
<<<<<<< HEAD
		var mask uint32 = (1 << (n.shift + n.size + 1)) - (1 << n.shift) // (1 << ((n.shift >> 5) + (n.shift & 0x1F) + 1)) - (1 << (n.shift & 0x1F))
		var val uint32 = n.v << n.shift // uint32(n.v) << (n.shift & 0x1F)
		fmt.Fprintf(w, "node%d:\n", i)
		// fmt.Fprintf(w, "\tif((input & %d) == %d)\n", mask, val)
		fmt.Fprintf(w, "\tif((input & 0b%032b) == 0b%032b)\n", mask, val)
=======
		var mask uint32 = (1 << ((n.shift >> 5) + (n.shift & 0x1F) + 1)) - (1 << (n.shift & 0x1F))
		var val uint32 = uint32(n.v) << (n.shift & 0x1F)
		fmt.Fprintf(w, "node%d:\n", i)
		fmt.Fprintf(w, "\tif((input & %d) == %d)\n", mask, val)
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
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
		
		// fmt.Fprintf(os.Stdout, "\tgoto node%d;\n", uint16(nodeId[lo]))

		nodes = append(nodes, Node{
			v:  uint8(v),
			lo: uint16(nodeId[lo]),
			hi: uint16(nodeId[hi]),
		})
		nodeId[id] = len(nodes) - 1
	}
	
	nodes2 := make([]Node2, 0, n)
	for i, N := range nodes[:] {
		// fmt.Fprintf(os.Stdout, "\tgoto node%d;\n", N.hi)
		nodes2 = append(nodes2, Node2{
			shift: N.v,
<<<<<<< HEAD
			size: 0,  // This results in a default size of 1
=======
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
			v: 1,
			lo: N.lo,
			hi: N.hi,
			parents: make([]int, 0, n),
		})
		
		nodes2[N.lo].parents = append(nodes2[N.lo].parents, i)
		nodes2[N.hi].parents = append(nodes2[N.hi].parents, i)
		
		// fmt.Println(nodes2[N.lo].parents)
	}
	
	
	/* for i, n := range nodes2 {
	
	} */
	
<<<<<<< HEAD
	// fmt.Println(len(nodes2))
	
=======
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
	for i := len(nodes2) - 1; i >= 2; i-- {
		origN := &nodes2[i]
		curN := nodes2[i]
		curNNumerical := uint16(i)
		
		if origN.lo < 2 && origN.hi < 2 { // If both children lead to end of BDD, cannot compress further, so exit case
			continue
		}
		
		// if origN.shift - nodes2
		
<<<<<<< HEAD
		var checkStr uint32 = 0
=======
		var checkStr uint8 = 0
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
		var bitI uint8 = 0
		var increasing bool = false // = origN.shift <  // Is the bit shift value increasing as one descends upon the tree
		var commonNode uint16
		
		var fixed bool = false
		
		// if i == 3 {fmt.Printf("%d == %d\n", origN.hi, nodes2[origN.lo].hi)}
		
		if origN.lo == nodes2[origN.hi].lo {
			commonNode = origN.lo
			curN = nodes2[origN.hi]
			curNNumerical = origN.hi
			
			abs := int(origN.shift) - int(curN.shift)
			
			if(abs < 0){ abs = -abs; increasing = true}
			
			
			if len(curN.parents) > 1 || abs > 1 {continue} // If the current node has multiple references to it, it cannot be a node that is compressed and ignored
			// also if the shift distance is greater than 1
			
			checkStr = 0b11
			bitI += 2
			fixed = true
			
		} else if origN.lo == nodes2[origN.hi].hi {
			commonNode = origN.lo
			curN = nodes2[origN.hi]
			curNNumerical = origN.hi
			
			abs := int(origN.shift) - int(curN.shift)
			
			if(abs < 0){ abs = -abs; increasing = true}
			
			
			if len(curN.parents) > 1 || abs > 1 {continue} // If the current node has multiple references to it, it cannot be a node that is compressed and ignored
			// also if the shift distance is greater than 1
			
			checkStr = 0b10
			if increasing{checkStr = 0b01}
			bitI += 2
			fixed = true
			
		} else if origN.hi == nodes2[origN.lo].lo {
			commonNode = origN.hi
			curN = nodes2[origN.lo]
			curNNumerical = origN.lo
			
			abs := int(origN.shift) - int(curN.shift)
			
			if(abs < 0){ abs = -abs; increasing = true}
			
			
			if len(curN.parents) > 1 || abs > 1 {continue} // If the current node has multiple references to it, it cannot be a node that is compressed and ignored
			// also if the shift distance is greater than 1
			
			checkStr = 0b01
			if increasing{checkStr = 0b10}
			bitI += 2
			fixed = true
			
		} else if origN.hi == nodes2[origN.lo].hi {
		

			commonNode = origN.hi
			curN = nodes2[origN.lo]
			curNNumerical = origN.lo
			
			abs := int(origN.shift) - int(curN.shift)
			
			if(abs < 0){ abs = -abs; increasing = true}
			// if i == 3 {fmt.Println(abs)}
			
			
			if len(curN.parents) > 1 || abs > 1 {continue} // If the current node has multiple references to it, it cannot be a node that is compressed and ignored
			// also if the shift distance is greater than 1
			
			// if i == 3 {fmt.Println(curN.parents)}
			checkStr = 0b00
			bitI += 2
			fixed = true
			
		} 
		
		
		if fixed {
		
			// fmt.Println("fixed")
<<<<<<< HEAD
			// fmt.Println(commonNode)
			// fmt.Println(increasing)
			
			var next uint16 = 0 // Set this variable to the node other than the common node if it exists
			if curN.lo == commonNode {
				next = curN.hi
				// fmt.Println("Hi")
			} else if curN.hi == commonNode {
				next = curN.lo
				// fmt.Println("Lo")
			}
			curN = nodes2[next]
			curNNumerical = next
				
				
			
			for bitI <= 32 {
				// if len(nodes2[curN.].parents) == 1 && nodes2[]
				
				if curNNumerical < 2 || len(curN.parents) > 1 {break}
				
				var alternateNode uint16 // Set this variable to the node other than the common node if it exists
				if curN.lo == commonNode {
					alternateNode = curN.hi
					// fmt.Println("Hi")
				} else if curN.hi == commonNode {
					alternateNode = curN.lo
					// fmt.Println("Lo")
=======
			for bitI < 8 {
				// if len(nodes2[curN.].parents) == 1 && nodes2[]
				
				var alternateNode uint16 // Set this variable to the node other than the common node if it exists
				if curN.lo == commonNode {
					alternateNode = curN.hi
				} else if curN.hi == commonNode {
					alternateNode = curN.lo
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
				} else {
					break
				}
				
<<<<<<< HEAD
				// fmt.Println(alternateNode)
				
				// If the alternate node is well formed for continuing the chain (no parents, continuing to increase/decrease), continue the chain
				abs := int(curN.shift) - int(origN.shift)  // int(nodes2[alternateNode].shift)
			
				if(increasing){ abs = -abs}
				// fmt.Printf("abs: %d\n", abs)
			
			
				// if len(nodes2[alternateNode].parents) > 1 || abs != 1 {break}
				
				if abs != 0 - int(bitI) {break}
				
				// Conditions passed, update the check string and progress down the chain
				var newBit uint32 = 0 
				if alternateNode == curN.hi {newBit = 1}
				// fmt.Printf("New bit %d\n", newBit)
				if increasing {
					// fmt.Println(newBit << bitI)
					checkStr |= newBit << bitI
					// fmt.Printf("%032b\n", checkStr)
=======
				
				// If the alternate node is well formed for continuing the chain (no parents, continuing to increase/decrease), continue the chain
				abs := int(curN.shift) - int(nodes2[alternateNode].shift)
			
				if(increasing){ abs = -abs}
			
			
				if len(nodes2[alternateNode].parents) > 1 || abs != 1 {break}
				
				
				// Conditions passed, update the check string and progress down the chain
				var newBit uint8 = 0 
				if alternateNode == curN.hi {newBit = 1}
				
				if increasing {
					checkStr |= newBit << bitI
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
				} else {
					checkStr <<= 1
					checkStr |= newBit
				}
				
				
				curN = nodes2[alternateNode]
				curNNumerical = alternateNode
				bitI++
				
				
			}
			
			// Update the node to the actual value
			
			origN.v = checkStr
			
			// Update the shift to be the lower of the two shifts, as that is where the bits will be checked
			// var uShift uint8 = nodes2[nodes2[curN.lo].parents[0]].shift
<<<<<<< HEAD
			// var uShift uint8 = nodes2[curN.parents[0]].shift
			// if uShift < origN.shift {origN.shift = uShift} 
			
			if !increasing {origN.shift -= (bitI - 1)}
			
			// origN.shift |= (bitI - 1) << 5 // Add the length of the bit string to the top unused 3 bits of the shift for saving
			origN.size = bitI - 1
			
			
			/* var alternateNode uint16 // Set this variable to the node other than the common node if it exists
=======
			var uShift uint8 = nodes2[curN.parents[0]].shift
			if uShift < origN.shift {origN.shift = uShift} 
			
			origN.shift |= (bitI - 1) << 5 // Add the length of the bit string to the top unused 3 bits of the shift for saving
			
			var alternateNode uint16 // Set this variable to the node other than the common node if it exists
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
			if nodes2[curNNumerical].lo == commonNode {
				alternateNode = curN.hi
			} else if curN.hi == commonNode {
				alternateNode = curN.lo
<<<<<<< HEAD
			} */
			
			origN.hi = curNNumerical // curNNumerical // uint16(nodes2[curN.lo].parents[0])
=======
			}
			
			origN.hi = alternateNode // curNNumerical // uint16(nodes2[curN.lo].parents[0])
>>>>>>> 7587a1af9e82f6f63a4f2e3ffd0f002b76f3f10b
			origN.lo = commonNode
			
			// fmt.Printf("node%d: %d\n", i, origN.v)
			// fmt.Printf("%d\n", nodes2[i].v)
			
		}
		
	}
	
	
	

	if *dot {
		writeDot(nodes, os.Stdout)
	} else if *binary {
		writeBinary(nodes, os.Stdout)
	} else {
		// writeC(nodes, os.Stdout)
		writeC2(nodes2, os.Stdout)
	}
}
