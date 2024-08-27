#include "fd.h"

FDFile* lfix_filefdnew(int kfd);
FDFile* lfix_filenew(int dirfd, const char* name, int flags, int mode);
