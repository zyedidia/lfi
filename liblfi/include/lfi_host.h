#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct HostFile;

struct HostFile* lfi_host_open(const char* filename, int flags, int mode);

struct HostFile* lfi_host_fdopen(int fd);

int lfi_host_close(struct HostFile* file);

#ifdef __cplusplus
}
#endif
