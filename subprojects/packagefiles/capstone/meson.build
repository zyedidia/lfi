project('capstone', 'c', version: '5.0.1', meson_version: '>=0.55.0')

cs_files = [
  'arch/AArch64/AArch64BaseInfo.c',
  'arch/AArch64/AArch64Disassembler.c',
  'arch/AArch64/AArch64InstPrinter.c',
  'arch/AArch64/AArch64Mapping.c',
  'arch/AArch64/AArch64Module.c',
  'arch/X86/X86ATTInstPrinter.c',
  'arch/X86/X86Disassembler.c',
  'arch/X86/X86DisassemblerDecoder.c',
  'arch/X86/X86IntelInstPrinter.c',
  'arch/X86/X86Mapping.c',
  'arch/X86/X86Module.c',
  'arch/X86/X86InstPrinterCommon.c',
  'cs.c',
  'MCInst.c',
  'MCInstrDesc.c',
  'MCRegisterInfo.c',
  'SStream.c',
  'Mapping.c',
  'utils.c',
]

capstone_includes = [include_directories('include'), include_directories('include/capstone')]

has_no_stringop_overflow = meson.get_compiler('c').has_argument('-Wno-stringop-overflow')

libcapstone_c_args = [
  '-DCAPSTONE_X86_ATT_DISABLE_NO',
  '-DCAPSTONE_X86_REDUCE_NO',
  '-DCAPSTONE_USE_SYS_DYN_MEM',
  '-DCAPSTONE_DIET_NO',
  '-DCAPSTONE_HAS_ARM64',
  '-DCAPSTONE_HAS_X86',
]

if has_no_stringop_overflow
  libcapstone_c_args += '-Wno-stringop-overflow'
endif

libcapstone = library('capstone', cs_files,
  c_args: libcapstone_c_args,
  include_directories: capstone_includes,
  implicit_include_directories: false
)

capstone_dep = declare_dependency(
  link_with: libcapstone,
  include_directories: capstone_includes
)
