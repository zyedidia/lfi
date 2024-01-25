module file;

import core.lib;

import proc;
import sysno;

enum {
    AT_FDCWD = -100,
    AT_EMPTY_PATH = 0x1000,
}

private const(char)* flags2cmode(int flags) {
    if ((flags & O_RDONLY) != 0) {
        return "r".ptr;
    }
    if ((flags & O_WRONLY) != 0) {
        return "w".ptr;
    }
    return "r+".ptr;
}

int file_new(VFile* vf, char* name, int flags, int mode) {
    int kfd = open(name, flags, mode);
    if (kfd < 0)
        return kfd;
    void* cfile = fdopen(kfd, flags2cmode(flags));
    if (!cfile)
        return Err.BADF;
    *vf = std_new(cfile);
    return 0;
}

VFile std_new(void* stream) {
    VFile vf;
    vf.dev = stream;
    vf.read = &file_read;
    vf.write = &file_write;
    vf.lseek = &file_lseek;
    vf.stat = &file_stat;
    vf.getdents64 = &file_getdents64;
    vf.close = &file_close;
    return vf;
}

ssize file_read(void* dev, Proc* p, ubyte* buf, usize n) {
    return fread(buf, 1, n, dev);
}

ssize file_write(void* dev, Proc* p, ubyte* buf, usize n) {
    return fwrite(buf, 1, n, dev);
}

int file_stat(void* dev, Proc* p, void* statbuf) {
    return -1;
    // return fstat(fileno(dev), statbuf);
}

ssize file_lseek(void* dev, Proc* p, ssize off, uint whence) {
    ssize r = fseek(dev, off, whence);
    if (r < 0)
        return r;
    return ftell(dev);
}

ssize file_getdents64(void* dev, Proc* p, void* dirp, usize count) {
    return getdents64(fileno(dev), dirp, count);
}

int file_close(void* dev, Proc* p) {
    return fclose(dev);
}

struct VFile {
    void* dev;
    ssize function(void* dev, Proc* p, ubyte* buf, usize n) read;
    ssize function(void* dev, Proc* p, ubyte* buf, usize n) write;
    ssize function(void* dev, Proc* p, ssize off, uint whence) lseek;
    int function(void* dev, Proc* p) close;
    int function(void* dev, Proc* p, void* stat) stat;
    ssize function(void* dev, Proc* p, void* dirp, usize count) getdents64;
}

struct FdTable {
    enum {
        NUM_FILE = 128,
    }

    VFile[NUM_FILE] files;
    bool[NUM_FILE] allocated;

    void alloc(int fd, VFile f) {
        assert(fd >= 0 && fd < NUM_FILE && !allocated[fd]);
        allocated[fd] = true;
        files[fd] = f;
    }

    VFile* alloc(ref int fd) return {
        int i;
        for (i = 0; i < NUM_FILE; i++) {
            if (!allocated[i])
                break;
        }
        if (i >= NUM_FILE)
            return null;
        fd = i;
        allocated[fd] = true;
        return &files[fd];
    }

    void init() {
        alloc(0, std_new(stdin));
        alloc(1, std_new(stdout));
        alloc(2, std_new(stderr));
    }

    bool get(int fd, ref VFile file) {
        if (has(fd)) {
            file = files[fd];
            return true;
        }
        return false;
    }

    bool remove(int fd) {
        if (has(fd)) {
            allocated[fd] = false;
            return true;
        }
        return false;
    }

    bool has(int fd) {
        return fd >= 0 && fd < NUM_FILE && allocated[fd];
    }
}
