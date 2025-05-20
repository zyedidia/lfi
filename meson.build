project(
  'lfi',
  ['c', 'cpp'],
  default_options: ['warning_level=1', 'buildtype=release'],
  meson_version: '>=0.60.3',
  version: run_command('git', 'rev-parse', '--short', 'HEAD', check: false).stdout().strip()
)

add_project_arguments('-D_LARGEFILE64_SOURCE', '-D_FILE_OFFSET_BITS=64', '-Werror=implicit-function-declaration', language : 'c')

compiler = meson.get_compiler('c')

# Enable various hardening flags (used by liblfi and liblfix).
c_args_hardened = [
  '-fno-strict-aliasing',
  '-fno-delete-null-pointer-checks',
  '-fno-strict-overflow',
  '-Werror=implicit',
  '-Werror=incompatible-pointer-types',
  '-Werror=int-conversion',
]

c_args_warnings = [
  '-Wno-unused-parameter',
  '-Wno-gnu-zero-variadic-macro-arguments',
]

has_auto_var_init = compiler.has_argument('-ftrivial-auto-var-init=zero')
if has_auto_var_init
  c_args_hardened += '-ftrivial-auto-var-init=zero'
endif
has_fuzzer = compiler.has_argument('-fsanitize=fuzzer')

argp = subproject('argp').get_variable('argp_dep')

cpu = target_machine.cpu_family()

archmap = {
  'aarch64': 'arm64',
  'x86_64': 'amd64',
}
xarchmap = {
  'aarch64': 'arm64',
  'x86_64': 'x64',
}

if not archmap.has_key(cpu)
  warning('unsupported architecture: ' + cpu)
  subdir_done()
endif

defines = []
if compiler.has_function('getdents64', prefix : '''#define _GNU_SOURCE
#include <dirent.h>''')
  defines += '-DHAVE_GETDENTS64'
endif
if compiler.has_function('memfd_create', prefix : '''#define _GNU_SOURCE
#include <sys/mman.h>''')
  defines += '-DHAVE_MEMFD_CREATE'
endif
if compiler.has_function('getentropy', prefix : '#include <unistd.h>')
  defines += '-DHAVE_GETENTROPY'
endif
if compiler.has_function('getrandom', prefix : '#include <sys/random.h>')
  defines += '-DHAVE_GETRANDOM'
endif
if compiler.has_function('arc4random_buf', prefix : '#include <stdlib.h>')
  defines += '-DHAVE_ARC4RANDOM_BUF'
endif

cpuarch = archmap[cpu]
xcpuarch = xarchmap[cpu]

go = find_program('go')
xxd = find_program('xxd', required: false)
cp = find_program('cp')

subdir('lfi-verify')

if not get_option('liblfi-only')
  subdir('lfi-leg')
  subdir('lfi-postlink')
  if get_option('fuzzer')
    subdir('lfi-fuzz')
  endif
  # subdir('lfi-veribdd')
  subdir('specinvoke')
endif
if not get_option('tools-only')
  subdir('liblfi-small')
  if get_option('liblfi') == 'standard'
    subdir('liblfi')
  endif
  subdir('lfi-run')
endif
