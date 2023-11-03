package main

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
)

// note: in order to use, you must remove checksum verification from
// check_important_files in bin/common/setup_common.pl
// or
// change version.txt to 0.0.0 and set SPEC_NOCHECK=1

func main() {
	loader := os.Getenv("LOADER")
	spec := os.Getenv("SPEC")
	specinvoke := filepath.Join(spec, "bin", "specinvoke.orig")

	var args []string
	var cmds string
	for i := 1; i < len(os.Args); i++ {
		switch os.Args[i] {
		case "-f":
			if i+1 >= len(os.Args) {
				log.Fatal("-f has no argument")
			}
			cmds = os.Args[i+1]
			i++
		default:
			args = append(args, os.Args[i])
		}
	}

	if cmds != "" {
		data, err := os.ReadFile(cmds)
		if err != nil {
			log.Fatal(err)
		}
		str := string(data)
		str = strings.ReplaceAll(str, "../run_base_", fmt.Sprintf("%s ../run_base_", loader))
		os.WriteFile(cmds, []byte(str), os.ModePerm)
	}

	args = append(args, "-f", cmds)
	cmd := exec.Command(specinvoke, args...)
	fmt.Println("specinvoke running:", cmd)
	cmd.Stdout = os.Stdout
	cmd.Stdin = os.Stdin
	cmd.Stderr = os.Stderr
	cmd.Env = os.Environ()
	if err := cmd.Run(); err != nil {
		log.Fatal(err)
	}
}
