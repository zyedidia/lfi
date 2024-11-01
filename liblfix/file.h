#include "lfix.h"

FDFile* lfix_filefdnew(int kfd);
FDFile* lfix_filenew(LFIXEngine* lfix, int dirfd, const char* name, int flags, int mode);
