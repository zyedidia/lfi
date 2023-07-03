package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"os/exec"
	"strings"
	"time"
)

func main() {
	loader := flag.Bool("loader", false, "run program with loader")

	flag.Parse()
	cmdsdat, err := io.ReadAll(os.Stdin)
	if err != nil {
		log.Fatal(err)
	}
	cmds := strings.Split(string(cmdsdat), "\n")
	start := time.Now()
	for _, c := range cmds {
		if strings.HasPrefix(c, "#") || strings.HasPrefix(c, "specinvoke exit") || strings.TrimSpace(c) == "" {
			continue
		}
		var cmd *exec.Cmd
		if *loader {
			cmd = exec.Command("sh", "-c", "loader "+c)
		} else {
			cmd = exec.Command("sh", "-c", c)
		}
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
