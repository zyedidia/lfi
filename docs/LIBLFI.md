# Using liblfi

The LFI runtime is usable as the liblfi library. There are two sub-libraries within liblfi:

* `liblfi-core`: provides basic functionality for creating and destroying
  sandboxes, mapping and protecting memory inside the sandbox (with
  verification for executable pages), tracking per-thread sandbox context, and
  transitioning control in and out of the sandbox.
* `liblfi-linux`: provides Linux emulation, with ELF loading and system call
  handling for a subset of the Linux API.

See https://github.com/lfi-project/lfi-runtime for the implementation of these
two libraries. You can build it like so:

```
meson setup build
cd build
ninja
```

This will produce a few different libraries: `liblfi-core.a`, `liblfi-linux.a`,
`liblfi.a`, and `liblfi.so`. The `liblfi.*` libraries include both the Core and
Linux libraries.

The full API for the Core library is provided by `lfi_core.h` and `lfi_arch.h`.
The Linux library can be used via `lfi_linux.h`.

## The Core library

The first part of the tutorial will explain how to use the more bare-bones Core
library. You should use this library if you don't want to run Linux-based LFI
binaries and instead have a custom runtime API for your LFI programs.

This will involve a lot of manual construction of sandbox state (manually loading
program code/data, setting up the stack, etc...). The Linux library automates a
lot of this work, so you should only use the Core library directly if you need
low-level control.

### Running a basic program

The first step is to create an object of type `struct LFIEngine` using the
`lfi_new(struct LFIOptions opts, size_t nsandboxes)` function. This will
reserve enough virtual address space for `nsandboxes`, which may vary depending
on your architecture and options.

```c
size_t pagesize = getpagesize();
struct LFIEngine *engine = lfi_new(
    (struct LFIOptions) {
        .boxsize = 4UL * 1024 * 1024 * 1024,
        .pagesize = pagesize,
    },
    1);
assert(engine);
```

This example creates an engine with space for 1 sandbox, and configures the
sandbox size to 4GiB and page size to match the host page size. Currently
liblfi only supports 4GiB sandboxes, although this may change in the future.

Here are some other useful options:

* `verbose`: enables verbose debug statements. This can also be enabled by
  setting the environment variable `LFI_VERBOSE=1`.
* `no_verify`: disables verification (unsafe).
* `stores_only`: reduces verification to only check for stores-only mode.

Once the engine is created, you can create a sandbox, represented by an object
of type `struct LFIBox`. This object tracks the memory associated with a
sandbox and can be used to map/protect memory inside the sandbox.

```c
struct LFIBox *box = lfi_box_new(engine);
assert(box);
```

You may want to map some actual memory into the sandbox memory, such as a
simple program to run. In this example we'll use an aarch64 program that puts
42 in `x8` and then executes the "system call" runtime call. See
https://github.com/lfi-project/lfi-runtime/blob/master/core/test/test_ctx.c for
a complete version with programs for x86-64 and RISC-V as well.

```c
static uint8_t prog[] = {
    0x48, 0x05, 0x80, 0xd2, // mov x8, #42
    0x7e, 0x03, 0x40, 0xf9, // ldr x30, [x27]
    0xc0, 0x03, 0x3f, 0xd6, // blr x30
}
```

We can use `lfi_box_mapany` to create a new memory mapping in the sandbox, copy
the program in, and then mark it as executable.

```c
// Create a R/W memory mapping in the sandbox.
lfiptr p = lfi_box_mapany(box, pagesize, LFI_PROT_READ | LFI_PROT_WRITE,
    LFI_MAP_ANONYMOUS | LFI_MAP_PRIVATE, -1, 0);
assert(p != (lfiptr) -1);

// Copy our program into the sandbox.
lfi_box_copyto(box, p, prog, sizeof(prog));

// Mark the program as executable (runs verification).
int r = lfi_box_mprotect(box, p, pagesize, LFI_PROT_READ | LFI_PROT_EXEC);
assert(r == 0);
```

Next, you'll want to create the actual sandbox context associated with a
sandbox, represented by an object of type `struct LFIContext`. This object
holds thread-local information like sandbox registers, and stack pointer.
Having multiple contexts for one sandbox allows you to have multiple sandbox
threads running in parallel. The context constructor additionally takes a
user data pointer, which you can use to store associated context. In this
example we will leave it `NULL`.

```c
struct LFIContext *ctx = lfi_ctx_new(box, NULL)
assert(ctx);
```

Finally, you'll want to register a "system call" handler for it. This handler
will be called when the sandbox program attempts to make a system call (the
rewritten version of the `syscall` or `svc` instruction), which is a particular
type of runtime call.

The handler is passed the `struct LFIContext` that made the call. We can use
`lfi_ctx_regs` to retrieve the register file for the context. We can also
modify the `struct LFIRegs` object to change the registers, but in this case
we'll just read from it. Then we'll exit the sandbox with `lfi_ctx_exit`.

```c
static void
handler(struct LFIContext *ctx)
{
    struct LFIRegs *regs = lfi_ctx_regs(ctx);
    printf("system call, x8: %d\n", regs->x8);
    lfi_ctx_exit(ctx, 0);
}
```

To register this handler, we'll call:

```
lfi_sys_handler(engine, handler);
```

Although not strictly necessary in this case, let's also create a stack.

