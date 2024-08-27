subdir('arm64')
subdir('amd64')

lfiv = executable(
  'lfi-verify',
  files('main.c'),
  link_with: [liblfiv_arm64, liblfiv_amd64],
  include_directories: include_directories('include'),
  c_args: '-Wno-missing-field-initialiazers',
  dependencies: [argp],
  install: true
)

install_headers('include/lfiv.h')

subdir('test')
