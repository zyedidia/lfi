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
  warning('Cannot build lfi-run for architecture: '+ cpu)
  subdir_done()
endif

has_d = add_languages('d', native: false, required: false)
if not has_d
  warning('No D compiler found, lfi-run will not be built')
  subdir_done()
endif

versions += archdir[cpu]

r = run_command('getconf', 'PAGESIZE', check: false)
if r.returncode() == 0 and r.stdout().strip() == '16384'
  versions += 'page16k'
endif

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
  'lfi/env.d',
)

subdir('core')
subdir('cwalk')
subdir('buddy')
subdir('arch')

lfi_run = executable('lfi-run', srcs, d_args: d_args, d_module_versions: versions, link_args: ['-betterC'], link_with: [liblfi, liblfiv_arm64, liblfiv_amd64], install: true)

subdir('test')
