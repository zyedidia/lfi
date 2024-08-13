subdir('arm64')

lfiv = executable(
  'lfiv',
  files('main.c'),
  link_with: [lfiv_arm64],
  include_directories: include_directories('include'),
  c_args: '-Wno-missing-field-initialiazers',
  install: true
)

subdir('test')
