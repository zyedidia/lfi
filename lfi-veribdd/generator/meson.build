bdd = meson.get_compiler('cpp').find_library('bdd')
omp = dependency('openmp')

genbdd = executable('genbdd', files('genbdd.cc'), dependencies: [liblfiv_arm64_dep, bdd, omp])