```c
size_t stacksize = pagesize;
lfiptr stack = lfi_box_mapany(box, stacksize, LFI_PROT_READ | LFI_PROT_WRITE,
    LFI_MAP_ANONYMOUS | LFI_MAP_PRIVATE, -1, 0);
lfi_ctx_regs(ctx)->sp = stack + stacksize;
```

Now we are ready to execute the program, which is located in the sandbox at
`p`.

```c
int code = lfi_ctx_run(ctx, p);
assert(code == 0);
```

This will begin sandbox execution, until `lfi_ctx_exit` is called (with a
return code). Since we called `lfi_ctx_exit` in the handler it will return
after the first system call, with return code 0 (passed to `lfi_ctx_exit`).

### Invoking functions with `LFI_INVOKE`

The model so far has been similar to an OS process: load the program, begin
execution, handle any system calls that it makes, and then at some point it
exits. If we want more of a library model, where we directly invoke certain
functions in the sandbox, we can use a different API from liblfi.

First, we need to initialize the return runtime call in the sandbox:

```c
lfi_box_init_ret(box);
```

Next, we'll use a different program from the previous example. We'll want a
program that just consists of a function that adds two arguments and then
returns, and we'll directly invoke it in the sandbox instead of using
`lfi_ctx_run`.

```c
static uint8_t prog[] = {
    0x00, 0x00, 0x01, 0x8b, // add x0, x0, x1
    0xc0, 0x03, 0x5f, 0xd6, // ret
};
```

I'll assume you have copied this program into the sandbox at address `p` and
marked it as executable (similar to the previous example).

Now we can invoke the function in the sandbox using the `LFI_INVOKE` macro:

```c
int x = LFI_INVOKE(box, &ctx, p, int, (int, int), 10, 32);
assert(x == 42);
```

We pass the type signature of the function to `LFI_INVOKE`, followed by the
actual arguments. We also pass the `box` object and a pointer to the `ctx`
object. This is because, for multithreading support (see later section), the
`ctx` object may actually be `NULL`, in which case liblfi will dynamically
create a new context object for us from the `box` object. This mechanism will
be discussed in more detail in the later section on multithreading.

Internally, `LFI_INVOKE` works by setting a thread-local called
`lfi_invoke_info` with the appropriate information (`box`, `&ctx`, and the
target address `p`), before calling the liblfi trampoline at the address stored
in `lfi_trampoline_addr`. You can do this manually if you need to (using a
non-C/C++ language).

### Callbacks

You might want to pass a host function into the sandbox that it can call. First,
you need to initialize callback support in the sandbox:

```c
bool ok = lfi_box_cbinit(box);
assert(ok);
```

Next, you can register your host function as a sandbox callback. This will
return a function pointer to a function inside the sandbox that will transfer
control to the host function. Since it is inside the sandbox, it may be called
by sandbox code.

```c
static int
callback(int a)
{
    printf("callback got %d\n", a);
    return a;
}
```

```c
void *box_callback = lfi_box_register_cb(box, callback);
assert(box_callback);
```

Let's also use a new program that consists of a function that takes a `int
(*)(int) fn` function, and an `int x`, and returns `fn(x)`

```c
static uint8_t prog[] = {
    0xe2, 0x03, 0x00, 0xaa, // mov x2, x0
    0xe0, 0x03, 0x01, 0x2a, // mov w0, w1
    0x7c, 0x43, 0x22, 0x8b, // add x28, x27, w2, uxtw
    0x80, 0x03, 0x1f, 0xd6, // br x28
};
```

Now we can invoke this will `LFI_INVOKE`, and pass in our `box_callback`.

```c
int x = LFI_INVOKE(box, &ctx, p, int, (int (*)(int), int), box_callback, 42);
assert(x == 42);
```

### Multithreading

If your host code uses multiple threads, you will need a separate `struct
LFIContext` for each thread (unless you want to serialize sandbox execution
with a lock). It can be inconvenient to manually create a new context when you
spawn a new thread. As a result, liblfi provides a mechanism to allow you to
create a new `LFIContext` dynamically when `LFI_INVOKE` is called on a new host
thread.

First, you'll want to make your context a thread-local rather than a function
local. This way, a new context pointer will be automatically created by your
language runtime when a new thread is created.

```c
_Thread_local struct LFIContext *ctx;
```

Next, you'll want to create the `clone_cb`, a function that is called by liblfi
when `LFI_INVOKE` is called with a context that is `NULL` to initialize it.

```c
static struct LFIContext *
clone_cb(struct LFIBox *box)
{
    size_t pagesize = getpagesize();

    struct LFIContext *ctx = lfi_ctx_new(box, NULL);
    assert(ctx);

    lfiptr stack = lfi_box_mapany(box, pagesize, LFI_PROT_READ | LFI_PROT_WRITE,
        LFI_MAP_ANONYMOUS | LFI_MAP_PRIVATE, -1, 0);

    lfi_ctx_regs(ctx)->sp = stack + pagesize;

    printf("clone_cb initialized ctx: %p, stack: %lx\n", ctx, stack);

    return ctx;
}
```

And register it with the engine:

```c
lfi_set_clone_cb(engine, clone_cb);
```

Now if you create a new host thread, the `ctx` for that thread will initially
be `NULL`. When you call `LFI_INVOKE(box, &ctx, ...)` the liblfi trampoline
will see that `ctx` is null and invoke `clone_cb` to initialize it.

## The Linux library

Coming soon!
