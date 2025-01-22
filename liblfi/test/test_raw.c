#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#include "lfi.h"

struct Proc {
    struct LFIAddrSpace* as;
    struct LFIContext* ctx;
};

static struct Proc*
mkproc(struct LFIPlatform* plat)
{
    struct Proc* p = malloc(sizeof(struct Proc));
    assert(p);

    struct LFIAddrSpace* as = lfi_as_new(plat);
    assert(as);
    struct LFIContext* ctx = lfi_ctx_new(as, p, true);
    assert(ctx);

    *p = (struct Proc) {
        .as = as,
        .ctx = ctx,
    };

    return p;
}

static void
handle_syscall(struct LFIContext* ctx)
{
    int sysno;
#if defined(__aarch64__) || defined(_M_ARM64)
    sysno = lfi_ctx_regs(ctx)->x8;
#elif defined(__x86_64__) || defined(_M_X64)
    sysno = lfi_ctx_regs(ctx)->rax;
#endif
    printf("%d\n", sysno);
    lfi_ctx_exit(ctx, sysno);
}

struct Buf {
    void* data;
    size_t size;
};

static struct Buf
readfile(char* path)
{
    FILE* f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Cannot open %s\n", path);
        return (struct Buf){0};
    }
    fseek(f, 0, SEEK_END);
    size_t sz = ftell(f);
    void* p = mmap(NULL, sz, PROT_READ, MAP_PRIVATE, fileno(f), 0);
    assert(p != (void*) -1);
    fclose(f);
    return (struct Buf) {
        .data = p,
        .size = sz,
    };
}

int
main(int argc, char** argv)
{
    if (argc <= 1) {
        fprintf(stderr, "no input\n");
        return 1;
    }

    size_t pagesize = getpagesize();
    struct LFIPlatform* plat = lfi_new_plat(pagesize);
    struct Proc* p = mkproc(plat);

    struct Buf prog = readfile(argv[1]);

    struct LFILoadInfo info;
    bool ok = lfi_proc_loadelf(p->as, (uint8_t*) prog.data, prog.size, NULL, 0, &info, (struct LFILoadOpts) {
        .stacksize = 2 * 1024 * 1024,
        .pagesize = pagesize,
    });
    assert(ok);

    ok = lfi_proc_init(p->ctx, p->as, info);
    assert(ok);

    lfi_sys_handler(plat, &handle_syscall);

    lfi_ctx_run(p->ctx, p->as);

    return 0;
}
