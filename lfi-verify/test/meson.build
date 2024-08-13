tests_arm64 = files('arm64/pass.s', 'arm64/pass_msr.s', 'arm64/fail.s')

foreach t : tests_arm64
  test('@0@'.format(t), find_program('go'), args: ['run', 'runtest.go', lfiv, t], workdir: meson.current_source_dir())
endforeach
