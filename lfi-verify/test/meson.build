test_srcs_arm64 = files('arm64/pass.s', 'arm64/fail.s')

test('arm64', find_program('go'), args: ['run', 'runtest.go', lfiv, test_srcs_arm64], workdir: meson.current_source_dir())
