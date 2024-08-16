project(
  'lfi',
  ['c'],
  default_options: ['warning_level=1', 'buildtype=release'],
  meson_version: '>=0.60.3',
  version: run_command('git', 'rev-parse', '--short', 'HEAD', check: false).stdout().strip()
)

add_project_arguments('-D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64', language : 'c')

go = find_program('go')

subdir('lfi-leg')
subdir('lfi-verify')
subdir('lfi-postlink')
subdir('lfi-compile')
subdir('liblfi')
subdir('lfi-run')
subdir('specinvoke')
subdir('toolchain')
