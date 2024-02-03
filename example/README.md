# Example

This example shows how to write a program that uses `liblfi` to load and run
simple LFI binaries. The `hello.c` program is compiled with LFI, and loaded by
the `run.c` program by using `liblfi`. The program invokes a system call that
gets handled by `run.c`.
