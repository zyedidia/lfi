project('zydis', 'c', version: '4.1.0', meson_version: '>=0.55.0')

zydis_files = [
  'src/Decoder.c',
  'src/DecoderData.c',
  'src/Disassembler.c',
  'src/Encoder.c',
  'src/EncoderData.c',
  'src/Formatter.c',
  'src/FormatterATT.c',
  'src/FormatterBase.c',
  'src/FormatterBuffer.c',
  'src/FormatterIntel.c',
  'src/MetaInfo.c',
  'src/Mnemonic.c',
  'src/Register.c',
  'src/Segment.c',
  'src/SharedData.c',
  'src/String.c',
  'src/Utils.c',
  'src/Zydis.c',
  'dependencies/zycore/src/Allocator.c',
  'dependencies/zycore/src/ArgParse.c',
  'dependencies/zycore/src/Bitset.c',
  'dependencies/zycore/src/Format.c',
  'dependencies/zycore/src/List.c',
  'dependencies/zycore/src/String.c',
  'dependencies/zycore/src/Vector.c',
  'dependencies/zycore/src/Zycore.c',
  'dependencies/zycore/src/API/Memory.c',
  'dependencies/zycore/src/API/Process.c',
  'dependencies/zycore/src/API/Synchronization.c',
  'dependencies/zycore/src/API/Terminal.c',
  'dependencies/zycore/src/API/Thread.c',
]

zydis_includes = [include_directories('include'), include_directories('src'), include_directories('dependencies/zycore/include')]

zydis_c_args = [
  '-DZYDIS_STATIC_BUILD',
]

libzydis = static_library('zydis', zydis_files,
  c_args: zydis_c_args,
  include_directories: zydis_includes,
  implicit_include_directories: false
)

zydis_dep = declare_dependency(
  link_with: libzydis,
  include_directories: zydis_includes
)
