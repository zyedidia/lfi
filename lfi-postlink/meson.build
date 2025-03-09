capstone = subproject('capstone', default_options: ['default_library=static']).get_variable('capstone_dep')
zydis = subproject('zydis').get_variable('zydis_dep')
fadec = subproject('fadec').get_variable('fadec')

lfi_postlink = executable(
  'lfi-postlink',
  files('amd64.c', 'arm64.c', 'main.c'),
  dependencies: [disarm, capstone, zydis, argp, fadec],
  install: true,
)
