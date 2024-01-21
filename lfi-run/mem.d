module mem;

struct MemRegion {
    ulong base;
    usize len;
    int prot;
}
