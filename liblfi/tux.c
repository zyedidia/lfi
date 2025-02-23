#include <stdlib.h>

#include "config.h"
#include "lfi_tux.h"
#include "host.h"
#include "lfi.h"
#include "proc.h"
#include "sys.h"
#include "engine.h"

#include "arch_sys.h"

#ifdef CONFIG_GDB
#define LIBBREAKPOINT_DEFAULT_DISABLED
#include "breakpoint.h"
#endif

EXPORT void
lfi_tux_syscall(struct LFIContext* ctx)
{
    arch_syshandle(ctx);
}

EXPORT struct Tux*
lfi_tux_new(struct LFIPlatform* plat, struct TuxOptions opts)
{
#ifdef CONFIG_GDB
    if (opts.gdbfile)
        start_libbreakpoint();
#endif

    struct Tux* tux = malloc(sizeof(struct Tux));
    if (!tux)
        return NULL;
    *tux = (struct Tux) {
        .plat = plat,
        .opts = opts,
    };

    tux->fstdin = filefnew(host_stdin(), TUX_O_RDONLY);
    if (!tux->fstdin)
        goto err1;
    tux->fstdout = filefnew(host_stdout(), TUX_O_WRONLY);
    if (!tux->fstdout)
        goto err2;
    tux->fstderr = filefnew(host_stderr(), TUX_O_WRONLY);
    if (!tux->fstderr)
        goto err3;
    // Bump reference counts to represent libtux's references.
    tux->fstdin->refs++;
    tux->fstdout->refs++;
    tux->fstderr->refs++;

    lfi_sys_handler(plat, &lfi_tux_syscall);
    return tux;
err3:
    free(tux->fstdout);
err2:
    free(tux->fstdin);
err1:
    free(tux);
    return NULL;
}

EXPORT uint64_t
lfi_tux_proc_run(struct TuxThread* p)
{
    return lfi_ctx_run(p->p_ctx, p->proc->p_as);
}

EXPORT void
lfi_tux_soboxinit(struct Tux* tux, bool val)
{
    tux->opts.soboxinit = val;
}
