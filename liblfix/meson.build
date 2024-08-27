srcs = files(
  'lfix.c',
  'sys.c',
  'file.c',
  'fd.c',
)

mmap = subproject('libmmap').get_variable('mmap')

liblfix = static_library(
  'lfix',
  srcs,
  dependencies: [mmap.as_link_whole(), liblfi_dep.as_link_whole()],
  install: true,
)

liblfix_dep = declare_dependency(link_with: liblfix, include_directories: include_directories('.'))

lfi_run_srcs = files(
  'main.c'
)

lfi_run = executable(
  'lfi-run',
  lfi_run_srcs,
  dependencies: [liblfix_dep],
  install: true,
)
