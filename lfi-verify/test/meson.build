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
  'amd64/fail_decl.s',
  'amd64/pass_decl.s',
]

clang = find_program('clang', required: false)

if clang.found()
  foreach t : tests_arm64
    test('@0@'.format(t), go, args: ['run', 'runtest.go', '-arch', 'arm64', lfiv, t], workdir: meson.current_source_dir(), suite: ['lfi-verify', 'arm64'], protocol: 'tap')
  endforeach

  foreach t : tests_amd64
    test('@0@'.format(t), go, args: ['run', 'runtest.go', '-arch', 'amd64', lfiv, t], workdir: meson.current_source_dir(), suite: ['lfi-verify', 'amd64'], protocol: 'tap')
  endforeach
endif
