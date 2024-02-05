package lfi

import (
	"reflect"
	"unsafe"

	_ "github.com/zyedidia/lfi/liblfi"
)

// #include "lfi.h"
import "C"

type Proc struct {
	proc *C.lfi_proc_t
}

func (p *Proc) Start(entry uint64, stack []byte) {
	sh := (*reflect.SliceHeader)(unsafe.Pointer(&stack))
	C.lfi_proc_start(p.proc, C.uintptr_t(entry), unsafe.Pointer(sh.Data), C.size_t(sh.Len))
}
