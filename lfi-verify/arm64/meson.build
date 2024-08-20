disarm = subproject('disarm').get_variable('disarm64')

liblfiv_arm64 = static_library(
  'lfiverify-arm64',
  files('verify.c'),
  dependencies: [disarm.as_link_whole()],
  install: true,
  include_directories: include_directories('../include'),
)

liblfiv_arm64_dep = declare_dependency(link_with: [liblfiv_arm64], include_directories: include_directories('../include'))
