project('lfiv', ['c'], default_options: ['warning_level=3', 'c_std=c11', 'buildtype=release'], meson_version: '>=0.54')

add_project_arguments('-Wno-missing-field-initializers', language : 'c')

subdir('arm64')

lfiv = executable('lfiv', files('main.c'), link_with: [lfiv_arm64], include_directories: include_directories('include'), install: true)

subdir('test')
