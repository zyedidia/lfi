sbxstub = custom_target(
  'sbxstub',
  output: ['stub'],
  input: files('stub.c', 'stub.S'),
  depend_files: files('stub.h', 'stubasm.h'),
  command: [lfi_gcc, '@INPUT@', '-O2', '-o', '@OUTPUT@'],
)

sbxstub_inc = custom_target(
  'sbxstub_inc',
  output: ['stub.inc'],
  input: sbxstub,
  command: [xxd, '-i', '@INPUT@', '@OUTPUT@']
)
