project('lfi-leg', ['c'], default_options: ['warning_level=1', 'buildtype=release'], meson_version: '>=0.58')

add_project_arguments('-Wno-unused-function', '-Wno-unused-parameter', language : 'c')

go = find_program('go')
leg = executable('leg', files('minipeg/minipeg.c'), install: false)
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

lfi_leg = executable('lfi-leg', files('main.c'), srcs, leg_srcs, install: true)
liblfi_leg = static_library('lfileg', files('lib.c'), srcs, leg_srcs, install: true)

install_headers('include/lfileg.h')

subdir('test')
