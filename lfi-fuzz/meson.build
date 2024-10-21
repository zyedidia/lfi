disarm = subproject('disarm').get_variable('disarm64')

if cpu != 'aarch64'
  subdir_done()
endif

srcs = files(
  'main.c',
  'generator.c',
  'runner.c',
  'jumpto.S',
)

lfifuzz = executable(
  'lfi-fuzz',
  sources: srcs,
  dependencies: [argp, liblfiv_dep, disarm],
  install: true,
)
