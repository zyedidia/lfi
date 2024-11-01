srcs = files(
  'lfix.c',
  'file.c',
  'fd.c',
  'proc.c',
  'cwalk/cwalk.c',
)

mmap = subproject('libmmap').get_variable('mmap')

subdir('arch/' + cpuarch)

liblfix = static_library(
  'lfix',
  srcs,
  dependencies: [mmap.as_link_whole(), liblfi_dep.as_link_whole(), liblfiv_dep],
  c_args: c_args_hardened + ['-fvisibility=hidden'],
  install: true,
)

install_headers('lfix.h')

liblfix_dep = declare_dependency(link_with: liblfix, include_directories: include_directories('.'))

lfi_run_srcs = files(
  'main.c'
)

lfi_run = executable(
  'lfi-run',
  lfi_run_srcs,
  dependencies: [liblfix_dep, mmap, liblfi_dep, liblfiv_dep, argp],
  install: true,
)
