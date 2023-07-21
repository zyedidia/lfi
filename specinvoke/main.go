package main

import (
	"bytes"
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"strings"
	"time"
)

func main() {
	loader := os.Getenv("LOADER")
	spec := os.Getenv("SPEC")
	specinvoke := filepath.Join(spec, "bin", "specinvoke")

	args := make([]string, len(os.Args))
	copy(args, os.Args)
	args = append(args, "-n")

	buf := &bytes.Buffer{}
	cmd := exec.Command(specinvoke, args...)
	cmd.Stdout = buf
	cmd.Stdin = os.Stdin
	cmd.Stderr = os.Stderr
	if err := cmd.Run(); err != nil {
		log.Fatal(err)
	}
	cmds := strings.Split(buf.String(), "\n")

	start := time.Now()
	for _, c := range cmds {
		if strings.HasPrefix(c, "#") || strings.HasPrefix(c, "specinvoke exit") || strings.TrimSpace(c) == "" {
			continue
		}
		cmd := exec.Command("sh", "-c", loader+" "+c)
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		cmd.Stdin = os.Stdin
		fmt.Println(cmd)
		err := cmd.Run()
		if err != nil {
			log.Fatal(err)
		}
	}
	fmt.Println(time.Since(start))
}
