module proc;

import core.lib;
import core.alloc;
import core.vector;
import core.size;

import arch.regs;

import sys;
import sched;
import lfi;
import fd;
import queue;
import elf;
import cwalk;
import buddy;
import main;

enum PState {
    RUNNABLE,
    BLOCKED,
    EXITED,
}

enum {
    KSTACKSIZE = kb!(64),

    ARGC_MAX = 1024,
    ARGV_MAX = 1024,

    BRKMAXSIZE = mb!(512),

    PROCSIZE = gb!(4),
}

struct Cwd {
    char[PATH_MAX] name;
    int fd;
}

void cwdcopy(Cwd* cwd, ref Cwd to) {
    int fd = open(cwd.name.ptr, O_DIRECTORY | O_PATH, 0);
    ensure(fd >= 0);
    memcpy(to.name.ptr, cwd.name.ptr, cwd.name.length);
    to.fd = fd;
}

struct MMap {
    uintptr base;
    usize size;
    int prot;
    bool fixed;
}

struct Proc {
    Context ctx;
    LFIProc* lp;
    uintptr base;
    PState state;
    void* wq;
    Proc* next;
    Proc* prev;

    FDTable fdtable;
    Cwd cwd;

    Proc* parent;
    Vector!(Proc*) children;

    uintptr brkbase;
    usize brksize;
    void* mapalloc;
    uintptr mapbase;
    usize mapsize;
    Vector!(MMap) maps;

    align(16) ubyte[KSTACKSIZE] kstack;
}

Proc* procnewempty() {
    Proc* p = knew!(Proc)();
    if (!p)
        return null;
    p.ctx = taskctx(&p.kstack[$-16], &procentry);
    p.cwd.fd = AT_FDCWD;
    ensure(getcwd(&p.cwd.name[0], p.cwd.name.length) != null);
    return p;
}

Proc* procnewchild(Proc* parent) {
    bool success;
    Proc* p = procnewempty();
    if (!p)
        return null;
    scope(exit) if (!success) procfree(p);

    ubyte* meta = kalloc(buddy_sizeof_alignment(parent.mapsize, PAGESIZE)).ptr;
    if (!meta)
        return null;
    scope(exit) if (!success) kfree(meta);

    if (lfi_proc_copy(lfiengine, &p.lp, parent.lp, p) < 0)
        return null;
    p.base = lfi_proc_base(p.lp);

    fdcopy(&parent.fdtable, p.fdtable);
    cwdcopy(&parent.cwd, p.cwd);
    p.brkbase = procaddr(p, parent.brkbase);
    p.brksize = parent.brksize;
    if (p.brksize != 0) {
        ensure(mmap(cast(void*) p.brkbase, p.brksize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0) != cast(void*) -1);
        memcpy(cast(void*) p.brkbase, cast(void*) parent.brkbase, p.brksize);
    }
    p.mapbase = procaddr(p, parent.mapbase);
    p.mapsize = parent.mapsize;
    p.mapalloc = buddy_copy(meta, cast(void*) p.mapbase, parent.mapalloc);
    assert(p.mapalloc); // buddy_copy should always succeed
    p.parent = parent;
    p.state = PState.RUNNABLE;

    success = true;
    return p;
}

Proc* procnewfile(const(char)* path, int argc, const(char)** argv) {
    bool success;

    Proc* p = procnewempty();
    if (!p)
        return null;
    scope(exit) if (!success) procfree(p);

    int err = lfi_add_proc(lfiengine, &p.lp, p);
    if (err < 0)
        return null;
    p.base = lfi_proc_base(p.lp);

    if (!procfile(p, path, argc, argv))
        return null;
    fdinit(&p.fdtable);

    success = true;
    return p;
}

void procfreemaps(Proc* p) {
    if (p.brksize > 0)
        ensure(munmap(cast(void*) p.brkbase, p.brksize) == 0);
    foreach (ref map; p.maps) {
        mapunmap(p, map);
    }
    p.maps.clear();
    kfree(p.mapalloc);
}

void procfree(Proc* p) {
    procfreemaps(p);
    if (p.lp)
        lfi_remove_proc(lfiengine, p.lp);
    fdclear(&p.fdtable, p);
    if (p.cwd.fd >= 0)
        close(p.cwd.fd);
    kfree(p);
}

bool procfile(Proc* p, const(char)* path, int argc, const(char)** argv) {
    int fd = openat(p.cwd.fd, path, O_RDONLY, 0);
    if (fd < 0)
        return false;
    void* f = fdopen(fd, "rb");
    if (!f)
        return false;
    ubyte[] buf = readfile(f);
    if (!buf)
        return false;
    ensure(fclose(f) == 0);
    scope(exit) kfree(buf);

    if (!procsetup(p, buf, argc, argv))
        return false;

    return true;
}

