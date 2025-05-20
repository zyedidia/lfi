srcs = [
  'engine.c',
  'err.c',
  'proc.c',
  'buddy.c',
  'stack.c',
]

mmap = subproject('libmmap').get_variable('mmap')

subdir('arch/' + cpuarch)

liblfi_small = static_library(
  'lfi',
  srcs,
  c_args: c_args_hardened + ['-fvisibility=hidden'] + defines,
  install: true,
  dependencies: [liblfiv_dep, mmap.as_link_whole()],
)

install_headers('lfi_small.h')

liblfi_small_dep = declare_dependency(link_with: liblfi_small, include_directories: include_directories('.'))

if not get_option('liblfi-tests')
  subdir_done()
endif

subdir('test')
