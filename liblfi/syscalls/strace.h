#pragma once

#include "arch_sys.h"

#define STRACE_CASE(SYS)     \
    case TUX_SYS_##SYS: \
        return #SYS;

const char* sysname(uint64_t sysno);
