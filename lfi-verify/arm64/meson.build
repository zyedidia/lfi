subdir('disarm')
lfiv_arm64_inc = include_directories('disarm', '../include')

lfiv_arm64_srcs = files('verify.c')

liblfiv_arm64 = static_library('lfiverify-arm64', lfiv_arm64_srcs + disarm_srcs, instr_data, include_directories: lfiv_arm64_inc, install: true, c_args: ['-Wno-unused-function'])
