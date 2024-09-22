tests_arm64 = [
  'arm64/pass.s',
  'arm64/pass_msr.s',
  'arm64/fail.s',
  'arm64/fail_decl.s',
  'arm64/pass_decl.s',
]

tests_amd64 = [
  'amd64/pass.s',
  'amd64/fail.s',
]

amd64_lfi_gcc = find_program('x86_64-linux-gnu-gcc', required: false)
arm64_lfi_gcc = find_program('aarch64-none-elf-gcc', required: false)

if arm64_lfi_gcc.found()
  foreach t : tests_arm64
    test('@0@'.format(t), go, args: ['run', 'runtest.go', '-arch', 'arm64', lfiv, t], workdir: meson.current_source_dir(), suite: ['lfi-verify', 'arm64'])
  endforeach
endif

if amd64_lfi_gcc.found()
  foreach t : tests_amd64
    test('@0@'.format(t), go, args: ['run', 'runtest.go', '-arch', 'amd64', lfiv, t], workdir: meson.current_source_dir(), suite: ['lfi-verify', 'amd64'])
  endforeach
endif
