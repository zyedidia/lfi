fadec = subproject('fadec').get_variable('fadec')

liblfiv_amd64 = static_library(
  'lfiverify-amd64',
  files('verify.c'),
  dependencies: [fadec.as_link_whole()],
  install: true,
  include_directories: include_directories('../include'),
)
