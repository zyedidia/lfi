project('libbreakpoint', 'c', version: 'v1.0.0')

libbreakpoint = static_library('breakpoint',
  'libbreakpoint/libbreakpoint.c',
  include_directories: 'libbreakpoint',
  c_args: ['-DLIBBREAKPOINT_DEFAULT_DISABLED', '-DLIBBREAKPOINT_DOTDUMP_DISABLED', '-Wno-unused-variable', '-Wno-unused-function', '-Wno-switch', '-Wno-unused-result'],
)

libbreakpoint_dep = declare_dependency(link_with: libbreakpoint, include_directories: 'libbreakpoint')
