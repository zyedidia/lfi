capstone = subproject('capstone', default_options: ['default_library=static']).get_variable('capstone_dep')
zydis = subproject('zydis').get_variable('zydis_dep')

lfi_postlink = executable(
  'lfi-postlink',
  files('amd64.c', 'arm64.c', 'main.c'),
  dependencies: [capstone, zydis, argp],
  install: true,
)
