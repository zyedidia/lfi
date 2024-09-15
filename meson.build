project(
  'lfi',
  ['c', 'cpp'],
  default_options: ['warning_level=1', 'buildtype=release'],
  meson_version: '>=0.60.3',
  version: run_command('git', 'rev-parse', '--short', 'HEAD', check: false).stdout().strip()
)

add_project_arguments('-D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64', language : 'c')

# Enable various hardening flags (used by liblfi and liblfix).
c_args_hardened = [
  '-fno-strict-aliasing',
  '-fno-delete-null-pointer-checks',
  '-fno-strict-overflow',
  '-Werror=implicit',
  '-Werror=incompatible-pointer-types',
  '-Werror=int-conversion',
]

has_auto_var_init = meson.get_compiler('c').has_argument('-ftrivial-auto-var-init=zero')
if has_auto_var_init
  c_args_hardened += '-ftrivial-auto-var-init=zero'
endif

argp = subproject('argp').get_variable('argp_dep')

cpu = target_machine.cpu_family()
lfi_gcc = find_program(cpu + '-lfi-linux-musl-gcc', required: false)

go = find_program('go')
xxd = find_program('xxd', required: false)

subdir('lfi-leg')
subdir('lfi-verify')
subdir('lfi-postlink')
subdir('lfi-compile')
subdir('liblfi')
subdir('liblfix')
# subdir('lfi-run')
# subdir('libsobox')
# subdir('lfi-veribdd')
subdir('specinvoke')
subdir('toolchain')
