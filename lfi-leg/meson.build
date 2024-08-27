# GCC 13 has a bug that generates an incorrect array-bounds warning: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105523
leg = executable('leg', files('minipeg/minipeg.c'), c_args: ['-Wno-array-bounds'], native: true, install: false)
# leg = find_program('leg')

srcs = files(
  'ht.c',
  'op.c',
  'util.c',
)

leg_srcs = []

subdir('arm64')
subdir('amd64')
subdir('riscv64')

args = ['-Wno-unused-function', '-Wno-unused-parameter']

lfi_leg = executable('lfi-leg', files('main.c'), srcs, leg_srcs, install: true, c_args: args, dependencies: argp)
liblfi_leg = static_library('lfileg', files('lib.c'), srcs, leg_srcs, install: true, c_args: args)

install_headers('include/lfileg.h')

subdir('test')
