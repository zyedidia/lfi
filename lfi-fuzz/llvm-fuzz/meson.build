if not has_fuzzer
  warning('LLVM fuzzing is disabled because -fsanitize=fuzzer is not supported')
  subdir_done()
endif

llvm_fuzz = executable(
  'llvm-fuzz',
  files('target.c'),
  dependencies: [liblfiv_fuzz_dep],
  c_args: ['-fsanitize=fuzzer'],
  link_args: ['-fsanitize=fuzzer'],
)
