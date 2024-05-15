module core.math;

pragma(inline, true)
ulong kb(ulong n) {
    return 1024 * n;
}
pragma(inline, true)
ulong mb(ulong n) {
    return 1024 * 1024 * n;
}
pragma(inline, true)
ulong gb(ulong n) {
    return 1024 * 1024 * 1024 * n;
}

T min(T, U)(T a, U b) if (is(T == U) && is(typeof(a < b))) {
    return b < a ? b : a;
}

T max(T, U)(T a, U b) if (is(T == U) && is(typeof(a < b))) {
    return a < b ? b : a;
}

uintptr trunc(uintptr addr, usize align_) {
    usize align_mask = align_ - 1;
    return addr & ~align_mask;
}

uintptr ceil(uintptr addr, usize align_) {
    usize align_mask = align_ - 1;
    return (addr + align_mask) & ~align_mask;
}

uintptr truncpg(uintptr addr) {
    return trunc(addr, PAGESIZE);
}

uintptr ceilpg(uintptr addr) {
    return ceil(addr, PAGESIZE);
}
