#pragma once

char* lfi_rewrite(char* inputstr, char* arch, char* sandbox, char* cfi, char* p2size, char* segue);

char* lfi_flags(char* arch, char* sandbox, char* cfi, char* p2size, char* segue);
