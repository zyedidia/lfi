# Enable various hardening flags.
c_args = [
  '-fno-strict-aliasing',
  '-fno-delete-null-pointer-checks',
  '-fno-strict-overflow',
  '-Werror=implicit',
  '-Werror=incompatible-pointer-types',
  '-Werror=int-conversion',
]

has_auto_var_init = meson.get_compiler('c').has_argument('-ftrivial-auto-var-init=zero')
if has_auto_var_init
  c_args += '-ftrivial-auto-var-init=zero'
endif

srcs = [
  'engine.c',
  'err.c',
  'proc.c',
  'buddy.c',
]

archdir = {
  'aarch64': 'arch/arm64',
  'x86_64': 'arch/amd64',
}

cpu = target_machine.cpu_family()

if not archdir.has_key(cpu)
  warning('cannot build liblfi for architecture: ' + cpu)
  subdir_done()
endif

subdir(archdir[cpu])

liblfi = static_library('lfi', srcs, c_args: c_args, install: true)

install_headers('lfi.h')

liblfi_dep = declare_dependency(link_with: liblfi, include_directories: include_directories('.'))

subdir('test')
