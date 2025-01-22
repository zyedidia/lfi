if host == 'linux'
  srcs += files(
    'linux/random.c',
    'linux/dir.c',
    'linux/info.c',
    'linux/path.c',
    'linux/cpu.c',
    'linux/prctl.c',
    'posix/file.c',
    'posix/time.c',
  )
  if get_option('liblfi-threads')
    srcs += files(
      'linux/futex.c',
      'posix/thread.c',
    )
  endif
elif host == 'posix'
  srcs += files(
    'posix/random.c',
    'posix/file.c',
    'posix/dir.c',
    'posix/time.c',
    'posix/path.c',
    'posix/info.c',
    'posix/cpu.c',
    'posix/prctl.c',
  )
  if get_option('liblfi-threads')
    srcs += files(
      'posix/futex.c',
      'posix/thread.c',
    )
  endif
endif
