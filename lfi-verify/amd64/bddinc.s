.section .rodata

.align 4
.global lfi_bdd_data
lfi_bdd_data:
    .incbin "amd64/x86-all.bdd.bin"
.global lfi_bdd_data_end
lfi_bdd_data_end:
