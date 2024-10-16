#include <unistd.h>

#include "sys.h"
#include "sobox.h"
#include "proc.h"

static size_t
gb(size_t x)
{
    return 1024 * 1024 * 1024 * x;
}

bool
sbx_init(Sobox* sbx)
{
    LFIOptions options = (LFIOptions) {
        .noverify = true,
        .pagesize = getpagesize(),
        .stacksize = 2 * MB,
        .syshandler = syshandler,
    };
    LFIEngine* engine = lfi_new(options);
    if (!engine)
        return false;
    sbx->lfimgr = engine;
    if (!lfi_reserve(engine, gb(256)))
        return false;
    fprintf(stderr, "libsobox: initialized\n");
    return true;
}

void
sbx_deinit(Sobox* sbx)
{
    lfi_delete(sbx->lfimgr);
}
