module object;

alias string = const(char)[];
alias usize = typeof(int.sizeof);
alias size_t = usize;

alias noreturn = typeof(*null);

static if ((void*).sizeof == 8) {
    alias uintptr = ulong;
    alias ssize = long;
} else static if ((void*).sizeof == 4) {
    alias uintptr = uint;
    alias ssize = int;
} else {
    static assert(0, "pointer size must be 4 or 8 bytes");
}

pragma(printf)
extern (C) void printf(const(char)* fmt, ...);

pragma(printf)
extern (C) void fprintf(void* stream, const(char)* fmt, ...);

struct Empty {}

void ensure(bool b, string msg = "ensure failure", string file = __FILE__, int line = __LINE__) {
    import core.exception : panic;
    if (!b) {
        panic(file, line, msg);
    }
}

bool __equals(scope const string lhs, scope const string rhs) {
    if (lhs.length != rhs.length)
        return false;
    for (usize i = 0; i < lhs.length; i++) {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

version (page16k) {
    enum PAGESIZE = 4096 * 4;
} else {
    enum PAGESIZE = 4096;
}
