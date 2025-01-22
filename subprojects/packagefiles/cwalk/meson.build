project('cwalk', 'c', version: 'v1.2.9')

cwalk_files = [
  'src/cwalk.c'
]

libcwalk = static_library(
  'cwalk',
  cwalk_files,
  include_directories: include_directories('include'),
)

cwalk_dep = declare_dependency(
  link_with: libcwalk,
  include_directories: include_directories('include'),
)
