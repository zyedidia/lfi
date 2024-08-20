tests = [
  'test1.c',
]

test_so = custom_target(
  'test_so',
  output: ['libtest.so'],
  input: files('lib.c'),
  command: [lfi_gcc, '@INPUT@', '-O2', '-o', '@OUTPUT@', '-shared'],
)

foreach t : tests
  test(t, executable(t + '.elf', t, test_so, dependencies: [sobox, liblfi_dep]), suite: ['libsobox'])
endforeach
