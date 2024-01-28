module proc;

import core.vector;
import core.lib;
import core.math;
import core.alloc;
import core.interval;

import regs;
import mem;
import elf;
import sys;
import file;
import queue;
import schedule;

extern (C) {
    void proc_entry(Proc* p);
    void syscall_entry();
    void yield_entry();
}

enum {
    GUARD_SIZE = kb(48),
    PROC_SIZE = gb(4),
    CODE_MAX = gb(1),
    STACK_SIZE = mb(2),
    KSTACK_SIZE = kb(64),
    BRK_SIZE = mb(512),

    ARGC_MAX = 1024,
    ARGV_MAX = 1024,
}

// This will fail if using 64kB pages and 48kB guards.
static assert(GUARD_SIZE % PAGESIZE == 0);

struct Cwd {
    char[PATH_MAX] name;
    int fd;

    void copy_into(ref Cwd cwd) {
        memcpy(cwd.name.ptr, name.ptr, name.length);
        cwd.fd = fd;
    }
}

struct Proc {
    enum State {
        RUNNABLE,
        BLOCKED,
        EXITED,
    }

    ubyte* kstackp;
    Regs regs;
    Context context;

    MemRegion[2] guards;
    MemRegion sys;
    Vector!(MemRegion) segments;
    MemRegion stack;
    MemRegion brk;

    uintptr mmap_start;
    uintptr mmap_end;

    Cwd cwd;

    uintptr brkp;
    IntervalTree!(MemRegion) vmas;
    IntervalTree!(Empty) free_vmas;

    Proc* parent;
    Vector!(Proc*) children;

    FdTable fdtable;

    void* wq;

    uintptr base;
    ubyte[] kstack;

    Proc* next;
    Proc* prev;
    State state;

    void free_regions() {
        guards[0].unmap();
        guards[1].unmap();
        sys.unmap();
        stack.unmap();
        brk.unmap();

        foreach (ref seg; segments) {
            seg.unmap();
        }

        foreach (ref mem; vmas) {
            mem.val.unmap();
        }

        vmas.free();
        free_vmas.free();
    }

    static Proc* make_empty() {
        if (manager.full())
            return null;

        Proc* p = knew!(Proc)();
        if (!p)
            return null;

        ubyte[] kstack = void;

        kstack = kzalloc(KSTACK_SIZE);
        if (!kstack)
            goto err1;

        p.fdtable.init();
        p.kstack = kstack;

        p.kstackp = p.kstack.ptr + KSTACK_SIZE;
        p.context = Context(cast(uintptr) p.kstackp, cast(uintptr) &Proc.entry, p.kstack.ptr);
        p.cwd.fd = AT_FDCWD;

        ensure(getcwd(&p.cwd.name[0], p.cwd.name.length) != null);

        p.base = manager.make();

        return p;

err1:
        kfree(p);
        return null;
    }

    static Proc* make_from_parent(Proc* parent) {

        Proc* p = Proc.make_empty();
        if (!p)
            return null;

        p.base = manager.make();

        printf("Fork process to %lx\n", p.base);

        p.guards[0] = parent.guards[0].copy_to(p);
        if (!p.guards[0].valid())
            goto err;
        p.guards[1] = parent.guards[1].copy_to(p);
        if (!p.guards[1].valid())
            goto err;
        p.sys = parent.sys.copy_to(p);
        if (!p.sys.valid())
            goto err;

        p.stack = parent.stack.copy_to(p);
        if (!p.stack.valid())
            goto err;
        p.brk = parent.brk.copy_to(p);
        if (!p.brk.valid())
            goto err;

        {
            ensure(p.sys.protect(PROT_READ | PROT_WRITE) == 0);
            SysTable* table = cast(SysTable*) p.sys.base;
            table.setup(p);
            ensure(p.sys.protect(PROT_READ) == 0);
        }

        foreach (ref seg; parent.segments) {
            MemRegion m = seg.copy_to(p);
            if (!m.valid())
                goto err;
            if (!p.segments.append(m))
                goto err;
        }

        if (!parent.vmas.copy_into(p.vmas))
            goto err;
        if (!parent.free_vmas.copy_into(p.free_vmas))
            goto err;

        p.brkp = parent.brkp;
        p.parent = parent;
        p.mmap_start = parent.mmap_start;
        p.mmap_end = parent.mmap_end;
        p.regs = parent.regs;
        p.regs.validate(p);
        parent.cwd.copy_into(p.cwd);

        p.state = Proc.State.RUNNABLE;

        return p;

err:
        kfree(p);
        return null;
    }

