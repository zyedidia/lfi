arch = {
  'aarch64': true,
  'x86_64': true,
}

if not xxd.found()
  warning('xxd not found: cannot build libsobox')
  subdir_done()
endif

if not arch.has_key(cpu)
  warning('cannot build libsobox for architecture: ' + cpu)
  subdir_done()
endif

if not lfi_gcc.found()
  warning('LFI GCC was not found, cannot build libsobox')
  subdir_done()
endif

mmap = subproject('libmmap').get_variable('mmap')

srcs = files(
  'sobox.c',
  'proc.c',
  'file.c',
  'fd.c',
  'sys.c',
)

subdir('stub')

libsobox = static_library(
  'sobox',
  srcs,
  sbxstub_inc,
  c_args: c_args_hardened,
  dependencies: [liblfiv_dep, mmap.as_link_whole(), liblfi_dep.as_link_whole()],
  install: true,
)

sobox = declare_dependency(link_with: [libsobox], include_directories: include_directories('.'))

install_headers('sobox.h')

subdir('test')
