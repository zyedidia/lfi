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
	Arch          string
	GnuArch       string
	LfiFlags      string
	LegFlags      string
	Flags         string
	ExtraFlags    string
	Compiler      string
	Toolchain     string
	PostlinkFlags string
}

func legFlags(compiler, lfiflags string) string {
	buf := &bytes.Buffer{}
	cmd := exec.Command("sh", "-c", fmt.Sprintf("lfi-leg --flags=%s %s", compiler, lfiflags))
	cmd.Env = os.Environ()
	cmd.Stdout = buf
	cmd.Stderr = os.Stderr
	err := cmd.Run()
	if err != nil {
		log.Fatal(err)
	}
	return buf.String()
}

func main() {
	toolchain := flag.String("toolchain", "gcc", "compiler toolchain to generate wrapper for (gcc,clang,nolib-clang)")
	compiler := flag.String("compiler", "gcc", "compiler to generate wrapper for (clang,clang++,gcc,g++,gfortran,...)")
	arch := flag.String("arch", runtime.GOARCH, "architecture to generate wrapper for (clang-only)")
	flags := flag.Bool("flags", false, "show flags")
	flag.Parse()

	lfiflags := os.Getenv("LFIFLAGS")

	var extraflags map[string]string
	switch *arch {
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
		fmt.Fprintln(os.Stderr, "invalid arch", *arch)
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
		fmt.Printf("%s %s\n", strings.TrimSpace(legFlags(legToolchain, lfiflags)), extraflags[*toolchain])
		return
	}

	t, err := template.New("lfi").Parse(data)
	if err != nil {
		log.Fatal(err)
	}

	err = t.Execute(os.Stdout, Args{
		Arch:          arch,
		LfiFlags:      lfiflags,
		LegFlags:      legFlags(legToolchain, lfiflags, arch),
		ExtraFlags:    extraflags[*toolchain],
		Compiler:      *compiler,
		Toolchain:     legToolchain,
		PostlinkFlags: legFlags("postlink", lfiflags, arch),
		GnuArch:       lfiarch,
	})
	if err != nil {
		log.Fatal(err)
	}
}
