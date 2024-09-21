srcs = [
  'engine.c',
  'err.c',
  'proc.c',
  'buddy.c',
]

subdir('arch/' + cpuarch)

liblfi = static_library('lfi', srcs, c_args: c_args_hardened, install: true, dependencies: [liblfiv_dep])

install_headers('lfi.h')

liblfi_dep = declare_dependency(link_with: liblfi, include_directories: include_directories('.'))

subdir('test')
