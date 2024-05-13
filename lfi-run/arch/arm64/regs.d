module arch.arm64.regs;

struct Context {
    ulong x30;
    ulong sp;
    ulong x19;
    ulong x20;
    ulong x21;
    ulong x22;
    ulong x23;
    ulong x24;
    ulong x25;
    ulong x26;
    ulong x27;
    ulong x28;
    ulong x29;
    ulong d8;
    ulong d9;
    ulong d10;
    ulong d11;
    ulong d12;
    ulong d13;
    ulong d14;
    ulong d15;
    void* spbase;
}

Context taskctx(void* sp, void* entry) {
    Context ctx;
    ctx.sp = cast(uintptr) sp;
    ctx.x30 = cast(uintptr) entry;
    return ctx;
}
