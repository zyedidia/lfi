subdir('disarm')
lfiv_arm64_inc = include_directories('disarm', '../include')

lfiv_arm64_srcs = files('verify.c')

lfiv_arm64 = static_library('lfiv-arm64', lfiv_arm64_srcs + disarm_srcs, instr_data, include_directories: lfiv_arm64_inc, install: true, c_args: ['-Wno-unused-function'])
