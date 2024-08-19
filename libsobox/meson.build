arch = {
  'aarch64': true,
  'x86_64': true,
}

if not arch.has_key(cpu)
  warning('cannot build libsobox for architecture: ' + cpu)
  subdir_done()
endif

if not lfi_gcc.found()
  warning('LFI GCC was not found, cannot build libsobox')
  subdir_done()
endif

subdir('stub')
