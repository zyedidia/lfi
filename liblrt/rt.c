#include <stdbool.h>
#include <unistd.h>

#include "lfi.h"
#include "lfi_rt.h"
#include "sys.h"

bool
lfi_rt_init(LFIRuntime* lrt)
{
    LFIOptions options = (LFIOptions) {
        .pagesize = getpagesize(),
        .stacksize = mb(2),
        .syshandler = lfi_rt_syscall,
    };

    LFIEngine* engine = lfi_new(options);
    if (!engine)
        return false;

    if (!lfi_reserve(engine, gb(256))) {
        lfi_delete(engine);
        return false;
    }

    return true;
}
