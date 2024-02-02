module verify;

import core.alloc;
import core.lib;

import main;

bool verify_bytes(void* b, usize size) {
    if (flags.noverify) {
        return true;
    }
    ErrorFn fn = null;
    if (flags.verbose) {
        fn = &show_error;
    }
    return lfi_verify_bytes(b, size, fn);
}

private alias ErrorFn = void function(ubyte*, usize);

private void show_error(ubyte* b, usize size) {
    ubyte[] msg = kallocarray!(ubyte)(size + 1);
    memcpy(msg.ptr, b, size);
    msg[size] = 0;
    fprintf(stderr, "%s\n", msg.ptr);
    kfree(msg);
}

private extern (C) bool lfi_verify_bytes(void* b, usize size, ErrorFn fn);
