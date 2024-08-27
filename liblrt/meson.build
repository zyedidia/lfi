srcs = files(
  'rt.c'
)

mmap = subproject('libmmap').get_variable('mmap')

liblrt = static_library(
  'lrt',
  srcs,
  dependencies: [mmap.as_link_whole(), liblfi_dep.as_link_whole()],
  install: true,
)

liblrt_dep = declare_dependency(link_with: liblrt, include_directories: include_directories('.'))

lfi_run_srcs = files(
  'main.c'
)

lfi_run = executable(
  'lfi-run',
  lfi_run_srcs,
  dependencies: [liblrt_dep],
  install: true,
)
