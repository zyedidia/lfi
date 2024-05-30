#include <sstream>
#include <iostream>

#include "include/x64asm.h"

using namespace std;
using namespace x64asm;

extern "C" size_t x64_insn_size(char* insn) {
    Assembler assm;
    Code c;
    stringstream(string(insn)) >> c;
    return assm.assemble(c).second.size();
}
