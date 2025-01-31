srcs += files(
  'sys_clock.c',
  'sys_file.c',
  'sys_info.c',
  'sys_ioctl.c',
  'sys_mem.c',
  'sys_proc.c',
  'sys_random.c',
  'sys_signal.c',
  'sys_fcntl.c',
  'sys_cwd.c',
  'sys_prctl.c',
  'sys_none.c',
  'strace.c',
)

if get_option('liblfi-threads')
  srcs += files('sys_thread.c')
endif
