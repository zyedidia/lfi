lfi_wrap_src = ['main.go']

custom_target('lfi-wrap',
  output: 'lfi-wrap',
  input: lfi_wrap_src,
  command: [go, 'build', '-o', '@OUTPUT@', '@INPUT@'],
  build_by_default: true,
  install: true,
  install_dir: 'bin'
)
