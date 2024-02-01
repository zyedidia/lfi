module verify;

import main;

bool verify_bytes(void* b, usize size) {
    if (flags.noverify) {
        return true;
    }
    return lfi_verify_bytes(b, size, null);
}

private extern (C) bool lfi_verify_bytes(void* b, usize size, void* fn);
