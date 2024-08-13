project('lfi', ['c'], default_options: ['warning_level=1', 'buildtype=release'], meson_version: '>=0.58', version: 'dev')

go = find_program('go')

subdir('lfi-leg')
subdir('lfi-verify')
subdir('lfi-postlink')
subdir('lfi-compile')
subdir('liblfi')
