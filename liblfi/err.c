#include "err.h"
#include "lfi.h"

_Thread_local int lfi_errno;

int
lfi_err()
{
    return lfi_errno;
}

char*
lfi_strerror()
{
    switch (lfi_errno) {
    case LFI_ERR_NOMEM:
        return "out of memory";
    case LFI_ERR_NOSLOT:
        return "no sandbox slot available";
    case LFI_ERR_CANNOT_MAP:
        return "mmap returned error";
    case LFI_ERR_MAX_SPACE:
        return "no more address spaces available";
    case LFI_ERR_INVALID_ELF:
        return "invalid ELF file";
    case LFI_ERR_VERIFY:
        return "verification failed";
    case LFI_ERR_PROTECTION:
        return "invalid protection";
    case LFI_ERR_INVALID_STACK:
        return "invalid stack";
    case LFI_ERR_SYSTEM:
        return "system call returned an error";
    case LFI_ERR_NOVERIFIER:
        return "no verifier provided";
    case LFI_ERR_INVALID_GAS:
        return "gas is not available on this system";
    case LFI_ERR_NOSYSHANDLER:
        return "no runtime call handler provided";
    case LFI_ERR_INVALID_UPROC:
        return "invalid uproc parameters";
    case LFI_ERR_UPROC_SEG:
        return "ELF segment doesn't map to pre-allocated location";
    }
    return "unknown error";
}