bool procmapsetup(Proc* p, uintptr mapstart, uintptr mapend) {
    bool success;

    ubyte* meta = kalloc(buddy_sizeof_alignment(mapend - mapstart, PAGESIZE)).ptr;
    if (!meta)
        return false;
    scope(exit) if (!success) kfree(meta);

    p.mapalloc = buddy_init_alignment(meta, cast(void*) mapstart, mapend - mapstart, PAGESIZE);
    if (!p.mapalloc)
        return false;

    p.mapbase = mapstart;
    p.mapsize = mapend - mapstart;

    success = true;
    return true;
}

bool stacksetup(Proc* p, int argc, const(char)** argv, ref LFIProcInfo info, out uintptr newsp) {
    // Set up argv.
    char*[ARGC_MAX] argv_ptrs;

    void* stack_top = info.stack + info.stacksize;
    char* p_argv = cast(char*) stack_top - PAGESIZE;

    // Write argv string values to the stack.
    for (int i = 0; i < argc; i++) {
        usize len = strnlen(argv[i], ARGV_MAX) + 1;

        if (p_argv + len >= stack_top) {
            return false;
        }

        memcpy(p_argv, argv[i], len);
        p_argv[len - 1] = 0;
        argv_ptrs[i] = p_argv;
        p_argv += len;
    }

    // Write argc and argv pointers to the stack.
    long* p_argc = cast(long*) (stack_top - 2 * PAGESIZE);
    newsp = cast(uintptr) p_argc;
    *p_argc++ = argc;
    char** p_argvp = cast(char**) p_argc;
    for (int i = 0; i < argc; i++) {
        if (cast(uintptr) p_argvp >= cast(uintptr) stack_top - PAGESIZE) {
            return false;
        }
        p_argvp[i] = cast(char*) procuseraddr(p, cast(uintptr) argv_ptrs[i]);
    }
    p_argvp[argc] = null;
    // Empty envp.
    char** p_envp = cast(char**) &p_argvp[argc + 1];
    *p_envp++ = null;

    // Set up auxv.
    Auxv* av = cast(Auxv*) p_envp;
    *av++ = Auxv(AT_SECURE, 0);
    *av++ = Auxv(AT_BASE, procuseraddr(p, info.elfbase));
    *av++ = Auxv(AT_PHDR, procuseraddr(p, info.elfbase + info.elfphoff));
    *av++ = Auxv(AT_PHNUM, info.elfphnum);
    *av++ = Auxv(AT_PHENT, info.elfphentsize);
    *av++ = Auxv(AT_ENTRY, procuseraddr(p, info.elfentry));
    *av++ = Auxv(AT_EXECFN, procuseraddr(p, cast(ulong) p_argvp[0]));
    *av++ = Auxv(AT_PAGESZ, PAGESIZE);
    *av++ = Auxv(AT_HWCAP, 0x0);
    *av++ = Auxv(AT_HWCAP2, 0x0);
    *av++ = Auxv(AT_FLAGS, 0x0);
    *av++ = Auxv(AT_UID, 1000);
    *av++ = Auxv(AT_EUID, 1000);
    *av++ = Auxv(AT_GID, 1000);
    *av++ = Auxv(AT_EGID, 1000);
    *av++ = Auxv(AT_NULL, 0);
    return true;
}

bool procsetup(Proc* p, ubyte[] buf, int argc, const(char)** argv) {
    bool success;

    LFIProcInfo info;
    lfi_proc_exec(p.lp, buf.ptr, buf.length, &info);

    uintptr sp;
    if (!stacksetup(p, argc, argv, info, sp))
        return false;

    lfi_proc_init_regs(p.lp, info.elfentry, sp);

    p.brkbase = info.lastva;
    p.brksize = 0;

    if (!procmapsetup(p, p.brkbase + BRKMAXSIZE, cast(uintptr) info.stack - PAGESIZE))
        return false;

    p.state = PState.RUNNABLE;

    success = true;

    return true;
}

void procyield(Proc* p) {
    kswitch(null, &p.ctx, &schedctx);
}

void procblock(Proc* p, Queue* q, PState s) {
    p.state = s;
    p.wq = q;
    qpushf(q, p);
    procyield(p);
}

void procentry(Proc* p) {
    lfi_proc_start(p.lp);
}

void procexec(Proc* p) {
    p.ctx = taskctx(&p.kstack[$-16], &procentry);
    kstart(null, null, &schedctx);
}

int procpid(Proc* p) {
    return cast(int) (p.base >> 32);
}

uintptr procaddr(Proc* p, uintptr addr) {
    return (cast(uint) addr) | p.base;
}

uintptr procuseraddr(Proc* p, uintptr addr) {
    if (flags.poc)
        return cast(uint) addr;
    return procaddr(p, addr);
}

ubyte[] procbuf(Proc* p, uintptr buf, usize size) {
    buf = procaddr(p, buf);
    if (size >= PROCSIZE || buf + size >= p.base + PROCSIZE)
        return null;
    return (cast(ubyte*) buf)[0 .. size];
}

