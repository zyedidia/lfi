#include <unistd.h>

#include "sys.h"
#include "sobox.h"
#include "proc.h"

bool
sbx_init(Sobox* sbx, uint8_t* (*readfile)(const char* filename, size_t* size))
{
    struct lfi_options options = (struct lfi_options) {
        .noverify = true,
        .pagesize = getpagesize(),
        .stacksize = 2 * MB,
        .syshandler = syshandler,
    };
    struct lfi* engine = lfi_new(options);
    if (!engine)
        return false;
    sbx->lfimgr = engine;
    sbx->readfile = readfile;
    if (lfi_auto_add_vaspaces(sbx->lfimgr, 16 * PROCSIZE) < 0)
        return false;
    return true;
}

void
sbx_deinit(Sobox* sbx)
{
    lfi_delete(sbx->lfimgr);
}
