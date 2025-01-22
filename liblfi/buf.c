#include "syscalls/syscalls.h"
#include "host.h"
#include "buf.h"

buf_t
bufreadfile(struct Tux* tux, const char* filename)
{
    struct HostFile* f = NULL;
    if (tux->opts.fs.open)
        f = tux->opts.fs.open(filename, TUX_O_RDONLY, 0);
    if (!f)
        f = host_openat(NULL, filename, TUX_O_RDONLY, 0);
    if (!f)
        return (buf_t) {NULL, 0};
    ssize_t size = host_seek(f, 0, TUX_SEEK_END);
    if (size < 0)
        goto err;

    host_seek(f, 0, TUX_SEEK_SET);
    void* p = host_mmap(NULL, size, LFI_PROT_READ, LFI_MAP_PRIVATE, f, 0);
    if (p == (void*) -1)
        goto err;

    host_close(f);
    return (buf_t) {
        .data = (uint8_t*) p,
        .size = size,
    };
err:
    host_close(f);
    return (buf_t){NULL, 0};
}