    static Proc* make_from_file(const(char)* pathname, int argc, const(char)** argv, const(char)** envp) {
        Proc* p = Proc.make_empty();
        if (!p)
            goto err1;
        if (!p.init_from_file(pathname, argc, argv, envp))
            goto err1;

        return p;
err1:
        kfree(p);
        return null;
    }

    bool init_from_file(const(char)* pathname, int argc, const(char)** argv, const(char)** envp) {
        void* f = fopen(pathname, "rb");
        if (!f)
            return false;
        ubyte[] buf = readfile(f);
        if (!buf)
            return false;
        ensure(fclose(f) == 0);
        scope(exit) kfree(buf);

        if (!setup(buf, argc, argv, envp))
            return false;

        return true;
    }

    static void entry(Proc* p) {
        proc_entry(p);
    }

    bool setup(ubyte[] buf, int argc, const(char)** argv, const(char)** envp) {
        if (argc <= 0 || argc >= ARGC_MAX)
            return false;

        uintptr seg_base, last, entry;
        if (!load(base, buf, seg_base, last, entry))
            return false;

        stack = MemRegion.map(cast(uintptr) guards[1].base - STACK_SIZE, STACK_SIZE, PROT_READ | PROT_WRITE);
        if (!stack.valid())
            return false;

        brkp = ceil(last, PAGESIZE);
        brk = MemRegion.map(cast(uintptr) brkp, BRK_SIZE, PROT_READ | PROT_WRITE);
        if (!brk.valid())
            goto err1;

        regs = Regs(base, entry);

        // Set up argv and envp.
        {
            char*[ARGC_MAX] argv_ptrs;

            void* stack_top = stack.base + stack.len;
            char* p_argv = cast(char*) stack_top - PAGESIZE;

            // Write argv string values to the stack.
            for (int i = 0; i < argc; i++) {
                usize len = strnlen(argv[i], ARGV_MAX) + 1;

                if (p_argv + len >= stack_top) {
                    goto err1;
                }

                memcpy(p_argv, argv[i], len);
                p_argv[len - 1] = 0;
                argv_ptrs[i] = p_argv;
                p_argv += len;
            }

            // Write argc and argv pointers to the stack.
            long* p_argc = cast(long*) (stack_top - 2 * PAGESIZE);
            regs.sp = cast(uintptr) p_argc;
            *p_argc++ = argc;
            char** p_argvp = cast(char**) p_argc;
            for (int i = 0; i < argc; i++) {
                if (cast(uintptr) p_argvp >= cast(uintptr) stack_top - PAGESIZE) {
                    goto err1;
                }
                p_argvp[i] = argv_ptrs[i];
            }
            p_argvp[argc] = null;
            // Empty envp.
            char** p_envp = cast(char**) &p_argvp[argc + 1];
            *p_envp++ = null;

            FileHeader* ehdr = cast(FileHeader*) buf.ptr;
            ProgHeader[] phdr = (cast(ProgHeader*) &buf[ehdr.phoff])[0 .. ehdr.phnum];

            // Set up auxv.
            Auxv* av = cast(Auxv*) p_envp;
            *av++ = Auxv(AT_SECURE, 0);
            *av++ = Auxv(AT_PHDR, seg_base + ehdr.phoff);
            *av++ = Auxv(AT_PHNUM, ehdr.phnum);
            *av++ = Auxv(AT_PHENT, ProgHeader.sizeof);
            *av++ = Auxv(AT_ENTRY, entry);
            *av++ = Auxv(AT_EXECFN, cast(ulong) p_argvp[0]);
            *av++ = Auxv(AT_PAGESZ, PAGESIZE);
            // *av++ = Auxv(AT_RANDOM, p_argvp_start[0]);
            *av++ = Auxv(AT_HWCAP, 0x0);
            *av++ = Auxv(AT_HWCAP2, 0x0);
            *av++ = Auxv(AT_FLAGS, 0x0);
            *av++ = Auxv(AT_UID, 1000);
            *av++ = Auxv(AT_EUID, 1000);
            *av++ = Auxv(AT_GID, 1000);
            *av++ = Auxv(AT_EGID, 1000);
            *av++ = Auxv(AT_NULL, 0);
        }

        // Set up sys page.

        {
            SysTable* table = cast(SysTable*) sys.base;
            table.setup(&this);
            ensure(sys.protect(PROT_READ) == 0);
        }

        mmap_start = cast(uintptr) brk.base + brk.len;
        mmap_end = truncpg(cast(uintptr) stack.base - 1);
        if (!free_vmas.add(mmap_start, mmap_end - mmap_start, Empty()))
            goto err2;

        return true;
err2:
        brk.unmap();
err1:
        stack.unmap();
        return false;
    }

