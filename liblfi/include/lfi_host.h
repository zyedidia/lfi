#pragma once

struct HostFile;

struct HostFile* lfi_host_open(const char* filename, int flags, int mode);

struct HostFile* lfi_host_fdopen(int fd);

int lfi_host_close(struct HostFile* file);
