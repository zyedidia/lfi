arches = {
  'aarch64': 'aarch64_lfi',
  'x86_64': 'x86_64',
}

if not lfi_gcc.found()
  message('LFI GCC was not found, cannot perform lfi-run tests')
  subdir_done()
endif

tests = [
  'hello.c',
  'alloc.c',
  'argv.c',
  'file.c',
  'chdir.c',
  # 'fork.c', TODO: enable test
  'exec.c',
]

foreach tc : tests
  tc_path = files(tc)[0]
  targ = custom_target(
    f'@tc@.elf',
    output: [f'@tc@.elf'],
    input: tc_path,
    command: [lfi_gcc, '@INPUT@', '-o', '@OUTPUT@', '-static-pie'],
  )
  test('@0@'.format(tc_path), lfi_run, args: ['--no-verify', targ], suite: 'lfi-run')
endforeach
