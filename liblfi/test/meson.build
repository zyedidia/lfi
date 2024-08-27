tests = [
  'init.c',
  'run.c',
]

if not xxd.found()
  warning('xxd not found: cannot test liblfi')
  subdir_done()
endif

gcc = meson.get_compiler('c')

testprog = executable('testprog', 'testprog.S', link_args: ['-nostdlib', '-static-pie'])

testprog_inc = custom_target(
  'testprog_inc',
  output: ['testprog.inc'],
  input: testprog,
  command: [xxd, '-i', '@INPUT@', '@OUTPUT@']
)

foreach t : tests
  test(t, executable(
    t + '.elf',
    t, testprog_inc,
    dependencies: [liblfi_dep],
  ), suite: ['liblfi'])
endforeach
