module arch.amd64.regs;

struct Context {
    ulong rsp;
    ulong r15;
    ulong r14;
    ulong r13;
    ulong r12;
    ulong rbx;
    ulong rbp;
    ulong gs;
}

void* stackpush(void* sp, void* value) {
    void** spp = cast(void**) sp;
    *(--spp) = value;
    return cast(void*) spp;
}

Context taskctx(void* sp, void* entry) {
    Context ctx;
    sp = stackpush(sp, null);
    ctx.rsp = cast(uintptr) stackpush(sp, entry);
    ctx.rbp = ctx.rsp;
    return ctx;
}
