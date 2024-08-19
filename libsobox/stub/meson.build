sbxstub = custom_target(
  'sbxstub',
  output: ['stub'],
  input: files('stub.c'),
  depend_files: files('stub.h'),
  command: [lfi_gcc, '@INPUT@', '-o', '@OUTPUT@'],
)

sbxstub_inc = custom_target(
  'sbxstub_inc',
  output: ['stub.inc'],
  input: sbxstub,
  command: [xxd, '-i', '@INPUT@', '@OUTPUT@']
)
