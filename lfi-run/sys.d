module sys;

pragma(inline, true)
usize kb(usize i) {
    return i * 1024;
}

pragma(inline, true)
usize mb(usize i) {
    return i * 1024 * 1024;
}

pragma(inline, true)
usize gb(usize i) {
    return i * 1024 * 1024 * 1024;
}

pragma(inline, true)
usize tb(usize i) {
    return i * 1024 * 1024 * 1024 * 1024;
}

const char[] GenSysReg(string name) = GenSysRegRdOnly!(name) ~ GenSysRegWrOnly!(name);
const char[] GenSysRegRdOnly(string name) =
`pragma(inline, true) ` ~
`static uintptr ` ~ name ~ `() {
    uintptr val;
    asm {
        "mrs %0, ` ~ name ~ `" : "=r"(val);
    }
    return val;
}`;
const char[] GenSysRegWrOnly(string name) =
`pragma(inline, true) ` ~
`static void ` ~ name ~ `(uintptr v) {
    asm {
        "msr ` ~ name ~ `, %0" : : "r"(v);
    }
}`;

struct SysReg {
    mixin(GenSysReg!("tpidr_el0"));
}
