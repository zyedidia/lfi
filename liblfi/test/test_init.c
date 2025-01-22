#include <assert.h>
#include <unistd.h>

#include "lfi.h"

int
main()
{
    size_t pagesize = getpagesize();
    struct LFIPlatform* plat = lfi_new_plat(pagesize);
    assert(plat);
    struct LFIAddrSpace* as = lfi_as_new(plat);
    assert(as);
    struct LFIContext* ctx = lfi_ctx_new(as, NULL, true);
    assert(ctx);

    lfi_ctx_free(ctx);

    return 0;
}
