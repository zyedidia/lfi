# Lightweight Fault Isolation (LFI)

Welcome to the home of the Lightweight Fault Isolation (LFI) project. The
project is hosted on GitHub in the https://github.com/lfi-project organization.
This repository contains information and tutorials about how to use LFI.

The GitHub organization has several repositories for the different components of LFI:

* [`lfi-runtime`](https://github.com/lfi-project/lfi-runtime): the runtime responsible for loading LFI programs, handling host calls, and running verification.
* [`lfi-verifier`](https://github.com/lfi-project/lfi-verifier): the LFI verifier.
* [`lfi-rewriter`](https://github.com/lfi-project/lfi-rewriter): the LFI rewriter for GNU assembly, and a post-linker tool for performing binary transformations after linking (only necessary on x86-64).
* [`lfi-bind`](https://github.com/lfi-project/lfi-bind): a tool for generating trampolines and initialization routines for running libraries inside of LFI sandboxes.
* [`lfi-llvm-toolchain`](https://github.com/lfi-project/lfi-llvm-toolchain): scripts for building an LLVM-based LFI compiler toolchain, along with a sysroot including compiler-rt, musl, libc++, and mimalloc.
* [`llvm-project`](https://github.com/lfi-project/llvm-project): our development fork of the LLVM project.
* [`lfi-specification`](https://github.com/lfi-project/lfi-specification): the LaTeX sources for the LFI specification document.

As a research project, the LFI implementation initially existed in the
https://github.com/zyedidia/lfi repository. See the `lfi-research` branch of
this repository for that version.

# What is LFI?

LFI (Lightweight Fault Isolation) is a performant and secure software
sandboxing system targeting the Arm64 and x86-64 architectures. LFI allows you
to run ~64K (Arm64) or ~3K (x86-64) sandboxes in a single address space while
guaranteeing that the sandboxes cannot read or write each other's memory. Each
sandbox may be given up to 4GiB of memory. These sandboxes are very efficient:
they run with roughly 7% (Arm64)/8% (x86-64) overhead compared to native code
when sandboxing reads and writes, and 1.5% (Arm64)/6% (x86-64) overhead when
only sandboxing writes, measured on SPEC 2017. Since all sandboxes exist in the
same address space, context switches do not require changing the CPU's
privilege level (i.e., transitioning to kernel mode).

# Getting Started

To get started with LFI, you'll need an LFI compiler. You can get one from
https://github.com/lfi-project/lfi-llvm-toolchain. Prebuilt compilers aarch64
and x86-64 compilers are hosted in the releases:
https://github.com/lfi-project/lfi-llvm-toolchain/releases/latest. Download
the `aarch64-lfi-clang.tar.gz` or `x86_64-lfi-clang.tar.gz` bundle, depending
on your architecture (or `aarch64-lfi-clang-host-x86_64.tar.gz` if you want to
cross compile to aarch64 from x86-64).

After opening the archive, you should see a directory structure like this:

```
├── bin
│   ├── LLVM tools (clang, lld, ...)
├── include
├── lfi-bin
│   ├── lfi-postlink
│   ├── lfi-rewrite
│   ├── lfi-run
│   ├── lfi-verify
│   ├── ARCH-lfi-linux-musl-clang -> ../bin/clang
│   └── ARCH-lfi-linux-musl-clang++ -> ../bin/clang++
├── lfi-clang
│   ├── ARCH-lfi-linux-musl-clang -> ../bin/clang
│   └── ARCH-lfi-linux-musl-clang++ -> ../bin/clang++
├── lib
├── libexec
├── share
└── sysroot
```

You'll want to add the `lfi-bin` directory to your `PATH`. If you already have
the LFI tools installed via a separate installation, consider only adding
`lfi-clang` to your `PATH` instead.

Once you have a compiler, you should be able to build a simple C or C++ program:

```c
#include <stdio.h>
int main() {
    printf("Hello from LFI\n");
    return 0;
}
```

Compile and run using `lfi-run`:

```
$ aarch64-lfi-linux-musl-clang hello.c -O2 -o hello -static-pie
$ lfi-run -v ./hello
Hello from LFI
```

You can use the prebuilt `lfi-run` tool from the prebuilt archive. You can also
easily build the LFI runtime from source:

```
git clone https://github.com/lfi-project/lfi-runtime
cd lfi-runtime
meson setup build
cd build
ninja
./tools/lfi-run/lfi-run ...
```

The `lfi-run` tool is primarily meant for benchmarking and testing. It does not
run verification by default (pass `-v` to enable), and it allows full
filesystem access by default. See the usage (`lfi-run --help`) for more
information.

# Next Steps

After building and running your first LFI program, you may want to pursue
several further directions. See the following guides for some suggestions:

* Setting up benchmarking with SPEC 2017 and `lfi-bench`: [guide](docs/BENCHMARKING.md).
* Using LFI to sandbox libraries: [guide](docs/LIBRARIES.md).
* Learning more about how LFI works: [guide](docs/DETAILS.md).
