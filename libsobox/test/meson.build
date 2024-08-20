tests = [
  'test1.c',
]

foreach t : tests
  test(t, executable(t + '.elf', t, dependencies: [sobox, liblfi_dep]), suite: ['libsobox'])
endforeach
