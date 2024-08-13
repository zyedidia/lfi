capstone = subproject('capstone', default_options: ['default_library=static']).get_variable('capstone_dep')
zydis = dependency('Zydis', version: '>=4.0.0.0')

lfi_postlink = executable(
  'lfi-postlink',
  files('amd64.c', 'arm64.c', 'main.c'),
  dependencies: [capstone, zydis],
  install: true
)
