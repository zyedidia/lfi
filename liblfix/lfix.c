#include <stdbool.h>
#include <unistd.h>

#include "lfi.h"
#include "lfix.h"
#include "sys.h"

bool
lfix_init(LFIXEngine* lfix)
{
    LFIOptions options = (LFIOptions) {
        .pagesize = getpagesize(),
        .stacksize = mb(2),
        .syshandler = lfix_syscall,
    };

    LFIEngine* lfi = lfi_new(options);
    if (!lfi)
        return false;

    if (!lfi_reserve(lfi, gb(256))) {
        lfi_delete(lfi);
        return false;
    }

    return true;
}
