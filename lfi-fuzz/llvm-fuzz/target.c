#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "lfiv.h"

LFIvOpts vopts = (LFIvOpts) {
    .decl = true,
};
/* static LFIVerifier v = (LFIVerifier) { */
/*     .opts = vopts, */
/* }; */

static int check(const uint8_t* data, size_t size) {
    if (size == 4) {
        if (lfiv_verify_insn_arm64(*((uint32_t*) data), &vopts))
            return -1;
    }
    return 0;
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  return check(data, size);
}
