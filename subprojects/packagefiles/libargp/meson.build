project('argp-standalone', 'c',
	version : '1.5.0',
	license : 'LGPL-2.1-or-later',
	default_options : ['c_std=gnu99'],
)

argp_source = files([
	'argp-ba.c',
	'argp-eexst.c',
	'argp-fmtstream.c',
	'argp-help.c',
	'argp-parse.c',
	'argp-pv.c',
	'argp-pvh.c',
	#'argp-test.c'
])

conf_data = configuration_data()

cc = meson.get_compiler('c')

conf_data.set10('HAVE_CONFIG_H', true)

conf_data.set10('HAVE_ALLOCA_H', cc.check_header('alloca.h'))
conf_data.set('HAVE_UNISTD_H', cc.check_header('unistd.h'))
conf_data.set('HAVE_EX_USAGE', cc.has_header_symbol('sysexits.h', 'EX_USAGE'))

conf_data.set10('HAVE_DECL_FLOCKFILE', cc.has_function('flockfile'))
conf_data.set10('HAVE_DECL_FPUTS_UNLOCKED', cc.has_function('fputs_unlocked', prefix : '#include <stdio.h>'))
conf_data.set10('HAVE_DECL_FPUTC_UNLOCKED', cc.has_function('fputc_unlocked', prefix : '#include <stdio.h>'))
conf_data.set10('HAVE_DECL_FWRITE_UNLOCKED', cc.has_function('fwrite_unlocked', prefix : '#include <stdio.h>'))
conf_data.set10('HAVE_DECL_PUTC_UNLOCKED', cc.has_function('putc_unlocked', prefix : '#include <stdio.h>'))

conf_data.set10('HAVE_MEMPCPY', cc.has_function('mempcpy', prefix : '#include <string.h>'))
conf_data.set10('HAVE_ASPRINTF', cc.has_function('asprintf', prefix: '#include <stdio.h>'))
conf_data.set10('HAVE_STRCHRNUL', cc.has_function('strchrnul', prefix: '#include <string.h>'))
conf_data.set10('HAVE_STRNDUP', cc.has_function('strndup', prefix: '#include <string.h>'))
conf_data.set10('HAVE_STRCASECMP', cc.has_function('strcasecmp', prefix: '#include <string.h>'))

conf_data.set10('HAVE_DECL_PROGRAM_INVOCATION_NAME',
			    cc.has_function('program_invocation_name', prefix : '#include <errno.h>'))
conf_data.set10('HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME',
				cc.has_function('program_invocation_short_name', prefix : '#include <errno.h>'))

configure_file(input : 'meson_config.h.in',
               output : 'config.h',
               configuration : conf_data)

add_project_arguments('-DHAVE_CONFIG_H=1', language : 'c')

if conf_data.get('HAVE_STRCHRNUL') == 0
	argp_source += files(['compat/strchrnul.c'])
endif
if conf_data.get('HAVE_STRNDUP') == 0
	argp_source += files(['compat/strndup.c'])
endif
if conf_data.get('HAVE_STRCASECMP') == 0
	argp_source += files(['compat/strcasecmp.c'])
endif
if conf_data.get('HAVE_MEMPCPY') == 0
	argp_source += files(['compat/mempcpy.c'])
endif

if host_machine.system() != 'windows'
	argp_library = static_library('argp',
		argp_source,
		include_directories : '.',
        c_args: ['-w'],
	)
else
	argp_library = static_library('argp',
		argp_source,
		include_directories : '.',
)
endif

argp_dep = declare_dependency(link_with : argp_library,
	include_directories : '.')
