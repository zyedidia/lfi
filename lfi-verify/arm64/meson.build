disarm = subproject('disarm').get_variable('disarm64')

liblfiv_arm64 = static_library(
  'lfiverify-arm64',
  files('verify.c'),
  dependencies: [disarm],
  install: true,
  include_directories: include_directories('../include'),
)
