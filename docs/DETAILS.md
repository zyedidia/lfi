# Technical Summary

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

# Publications

The following papers describe the LFI scheme in more detail. The first describes the Arm64 scheme, and the second describes an optimization for x86-64 that we use. For more details about the x86-64 mechanism see the [short paper](https://www.scs.stanford.edu/~zyedidia/docs/papers/lfi-short.pdf) as well as prior work on [Google Native Client](https://www.scs.stanford.edu/~zyedidia/docs/papers/nacl2.pdf).

* Zachary Yedidia. "Lightweight Fault Isolation: Practical, Efficient, and Secure Software Sandboxing." ASPLOS 2024. [Link](https://zyedidia.github.io/papers/lfi_asplos24.pdf).
* Shravan Narayan, Tal Garfinkel, Evan Johnson, Zachary Yedidia, Yingchen Wang, Andrew Brown, Anjo Vahldiek-Oberwagner, Michael LeMay, Wenyong Huang, Xin Wang, Mingqiu Sun, Dean Tullsen, Deian Stefan. "Segue & ColorGuard: Optimizing SFI Performance and Scalability on Modern Architectures." ASPLOS 2025. [Link](https://zyedidia.github.io/papers/seguecg.pdf).
