disarm = subproject('disarm').get_variable('disarm64')
fadec = subproject('fadec').get_variable('fadec')

srcs = files(
  'arm64/verify.c',
  'amd64/verify.c',
)

liblfiv = static_library(
  'lfiv',
  srcs,
  dependencies: [disarm.as_link_whole(), fadec.as_link_whole()],
  install: true,
  include_directories: include_directories('.'),
)

liblfiv_dep = declare_dependency(link_with: liblfiv, include_directories: include_directories('.'))

if has_fuzzer
  disarm_fuzz = subproject('disarm').get_variable('disarm64_fuzz')
  liblfiv_fuzz = static_library(
    'lfiv-fuzzinst',
    srcs,
    dependencies: [disarm_fuzz.as_link_whole(), fadec.as_link_whole()],
    c_args: ['-fsanitize=fuzzer'],
  )
  liblfiv_fuzz_dep = declare_dependency(link_with: liblfiv_fuzz, include_directories: include_directories('.'))
endif

lfiv = executable(
  'lfi-verify',
  files('main.c'),
  link_with: [liblfiv],
  include_directories: include_directories('.'),
  c_args: '-Wno-missing-field-initializers',
  dependencies: [argp],
  install: true
)

install_headers('lfiv.h')

subdir('test')
