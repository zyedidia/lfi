host = get_option('liblfi-host')

srcs = files(
  'tux.c',
  'buf.c',
  'proc.c',
  'elfload.c',
  'sys.c',
  'file.c',
  'fd.c',
  'perf.c',
  'err.c',
  'host.c',
)

subdir('pal')
subdir('syscalls')
subdir('arch/' + xcpuarch)
subdir('host')

cwalk = subproject('cwalk')
mmap = subproject('libmmap')
boxmap = subproject('libboxmap')

defs = []

libelf = []
if get_option('liblfi-perf')
  libelf = dependency('libelf', required: false)
  if libelf.found()
    defs += '-DHAVE_LIBELF'
  endif
endif

config_h = configure_file(
  output: 'config.h',
  configuration: {
    'CONFIG_MAX_FUTEX': get_option('liblfi-max_futex'),
    'CONFIG_THREADS':   get_option('liblfi-threads'),
  }
)

liblfi = static_library(
  'lfi',
  sources: srcs + [config_h],
  c_args: c_args_hardened + c_args_warnings + defs,
  include_directories: include_directories('include', 'arch/' + xcpuarch, 'arch/'),
  dependencies: [cwalk.get_variable('cwalk_dep'), mmap.get_variable('mmap'), boxmap.get_variable('boxmap'), libelf],
  link_whole: [cwalk.get_variable('libcwalk'), mmap.get_variable('libmmap'), boxmap.get_variable('libboxmap')],
  install: true,
)

install_headers('include/lfi.h')
install_headers('include/lfi_tux.h')
install_headers('include/lfi_arch.h')
install_headers('include/lfi_host.h')

liblfi_dep = declare_dependency(link_with: liblfi, include_directories: include_directories('include'))

subdir('test')
