d_args = [
  '-betterC',
]

versions = []

archdir = {
  'aarch64': 'arm64',
  'x86_64': 'amd64',
}

cpu = target_machine.cpu_family()

if not archdir.has_key(cpu)
  warning('cannot build lfi-run for architecture: '+ cpu)
  subdir_done()
endif

add_languages('d', native: false, required: false)

versions += archdir[cpu]

srcs = files(
  'elf.d',
  'fd.d',
  'file.d',
  'main.d',
  'object.d',
  'pipe.d',
  'proc.d',
  'queue.d',
  'sched.d',
  'signal.d',
  'sys.d',
  'lfi/package.d',
)

subdir('core')
subdir('cwalk')
subdir('buddy')
subdir('arch')

lfi_run = executable('lfi-run', srcs, d_args: d_args, d_module_versions: versions, link_args: ['-betterC'], link_with: [liblfi, liblfiv_arm64], install: true)