bool procinbrk(Proc* p, uintptr addr, usize size) {
    return addr >= p.brkbase && size < p.brksize;
}

bool procinmap(Proc* p, uintptr addr, usize size) {
    return addr >= p.mapbase && size < p.mapsize;
}

const(char)* procpath(Proc* p, uintptr path) {
    path = procaddr(p, path);
    const(char)* str = cast(const(char)*) path;
    static assert(PATH_MAX < PROCSIZE);
    usize len = strnlen(str, PATH_MAX);
    if (path + len >= p.base + PROCSIZE)
        return null;
    if (str[len] != 0)
        return null;
    return str;
}

const(char)* procarg(Proc* p, uintptr arg) {
    arg = procaddr(p, arg);
    const(char)* str = cast(const(char)*) arg;
    static assert(ARGV_MAX < PROCSIZE);
    usize len = strnlen(str, ARGV_MAX);
    if (arg + len >= p.base + PROCSIZE)
        return null;
    if (str[len] != 0)
        return null;
    return str;
}

T* procobj(T)(Proc* p, uintptr ptr) {
    ubyte[] buf = procbuf(p, ptr, T.sizeof);
    if (!buf)
        return null;
    return cast(T*) buf.ptr;
}

T[] procarr(T)(Proc* p, uintptr ptr, usize size) {
    ubyte[] buf = procbuf(p, ptr, T.sizeof * size);
    if (!buf)
        return null;
    return (cast(T*) (buf.ptr))[0 .. size];
}

int procchdir(Proc* p, const(char)* path) {
    int fd = openat(p.cwd.fd, path, O_DIRECTORY | O_PATH, 0);
    if (fd < 0)
        return fd;
    if (p.cwd.fd >= 0)
        close(p.cwd.fd);

    if (!cwk_path_is_absolute(path)) {
        char[PATH_MAX] buffer;
        cwk_path_join(p.cwd.name.ptr, path, buffer.ptr, buffer.length);
        path = buffer.ptr;
    }
    memcpy(p.cwd.name.ptr, path, p.cwd.name.length);
    p.cwd.fd = fd;
    return 0;
}

// Create a memory mapping for the process at any possible location.
bool procmapany(Proc* p, usize size, int prot, int flags, int fd, ssize offset, out uintptr mapstart) {
    bool success;
    uintptr start = cast(uintptr) buddy_malloc(p.mapalloc, size);
    if (!start)
        return false;
    scope(exit) if (!success) ensure(buddy_safe_free(p.mapalloc, cast(void*) start, size));
    if (!procmap(p, start, size, prot, flags, fd, offset, false))
        return false;

    mapstart = start;
    success = true;
    return true;
}

// Create a memory mapping for the process at the requested location.
bool procmapfixed(Proc* p, uintptr start, usize size, int prot, int flags, int fd, ssize offset) {
    //TODO: check overlaps and only reserve ranges that are not overlapping
    bool success;
    buddy_reserve_range(p.mapalloc, cast(void*) start, size);
    scope(exit) if (!success) buddy_unsafe_release_range(p.mapalloc, cast(void*) start, size);
    if (!procmap(p, start, size, prot, flags, fd, offset, true))
        return false;
    success = true;
    return true;
}

// Create a memory mapping for the process at the requested location, assuming
// the location has already been allocated by the map allocator.
bool procmap(Proc* p, uintptr start, usize size, int prot, int flags, int fd, ssize offset, bool fixed) {
    bool success;
    if (fd >= 0) {
        FDFile* f = fdget(&p.fdtable, fd);
        if (!f)
            return false;
        if (f.mapfd == null)
            return false;
        fd = f.mapfd(f.dev);
    }
    void* mem = mmap(cast(void*) start, size, prot, flags | MAP_FIXED, fd, offset);
    if (mem == cast(void*) -1)
        return false;
    MMap m = MMap(start, size, prot, fixed);
    scope(exit) if (!success) munmap(mem, size);
    // TODO: if we are overlapping, we have to remove the existing regions
    if (!p.maps.append(m))
        return false;
    success = true;
    return true;
}

int procunmap(Proc* p, uintptr start, usize size) {
    int i;
    for (i = 0; i < p.maps.length; i++) {
        if (p.maps[i].base == start && p.maps[i].size == size)
            break;
    }
    if (i >= p.maps.length)
        return Err.INVAL;
    mapunmap(p, p.maps[i]);
    p.maps.unordered_remove(i);
    return 0;
}

void mapunmap(Proc* p, MMap m) {
    if (!m.fixed)
        ensure(buddy_safe_free(p.mapalloc, cast(void*) m.base, m.size));
    else
        buddy_unsafe_release_range(p.mapalloc, cast(void*) m.base, m.size);
    ensure(munmap(cast(void*) m.base, m.size) == 0);
}
