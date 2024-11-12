disarm = subproject('disarm').get_variable('disarm64')

subdir('llvm-fuzz')

srcs = files(
  'main.c',
  'rand.c',
)
includes = []

if cpu == 'aarch64'
  subdir('arm64')
elif cpu == 'x86_64'
  subdir('amd64')
else
  subdir_done()
endif

lfifuzz = executable(
  'lfi-fuzz',
  sources: srcs,
  dependencies: [argp, liblfiv_dep, disarm],
  include_directories: includes,
  link_args: ['-static'],
  install: true,
)
