#include "fd.h"

FDFile* filefdnew(int kfd);
FDFile* filenew(int dirfd, const char* name, int flags, int mode);
