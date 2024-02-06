package lfi

import (
	"unsafe"

	_ "github.com/zyedidia/lfi/liblfi"
)

// #include "lfi.h"
import "C"

type Proc struct {
	proc *C.lfi_proc_t
	ctxp unsafe.Pointer
	Base uintptr
}

func (p *Proc) Start(entry uint64, stack []byte) {
	C.lfi_proc_start(p.proc, C.uintptr_t(entry), unsafe.Pointer(unsafe.SliceData(stack)), C.size_t(len(stack)))
}
