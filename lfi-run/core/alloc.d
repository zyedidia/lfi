module core.alloc;

import core.emplace;
import core.lib : malloc, memset, free, aligned_alloc;

void* kallocpage() {
    ubyte[] b = kzalloc(PAGESIZE);
    if (!b)
        return null;
    return b.ptr;
}

ubyte[] kalloc(usize sz) {
    ubyte* p = void;
    if (sz >= PAGESIZE) {
        // always align to pagesize if the size is large enough
        p = cast(ubyte*) aligned_alloc(PAGESIZE, sz);
    } else {
        p = cast(ubyte*) malloc(sz);
    }
    if (!p)
        return null;
    return p[0 .. sz];
}

ubyte[] kzalloc(usize sz) {
    ubyte[] mem = kalloc(sz);
    if (!mem)
        return null;
    memset(mem.ptr, 0, mem.length);
    return mem;
}

T* knew(T)() {
    T* p = cast(T*) aligned_alloc(T.alignof, T.sizeof);
    if (!p) {
        return null;
    }
    if (!emplace_init(p)) {
        free(p);
        return null;
    }
    return p;
}

T[] kallocarray(T)(usize nelem) {
    T* p = cast(T*) aligned_alloc(T.alignof, T.sizeof * nelem);
    if (!p) {
        return null;
    }
    return p[0 .. nelem];
}

void kfree(void* ptr) {
    if (!ptr)
        return;
    free(ptr);
}

void kfree(T)(T* ptr) if (is(T == struct)) {
    if (!ptr)
        return;
    static if (HasDtor!(T)) {
        ptr.__xdtor();
    }
    free(ptr);
}

void kfree(T)(T[] arr) {
    if (!arr)
        return;
    static if (HasDtor!(T)) {
        foreach (ref val; arr) {
            val.__xdtor();
        }
    }
    free(arr.ptr);
}
