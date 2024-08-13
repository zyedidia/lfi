lfi_compile_src = [ 'main.go' ]

custom_target('lfi-compile',
  output : 'lfi-compile',
  input : lfi_compile_src,
  command : [go, 'build', '-o', '@OUTPUT@', '@INPUT@'],
  build_by_default: true,
  install: true,
  install_dir: 'bin'
)
