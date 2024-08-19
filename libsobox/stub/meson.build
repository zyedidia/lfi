sbxstub = custom_target(
  'sbxstub',
  output: ['sbxstub'],
  input: files('stub.c'),
  depend_files: files('stub.h'),
  command: [lfi_gcc, '@INPUT@', '-o', '@OUTPUT@'],
)
