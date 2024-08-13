capstone = dependency('capstone')
zydis = dependency('Zydis')

lfi_postlink = executable(
  'lfi-postlink',
  files('amd64.c', 'arm64.c', 'main.c'),
  dependencies: [capstone, zydis],
  install: true
)
