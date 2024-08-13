specinvoke_src = ['main.go']

custom_target('specinvoke',
  output: 'specinvoke',
  input: specinvoke_src,
  command: [go, 'build', '-o', '@OUTPUT@', '@INPUT@'],
  build_by_default: true,
  install: true,
  install_dir: 'bin'
)