    bool load(uintptr base, ubyte[] buf, ref uintptr seg_base, ref uintptr last, ref uintptr entry) {
        FileHeader* ehdr = cast(FileHeader*) buf.ptr;

        if (!elf_check(ehdr)) {
            return false;
        }

        if (ehdr.phoff >= buf.length || ehdr.phoff + ehdr.phnum * ProgHeader.sizeof >= buf.length) {
            return false;
        }

        ProgHeader[] phdr = (cast(ProgHeader*) (&buf[ehdr.phoff]))[0 .. ehdr.phnum];

        sys = MemRegion.map(base, PAGESIZE, PROT_READ | PROT_WRITE);
        if (!sys.valid())
            return false;
        guards[0] = MemRegion.map(base + PAGESIZE, GUARD_SIZE, PROT_NONE);
        if (!guards[0].valid())
            goto err1;
        guards[1] = MemRegion.map(base + PROC_SIZE - GUARD_SIZE, GUARD_SIZE, PROT_NONE);
        if (!guards[1].valid())
            goto err2;

        seg_base = cast(uintptr) guards[0].base + guards[0].len;

        foreach (ref ProgHeader p; phdr) {
            if (p.type != PT_LOAD)
                continue;
            uintptr start = trunc(p.vaddr, p.align_);
            uintptr end = ceil(p.vaddr + p.memsz, p.align_);
            uintptr offset = p.vaddr - start;

            if (p.memsz < p.filesz) {
                goto err3;
            }
            if (end - start >= CODE_MAX) {
                goto err3;
            }

            MemRegion seg = MemRegion.map(seg_base + start, end - start, PROT_READ | PROT_WRITE);
            if (!seg.valid()) {
                goto err3;
            }

            memcpy(seg.base + offset, &buf[p.offset], p.filesz);
            memset(seg.base + offset + p.filesz, 0, p.memsz - p.filesz);

            if (seg.protect(pflags(p.flags)) == -1) {
                seg.unmap();
                goto err3;
            }

            if (!segments.append(seg)) {
                seg.unmap();
                goto err3;
            }

            if (seg_base == 0)
                seg_base = cast(uintptr) seg.base;
            if (seg_base + end > last)
                last = seg_base + end;
        }

        entry = seg_base + ehdr.entry;

        return true;

err3:
        foreach (ref seg; segments) {
            seg.unmap();
        }

        guards[1].unmap();
err2:
        guards[0].unmap();
err1:
        sys.unmap();
        return false;
    }

    uintptr addr(uintptr p) {
        return (cast(uint) p) | base;
    }

    bool checkptr(uintptr ptr, usize size) {
        // TODO: check if ptr is accessible?
        return ptr + size < base + PROC_SIZE && ptr >= base;
    }

    bool checkmap(uintptr ptr, usize size) {
        if (!checkptr(ptr, size)) {
            return false;
        }
        return ptr >= mmap_start && ptr + size <= mmap_end;
    }

    bool checkpath(uintptr ptr) {
        if (!checkptr(ptr, PATH_MAX)) {
            return false;
        }
        if (strnlen(cast(const(char)*) ptr, PATH_MAX - 1) >= PATH_MAX - 1) {
            return false;
        }
        return true;
    }

    int pid() {
        return cast(int) (base >> 32);
    }

