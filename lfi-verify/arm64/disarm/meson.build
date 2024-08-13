python3 = find_program('python3')

# Check Python version
py_version_res = run_command(python3, ['--version'], check: true)
py_version = py_version_res.stdout().split(' ')[1]
if py_version_res.returncode() != 0 or not py_version.version_compare('>=3.10')
  error('Python 3.10 required, got @0@'.format(py_version))
endif

features = 'lse'
parse_args = ['--features', features]
if get_option('b_coverage')
  parse_args += ['--coverage']
endif

instr_data = custom_target('tables',
                           command: [python3, '@INPUT0@', '@OUTPUT@', '@INPUT1@', '--feature-desc', '@INPUT2@', '--encode-in-header'] + parse_args,
                           input: files('parse.py', 'desc.txt', 'feat.txt'),
                           output: ['disarm64-public.inc', 'disarm64-private.inc'])

disarm_srcs = files('classify.c', 'decode.c', 'format.c')

libdisarm64 = static_library('disarm64', 'classify.c', 'decode.c', 'encode.c', 'format.c', instr_data, c_args: ['-Wno-unused-function'])
disarm64 = declare_dependency(link_with: libdisarm64,
                              include_directories: include_directories('.'),
                              sources: instr_data)
meson.override_dependency('disarm64', disarm64)
