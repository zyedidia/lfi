bdd = meson.get_compiler('cpp').find_library('bdd', required: false)
omp = dependency('openmp', required: false)

if not bdd.found()
  warning('libbdd-dev not found, lfi-veribdd will not be built')
  subdir_done()
endif

if not omp.found()
  warning('openmp not found, lfi-veribdd will not be built')
  subdir_done()
endif

genbdd = executable('genbdd', files('genbdd.cc'), dependencies: [liblfiv_arm64_dep, bdd, omp])