    int chdir(const(char*) path) {
        int fd = open(path, O_DIRECTORY | O_PATH, 0);
        if (fd < 0)
            return fd;
        if (cwd.fd >= 0)
            close(cwd.fd);
        memcpy(cwd.name.ptr, path, cwd.name.length);
        cwd.fd = fd;
        return 0;
    }

    void yield() {
        kswitch(null, &context, &schedctx);
    }

    void block(Queue* q, State s) {
        state = s;
        wq = q;
        q.push_front(&this);
        yield();
    }

    // These map functions assume the arguments have been sanitized.
    bool map_any(usize length, int prot, int flags, int fd, ssize offset, ref uintptr map_start) {
        usize size = ceilpg(length);
        Interval!(Empty) i;
        // Find a region that is large enough.
        if (!free_vmas.find(size, i)) {
            return false;
        }

        map_start = i.start;

        return map(i.start, length, prot, flags, fd, offset);
    }

    bool map(uintptr start, usize length, int prot, int flags, int fd, ssize offset) {
        usize size = ceilpg(length);
        Interval!(MemRegion) v;
        while (vmas.overlaps(start, size, v)) {
            // TODO: handle allocation failure
            ensure(vmas.remove(v.start, v.size));
            if (v.start < start) {
                ensure(vmas.add(v.start, start - v.start, v.val));
            }
            if ((v.start + v.size) > (start + size)) {
                ensure(vmas.add(start + size, (v.start + v.size) - (start + size), v.val));
            }
        }

        return map_no_overlap(start, length, prot, flags, fd, offset);
    }

    bool map_no_overlap(uintptr start, usize length, int prot, int flags, int fd, ssize offset) {
        usize size = ceilpg(length);
        Interval!(MemRegion) v;
        if (vmas.overlaps(start, size, v)) {
            return false;
        }

        Interval!(Empty) i;
        free_vmas.overlaps(start, size, i);

        // Split the free region.
        bool ok = free_vmas.remove(i.start, i.size);
        if (ok) {
            // TODO: handle allocation failure
            // This needs to be atomic with the remove.
            if (start - i.start != 0) {
                ok = free_vmas.add(i.start, start - i.start, Empty());
                assert(ok);
            }
            if (i.size - size != 0) {
                if (!free_vmas.add(start + size, i.size - (start - i.start) - size, Empty())) {
                    // If this fails, we might have problems.
                    return false;
                }
            }
        }

        auto mem = MemRegion.map(start, size, prot, flags, fd, offset);
        if (!mem.valid()) {
            return false;
        }

        if (!vmas.add(start, size, mem)) {
            mem.unmap();
            return false;
        }

        return true;
    }

    int unmap(uintptr start, usize size) {
        Interval!(MemRegion) v;
        if (!vmas.find_exact(start, size, v)) {
            return -1;
        }

        ensure(v.val.unmap() == 0);

        // TODO: handle allocation failure
        ensure(free_vmas.add(start, size, Empty()));
        // Ok to ensure.
        ensure(vmas.remove(start, size));

        return 0;
    }

    void exec() {
        context = Context(cast(uintptr) kstackp, cast(uintptr) &Proc.entry, kstack.ptr);
        kswitch_nosave(null, &context, &schedctx);
    }

    SysTable* systable() {
        return cast(SysTable*) sys.base;
    }
}

struct SysTable {
    uintptr[256] rtcalls;
    Proc* proc;
    uintptr kernel_tpidr;

    void setup(Proc* p) {
        rtcalls[0] = cast(uintptr) &syscall_entry;
        rtcalls[1] = cast(uintptr) &yield_entry;
        proc = p;
        kernel_tpidr = SysReg.tpidr_el0;
    }
}

static assert(SysTable.sizeof <= PAGESIZE);

private bool elf_check(FileHeader* ehdr) {
    return ehdr.magic == ELF_MAGIC &&
        ehdr.width == ELFCLASS64 &&
        ehdr.version_ == EV_CURRENT &&
        ehdr.type == ET_DYN;
}

private int pflags(int prot) {
    return ((prot & PF_R) ? PROT_READ : 0) |
        ((prot & PF_W) ? PROT_WRITE : 0) |
        ((prot & PF_X) ? PROT_EXEC : 0);
}

Proc* proc_at(uintptr base) {
    // assumes there is a proc at base
    SysTable* sys = cast(SysTable*) base;
    return sys.proc;
}
