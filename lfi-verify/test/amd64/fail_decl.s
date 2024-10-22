// flags: --decl
.bundle_align_mode 4
foo:
div %rdi, %rax
jz foo
ret
