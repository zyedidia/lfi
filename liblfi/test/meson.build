tests = [
  'init.c',
]

foreach t : tests
  test(t, executable(
    t + '.elf',
    t,
    dependencies: [liblfi_dep],
  ), suite: ['liblfi'])
endforeach
