The implementation of LFI is in the process of being moved to
https://github.com/lfi-project. Please see the README there for up-to-date
information, reproduced below.

# LFI

Welcome to the home of the LFI (Lightweight Fault Isolation) project. The organization https://github.com/lfi-project holds the repositories that make up the various components of LFI.

* `lfi-runtime`: the runtime responsible for loading LFI programs, handling host calls, and running verification.
* `lfi-verifier`: the LFI verifier.
* `lfi-rewriter`: the LFI rewriter for GNU assembly, and a post-linker tool for performing binary transformations after linking (only necessary on x86-64).
* `lfi-bind`: a tool for generating trampolines and initialization routines for running libraries inside of LFI sandboxes.
* `lfi-llvm-toolchain`: scripts for building an LLVM-based LFI compiler toolchain, along with a sysroot including compiler-rt, musl, libc++, and mimalloc.
* `lfi-bench`: a set of libraries with build scripts for LFI and small benchmarks.
* `llvm-project`: our development fork of the LLVM project.
* `lfi-specification`: the LaTeX sources for the LFI specification document.

See https://github.com/zyedidia/lfi for the older research repository, where we also keep various experimental features. That repository will be moved/merged into this organization in the future.

# What is LFI?

LFI (Lightweight Fault Isolation) is a performant and secure software
sandboxing system targeting the Arm64 and x86-64 architectures. LFI allows you
to run ~64K (Arm64) or ~3K (x86-64) sandboxes in a single address space while
guaranteeing that the sandboxes cannot read or write each other's memory. Each
sandbox may be given up to 4GiB of memory. These sandboxes are very efficient:
they run with roughly 7% (Arm64)/8% (x86-64) overhead compared to native code when
sandboxing reads and writes, and 1.5% (Arm64)/6% (x86-64) overhead when only sandboxing writes, measured on SPEC 2017.
Since all sandboxes exist in the same
address space, context switches do not require changing the CPU's privilege
level (i.e., transitioning to kernel mode).

## Technical Summary

LFI works primarily via three components: the compiler, the verifier, and the runtime. When targeting LFI you must compile your program for the LFI target,
which applies a set of simple rewrites on the generated assembly to ensure that the generated assembly is secure. The LFI compiler can compile a wide variety
of unmodified input programs, including those that make extensive use hand-written assembly. The LFI compiler is currently implemented as a modification to LLVM
that invokes a text-based GNU assembly rewriting tool at the assembler stage.

Compiling a program for the LFI target produces an ELF file. Once you have done so it can be loaded and run by the LFI runtime. Since the program is untrusted and
potentially malicious, the runtime applies the LFI verifier to the program before loading it into executable memory. The verifier is a trusted program and ensures
that all security invariants of the sandbox are maintained by the untrusted program. These invariants include things like: not loading/storing any memory more than 4GiB
beyond the base of the sandbox, not modifying certain reserved registers, not branching to any system call instructions or other unsafe instructions, etc...

Once verification passes, the runtime begins executing the program and is responsible for handling any host calls (calls into the runtime) that it makes. By default, the runtime
performs Linux emulation, with support for a subset of Linux system calls, allowing you to run Linux programs within an LFI sandbox.

For more detailed two-page description of LFI for Arm64 and x86-64, please see this [short paper](https://www.scs.stanford.edu/~zyedidia/docs/papers/lfi-short.pdf).

LFI's current sandboxing schemes for Arm64 and x86-64 are documented in the [LFI specification](https://www.scs.stanford.edu/~zyedidia/docs/lfi/lfi-spec.pdf).

# Example

After installing the LFI compiler (see [lfi-llvm-toolchain](https://github.com/lfi-project/lfi-llvm-toolchain) for details) and installing the LFI runtime (see [lfi-runtime](https://github.com/lfi-project/lfi-runtime)), you can build and run your first LFI program.

```c
#include <stdio.h>
int main() {
    printf("Hello from LFI\n");
    return 0;
}
```

Compile:

```
$ aarch64-lfi-linux-musl-clang hello.c -O2 -o hello -static-pie
$ lfi-run -v hello
Hello from LFI
```

# Publications

The following papers describe the LFI scheme in more detail. The first describes the Arm64 scheme, and the second describes an optimization for x86-64 that we use. For more details about the x86-64 mechanism see the [short paper](https://www.scs.stanford.edu/~zyedidia/docs/papers/lfi-short.pdf) as well as prior work on [Google Native Client](https://www.scs.stanford.edu/~zyedidia/docs/papers/nacl2.pdf).

* Zachary Yedidia. "Lightweight Fault Isolation: Practical, Efficient, and Secure Software Sandboxing." ASPLOS 2024. [Link](https://zyedidia.github.io/papers/lfi_asplos24.pdf).
* Shravan Narayan, Tal Garfinkel, Evan Johnson, Zachary Yedidia, Yingchen Wang, Andrew Brown, Anjo Vahldiek-Oberwagner, Michael LeMay, Wenyong Huang, Xin Wang, Mingqiu Sun, Dean Tullsen, Deian Stefan. "Segue & ColorGuard: Optimizing SFI Performance and Scalability on Modern Architectures." ASPLOS 2025. [Link](https://zyedidia.github.io/papers/seguecg.pdf).
