tests = [
  'test_init.c',
  'test_raw.c',
  'test_tux.c',
  'test_fs.c',
]

test('test_init', executable(
  'test_init.elf',
  'test_init.c',
  dependencies: [liblfi_dep]
), suite: ['liblfi'])

lficc = find_program(cpu + '-lfi-linux-musl-clang', required: false)
if not lficc.found()
  warning('lficc not found: cannot test liblfi')
  subdir_done()
endif

go = find_program('go', required: false)
if not go.found()
  warning('go not found: cannot test liblfi')
  subdir_done()
endif

test_raw = executable(
  'test_raw.elf',
  'test_raw.c',
  dependencies: [liblfi_dep]
)

test_tux = executable(
  'test_tux.elf',
  'test_tux.c',
  dependencies: [liblfi_dep]
)

test_fs = executable(
  'test_fs.elf',
  'test_fs.c',
  dependencies: [liblfi_dep]
)

testdata = [
  {'bin': test_raw, 'file': 'raw/test.S', 'inputs': [], 'cflags': ['-nostdlib']},
  {'bin': test_tux, 'file': 'tux/hello.c', 'inputs': [], 'cflags': []},
  {'bin': test_tux, 'file': 'tux/alloc.c', 'inputs': [], 'cflags': []},
  {'bin': test_tux, 'file': 'tux/argv.c', 'inputs': ['one', 'two', 'three'], 'cflags': []},
  {'bin': test_tux, 'file': 'tux/file.c', 'inputs': ['tux/inputs/file.txt'], 'cflags': []},
  {'bin': test_tux, 'file': 'tux/chdir.c', 'inputs': ['tux/inputs', 'file.txt'], 'cflags': []},
  {'bin': test_tux, 'file': 'tux/thread.c', 'inputs': [], 'cflags': []},
  {'bin': test_fs, 'file': 'tux/fs.c', 'inputs': '/proc/self/test.txt', 'cflags': []}
]

foreach input : testdata
  out = input['file'].replace('/', '_') + '.lfi'
  exec = custom_target(out,
    output: out,
    input: input['file'],
    command: [lficc, '-O2', '-o', '@OUTPUT@', '@INPUT@', '-static-pie'] + input['cflags'],
  )
  expected = input['file'] + '.out'
  test(input['file'],
    go, args: ['run', 'run.go', expected, input['bin'], exec] + input['inputs'],
    workdir: meson.current_source_dir(),
    suite: ['liblfi']
  )
endforeach
