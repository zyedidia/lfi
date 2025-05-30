host = get_option('liblfi-host')

srcs = files(
  'tux.c',
  'buf.c',
  'proc.c',
  'elfload.c',
  'elfsym.c',
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

breakpoint = []
if get_option('liblfi-gdb')
  breakpoint = subproject('libbreakpoint').get_variable('libbreakpoint_dep')
endif

config_h = configure_file(
  output: 'config.h',
  configuration: {
    'CONFIG_MAX_FUTEX': get_option('liblfi-max_futex'),
    'CONFIG_THREADS':   get_option('liblfi-threads'),
    'CONFIG_GDB':       get_option('liblfi-gdb'),
    'SYS_EXTERNAL':     get_option('liblfi-dlopen'),
  }
)

liblfi = static_library(
  'lfi',
  sources: srcs + [config_h],
  c_args: c_args_hardened + c_args_warnings + defines + ['-fvisibility=hidden'],
  include_directories: include_directories('include', 'arch/' + xcpuarch, 'arch/'),
  dependencies: [
    cwalk.get_variable('cwalk_dep').as_link_whole(),
    mmap.get_variable('mmap').as_link_whole(),
    boxmap.get_variable('boxmap').as_link_whole(),
    get_option('liblfi-gdb') ? breakpoint.as_link_whole() : [],
    liblfiv_dep.as_link_whole(),
  ],
  install: true,
)

install_headers('include/lfi.h')
install_headers('include/lfi_tux.h')
install_headers('include/lfi_arch.h')
install_headers('include/lfi_host.h')

liblfi_dep = declare_dependency(link_with: liblfi, include_directories: include_directories('include'))

if not get_option('liblfi-tests')
  subdir_done()
endif

subdir('test')
