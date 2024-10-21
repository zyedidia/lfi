disarm = subproject('disarm').get_variable('disarm64')

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
