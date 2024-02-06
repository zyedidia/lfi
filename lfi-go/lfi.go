package lfi

import (
	"errors"
	"unsafe"

	"github.com/mattn/go-pointer"
	_ "github.com/zyedidia/lfi/liblfi"
)

/*
#cgo LDFLAGS: -llfiverify
#include "lfi.h"
uint64_t lfi_cb(void* ctxp, uint64_t num, uint64_t args[6]);
*/
import "C"

var (
	ErrNoMem        = errors.New("could not allocate memory")
	ErrNoSlot       = errors.New("no available process slots")
	ErrCannotMap    = errors.New("cannot memory map")
	ErrMaxVaspace   = errors.New("vaspace limit exceeded")
	ErrInvalidElf   = errors.New("invalid elf file")
	ErrVerify       = errors.New("verification failure")
	ErrProtection   = errors.New("invalid protection")
	ErrInvalidStack = errors.New("invalid stack")
	ErrUnknown      = errors.New("unknown error")
)

func cerr(cerr C.int) error {
	if cerr >= 0 {
		return nil
	}
	switch cerr {
	case C.LFI_ERR_NOMEM:
		return ErrNoMem
	case C.LFI_ERR_NOSLOT:
		return ErrNoSlot
	case C.LFI_ERR_CANNOT_MAP:
		return ErrCannotMap
	case C.LFI_ERR_MAX_VASPACE:
		return ErrMaxVaspace
	case C.LFI_ERR_INVALID_ELF:
		return ErrInvalidElf
	case C.LFI_ERR_VERIFY:
		return ErrVerify
	case C.LFI_ERR_PROTECTION:
		return ErrProtection
	case C.LFI_ERR_INVALID_STACK:
		return ErrInvalidStack
	}
	return ErrUnknown
}

type Info struct {
	Stack        []byte
	LastVa       uint64
	ElfEntry     uint64
	ElfBase      uint64
	ElfPhoff     uint64
	ElfPhnum     uint64
	ElfPhentSize uint64
}

type Options struct {
	NoVerify  bool
	FastYield bool
	PageSize  uint64
	StackSize uint64
	Syscall   func(ctx any, num uint64, args [6]uint64) int64
}

type Engine struct {
	lfi  *C.lfi_t
	opts Options
}

func NewEngine(opts Options) *Engine {
	var copts C.lfi_options_t
	copts.syscall_handler = C.rtcall_handler_f(C.lfi_cb)
	copts.page_size = C.uint64_t(opts.PageSize)
	copts.stack_size = C.uint64_t(opts.StackSize)
	copts.noverify = 0
	copts.fast_yield = 0
	return &Engine{
		lfi:  C.lfi_new(copts),
		opts: opts,
	}
}

func (e *Engine) AutoAddVaspaces() error {
	return cerr(C.lfi_auto_add_vaspaces(e.lfi))
}

func (e *Engine) MaxProcs() uint64 {
	return uint64(C.lfi_max_procs(e.lfi))
}

func (e *Engine) NumProcs() uint64 {
	return uint64(C.lfi_num_procs(e.lfi))
}

func (e *Engine) AddProc(prog []byte, ctx any) (*Proc, Info, error) {
	var cinfo C.lfi_proc_info_t
	var err C.int
	ctxp := pointer.Save(&callback{
		fn:   e.opts.Syscall,
		data: ctx,
	})
	proc := C.lfi_add_proc(e.lfi, (*C.uint8_t)(unsafe.Pointer(&prog[0])), C.size_t(len(prog)), ctxp, &cinfo, &err)
	if proc == nil {
		return nil, Info{}, cerr(err)
	}

	stack := unsafe.Slice((*byte)(cinfo.stack), cinfo.stack_size)

	return &Proc{
			proc: proc,
			ctxp: ctxp,
			Base: uintptr(C.lfi_proc_base(proc)),
		}, Info{
			Stack:        stack,
			LastVa:       uint64(cinfo.last_va),
			ElfEntry:     uint64(cinfo.elf_entry),
			ElfBase:      uint64(cinfo.elf_base),
			ElfPhoff:     uint64(cinfo.elf_phoff),
			ElfPhnum:     uint64(cinfo.elf_phnum),
			ElfPhentSize: uint64(cinfo.elf_phentsize),
		}, nil
}

func (e *Engine) RemoveProc(proc *Proc) {
	C.lfi_remove_proc(e.lfi, proc.proc)
}

type callback struct {
	fn   func(any, uint64, [6]uint64) int64
	data any
}

//export _lfi_go_cb
func _lfi_go_cb(v unsafe.Pointer, num C.uint64_t, a0, a1, a2, a3, a4, a5 C.uint64_t) C.uint64_t {
	cb := pointer.Restore(v).(*callback)
	return C.uint64_t(cb.fn(cb.data, uint64(num), [6]uint64{uint64(a0), uint64(a1), uint64(a2), uint64(a3), uint64(a4), uint64(a5)}))
}
