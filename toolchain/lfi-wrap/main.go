package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"runtime"
	"strings"
	"text/template"

	_ "embed"
)

//go:embed gcc
var gccTemplate string

//go:embed clang
var clangTemplate string

//go:embed nolib-clang
var nolibClangTemplate string

type Args struct {
	Arch       string
	LfiFlags   string
	LegFlags   string
	Flags      string
	ExtraFlags string
	Compiler   string
	Toolchain  string
}

func legFlags(compiler, lfiflags, arch string) string {
	buf := &bytes.Buffer{}
	cmd := exec.Command("sh", "-c", fmt.Sprintf("lfi-leg -a %s --flags=%s %s", arch, compiler, lfiflags))
	cmd.Env = os.Environ()
	cmd.Stdout = buf
	cmd.Stderr = os.Stderr
	err := cmd.Run()
	if err != nil {
		log.Fatal(err)
	}
	return strings.TrimSpace(buf.String())
}

var toLegArch = map[string]string{
	"x86_64":      "amd64",
	"aarch64_lfi": "arm64",
	"aarch64":     "arm64",
}

func main() {
	toolchain := flag.String("toolchain", "gcc", "compiler toolchain to generate wrapper for (gcc,clang,nolib-clang)")
	compiler := flag.String("compiler", "gcc", "compiler to generate wrapper for (clang,clang++,gcc,g++,gfortran,...)")
	flags := flag.Bool("flags", false, "show flags")
	flag.Parse()

	lfiarch := os.Getenv("ARCH")
	var arch string
	if _, ok := toLegArch[lfiarch]; ok {
		arch = toLegArch[lfiarch]
	} else {
		arch = runtime.GOARCH
	}
	lfiflags := os.Getenv("LFIFLAGS")

	var extraflags map[string]string
	switch arch {
	case "amd64":
		extraflags = map[string]string{
			"gcc":         "-ftls-model=local-exec -fPIC -fno-plt -static-pie -z separate-code",
			"clang":       "-static-pie -target x86_64-linux-musl",
			"nolib-clang": "-fPIC -target x86_64-linux-musl",
		}
	case "arm64":
		extraflags = map[string]string{
			"gcc":         "-fPIC -static-pie -z separate-code",
			"clang":       "-static-pie -target aarch64-linux-musl",
			"nolib-clang": "-fPIC -target aarch64-linux-musl",
		}
	default:
		fmt.Fprintln(os.Stderr, "invalid arch", arch)
		os.Exit(1)
	}

	legToolchain := *toolchain

	var data string
	switch *toolchain {
	case "gcc":
		data = gccTemplate
	case "clang":
		data = clangTemplate
	case "nolib-clang":
		data = nolibClangTemplate
		legToolchain = "clang"
	default:
		fmt.Fprintln(os.Stderr, "invalid compiler", *compiler)
		os.Exit(1)
	}

	if *flags {
		fmt.Printf("%s %s\n", legFlags(legToolchain, lfiflags, arch), extraflags[*toolchain])
		return
	}

	t, err := template.New("lfi").Parse(data)
	if err != nil {
		log.Fatal(err)
	}

	err = t.Execute(os.Stdout, Args{
		Arch:       arch,
		LfiFlags:   lfiflags,
		LegFlags:   legFlags(legToolchain, lfiflags, arch),
		ExtraFlags: extraflags[*toolchain],
		Compiler:   *compiler,
		Toolchain:  legToolchain,
	})
	if err != nil {
		log.Fatal(err)
	}
}
