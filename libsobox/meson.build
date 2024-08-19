arch = {
  'aarch64': true,
  'x86_64': true,
}

xxd = find_program('xxd', required: false)

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
  'lib.c',
  'file.c',
  'fd.c',
  'sys.c',
)

subdir('stub')

libsobox = static_library(
  'sobox',
  srcs,
  sbxstub_inc,
  objects: [liblfi.extract_all_objects(recursive: true)],
  dependencies: mmap.as_link_whole(),
  install: true,
)

sobox = declare_dependency(link_with: [libsobox, liblfiv_arm64, liblfiv_amd64], include_directories: include_directories('.'))

install_headers('sobox.h')

subdir('test')
