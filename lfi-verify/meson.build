disarm = subproject('disarm').get_variable('disarm64')
fadec = subproject('fadec').get_variable('fadec')

# subdir('arm64')
# subdir('amd64')

liblfiv = static_library(
  'lfiv',
  files('lfiv.c', 'arm64/verify.c', 'amd64/verify.c'),
  dependencies: [disarm.as_link_whole(), fadec.as_link_whole()],
  install: true,
  include_directories: include_directories('.'),
)

liblfiv_dep = declare_dependency(link_with: liblfiv, include_directories: include_directories('.'))

lfiv = executable(
  'lfi-verify',
  files('main.c'),
  link_with: [liblfiv],
  include_directories: include_directories('.'),
  c_args: '-Wno-missing-field-initializers',
  dependencies: [argp],
  install: true
)

install_headers('lfiv.h')

subdir('test')
