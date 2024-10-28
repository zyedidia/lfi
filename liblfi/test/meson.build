tests = [
  'init.c',
  'run.c',
  'uproc.c',
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

uproc_ld = custom_target(
  'uproc.ld',
  output: ['uproc.ld'],
  input: files('uproc.ld').get(0),
  command: [cp, '@INPUT@', '@OUTPUT@']
)

testuprog = executable('testuprog', 'testprog.S', link_args: ['-nostdlib', '-static', '-T', uproc_ld.full_path()], link_depends: uproc_ld)

testuprog_inc = custom_target(
  'testuprog_inc',
  output: ['testuprog.inc'],
  input: testuprog,
  command: [xxd, '-i', '@INPUT@', '@OUTPUT@']
)

foreach t : tests
  test(t, executable(
    t + '.elf',
    t, testprog_inc, testuprog_inc,
    dependencies: [liblfi_dep, liblfiv_dep],
  ), suite: ['liblfi'])
endforeach
