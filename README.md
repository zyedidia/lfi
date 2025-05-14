
<h1>LFI <img src="assets/lfi-logo.svg" alt="logo" width="30px"/></h1>

![Test Workflow](https://github.com/zyedidia/lfi/actions/workflows/test.yaml/badge.svg)
[![MPL License](https://img.shields.io/badge/license-MPL%202.0-blue)](https://github.com/zyedidia/lfi/blob/master/LICENSE)

LFI (Lightweight Fault Isolation) is a performant and secure software
sandboxing system targeting the ARM64 and x86-64 architectures. LFI allows you
to run ~64K (ARM64) or ~3K (x86-64) sandboxes in a single address space while
guaranteeing that the sandboxes cannot read or write each other's memory. Each
sandbox may be given up to 4GiB of memory. These sandboxes are very efficient:
on ARM64 they run with roughly 7% overhead compared to native code when
sandboxing reads and writes, and 1.5% overhead when only sandboxing writes
(x86-64 has slightly higher overheads). Since all sandboxes exist in the same
address space, context switches do not require changing the CPU's privilege
level (i.e., transitioning to kernel mode).

LFI's support for x86-64 is in-progress and does not yet include a complete
static verifier. The scalability limit of 3K sandboxes on x86-64 will also be
configurable, allowing up to 32K sandboxes at the cost of some additional
overhead. At the moment, we have measured overheads of ~9-10% on x86-64 for
full sandboxing.

# Tools

The LFI project provides the following tools:

* `lfi-leg`: reads a `.s` file, and produces an LFI-compatible `.s` file.
* `lfi-verify`: verifies ELF binaries for LFI-compatibility.
* `lfi-postlink`: patches binaries after linking (required for certain x86-64 optimizations).
* `lfi-run`: runs an LFI-compatible binary.

# Installation

There are two components to LFI: a compiler toolchain that can build
LFI-compatible binaries, and a runtime library for creating, verifying, and
managing sandboxes. For either of these components, you can either use prebuilt
versions provided with releases, or build from source.

## Prebuilt distribution

Prebuilt toolchains are provided in the GitHub releases:
https://github.com/zyedidia/lfi/releases/. The prebuilt toolchain includes a
full Clang compiler based on LLVM 19.

When you download a prebuilt toolchain, you will see the following directories:

* `lfi-bin/`: contains the LFI rewriter, verifier, and runtime. Put this on
  your `PATH`.
* `bin/`: contains the LLVM compiler binaries.
* `sysroot/`: contains the LFI sysroot, including libc, libc++, a dynamic
  linker, and additional runtime support libraries.

## Building from source

To build and install the LFI tools, run the following commands:

```
meson setup build --prefix=$PWD/install
cd build
ninja install
```

You will find the generated binaries, libraries, and headers in `$PWD/install`
(or in your prefix of choice). Before building a compiler toolchain, you should
make sure the installed `bin` directory is on your `PATH`.

Next, you might want to build a compiler toolchain based on LLVM or GCC. For
instructions and scripts, see [lfi-gcc](https://github.com/zyedidia/lfi-gcc)
and [lfi-llvm](https://github.com/zyedidia/lfi-llvm-toolchain).

# Example

Once you have installed all the tools, you can build simple programs.

```
#include <stdio.h>
int main() {
    printf("Hello from LFI\n");
    return 0;
}
```

With Clang:

```
$ aarch64-lfi-linux-musl-clang hello.c -O2 -o hello -static-pie
$ lfi-verify hello # check if it verifies (also performed by lfi-run)
verifying test
verification passed (3.2 MB/s)
$ lfi-run hello
Hello from LFI
```

And with GCC:

```
$ aarch64-lfi-linux-musl-gcc hello.c -O2 -o hello -static-pie
$ lfi-run hello
Hello from LFI
```

# Advanced Usage

The `lfi-leg` rewriter tool supports options for configuring the sandboxing approach.

```
Usage: lfi-leg [OPTION...] INPUT
lfi-gen: rewrite assembly files to be compatible with LFI

  -a, --arch=ARCH            Set the target architecture (arm64,amd64)
      --cfi=TYPE             Select CFI mechanism (bundle16,bundle32)
      --no-guard-elim        Do not run redundant guard elimination
      --no-segue             Do not use segment register to store the sandbox
                             base
  -o, --output=FILE          Output to FILE instead of standard output
      --poc                  Produce position-oblivious code (implies
                             --sys-external)
      --single-thread        Specify single-threaded target
      --sys-external         Store runtime call table outside sandbox
  -s, --sandbox=TYPE         Select sandbox type
                             (full,stores,bundle-jumps,none)
  -?, --help                 Give this help list
      --usage                Give a short usage message
```

Some notes:

* By default, LFI on x86-64 uses 16-byte bundles. We have measured better
  performance with 32-byte bundles on Intel machines, and better performance
  with 16-byte bundles on AMD machines. LFI does not use bundles on Arm64.
* The `--sandbox` option can be used to configure isolation granularity. With
  `stores`, only stores and control-flow is sandboxed. Programs are allowed to
  read outside of their memory. With `bundle-jumps`, LFI only enforces that
  bundles are the targets of jumps, but does not enforce that jumps are
  constrained to the sandbox, and does not enforce memory isolation.
* The `--single-thread` option in combination with `--sandbox=bundle-jumps`
  allows for more efficient return sequences, but is only applicable when
  sandboxed programs are single-threaded.

# Technical Summary

The LFI sandboxer only accepts ELF binaries that pass a verification step to
ensure they are safe to run. This verifier works by analyzing binary machine
code to ensure that the program will not access memory outside of its 4GiB
region or execute any system calls or other "unsafe" instructions. The verifier
is extremely simple, and is implemented in only a few hundred lines of code,
located in `lfi-verify/arm64/verify.c`. Thanks to the verifier, the compiler
used to generate the code is untrusted, so bugs in LLVM or GCC cannot cause
security vulnerabilities. This approach is both more secure and more performant
than current approaches that rely on a trusted compiler like Cranelift. The
verifier is also efficient, and can process machine code at a throughput of
100+ MiB/s on a Macbook Air.

In addition, LFI binaries may be generated by any LFI-compatible compiler
toolchain. LFI-compatible Clang and GCC toolchains are provided.

The core of the LFI toolchain is an assembly rewriter that reads arbitrary GNU
assembly files (`.s`) and produces assembly files that will pass verification
when compiled and linked. This rewriter is implemented as a set of PEG parsers
that are compiled to C using Leg, and consists of roughly 2,000 lines of code
total (ARM64 and x86-64). It is located in `lfi-leg/`.

LFI-compatible programs are performant: on the SPEC 2017 benchmark suite, we
measured a runtime overhead of 7% and a code size overhead of 14% for full
isolation. This compares well with LLVM-based ahead-of-time WebAssembly
compilers, which incur upwards of 20% runtime overhead. Additionally, LFI can
be used for pure fault isolation, where sandboxes may read, but not write,
each other's memory. In this case, we measured a runtime overhead of around
1.5%. LFI also compares well with Native Client (NaCl), the most widely-known
prior SFI system, which incurred around 16% overhead for full isolation and 7%
overhead for just stores on x86-64 SPEC benchmarks. NaCl never received Arm64
support before being deprecated.

LFI is also secure: the compiler toolchain used to
produce LFI-compatible programs is not a part of the trusted code base, and LFI
is significantly more Spectre-resistant compared to WebAssembly.

LFI supports all source-level language features and targets the ARMv8.0-A ISA
(including SIMD) plus the ARMv8.1 LSE extension.

The last component of an LFI system is the runtime, which loads programs and
handles runtime calls (e.g., syscalls) on their behalf. To create your own
runtime, you can use `liblfi`, which provides utility functions for creating and
running sandboxes, and handling runtime calls (it is up to you what runtime
calls are available and what they do).

The `lfi-run` program is an example LFI runtime that behaves like a subset of
Linux, and can be used to run many programs compiled for Linux with an LFI
toolchain. This runtime is useful for running benchmarks such as SPEC 2017.

LFI is currently in development and is a research project.

# Library Sandboxing

By default, the LFI compiler produces executables that you can run in a
sandboxed environment. To adapt this model to library sandboxing, a tool called
[lfi-bind](https://github.com/zyedidia/lfi-bind) can be used to generate bindings for
a library compiled with LFI so that functions within the sandbox can be invoked
by a host. Since the LFI sandbox runs within a single process, invoking a
sandboxed function is very cheap -- roughly 20-40 cycles.

## Specification

LFI's current sandboxing schemes for Arm64 and x86-64 are documented in the
[LFI specification](https://www.scs.stanford.edu/~zyedidia/docs/lfi/lfi-spec.pdf).

# Publication

Zachary Yedidia. "Lightweight Fault Isolation: Practical, Efficient, and Secure Software Sandboxing." ASPLOS 2024. [Link](https://zyedidia.github.io/papers/lfi_asplos24.pdf).

# Roadmap

The LFI project is currently under development. Here are some directions we are
interested in (some of which are being actively developed):

* Integration with library sandboxing tools.
* New capabilities and full security for the runtime.
* Optimized integration with WebAssembly (efficiently run WebAssembly inside LFI).
* Support for dynamic recompilation to other architectures.
* Native support for RISC-V.
* Instrumentation of static binaries, so you don't need to recompile your program.
* Support for Arm software context IDs for mitigating Spectre attacks (requires
  modifications to Linux, which Arm will hopefully implement soon).
