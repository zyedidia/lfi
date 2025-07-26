# Benchmarking Guide

## SPEC 2017

Since SPEC 2017 is a proprietary benchmark suite, you must have your own
installation. We will assume you have installed it to `$CPU2017`.

First, you need to install our wrapper `specinvoke` tool. This tool allows
us to override the SPEC runner to use `lfi-run` to run compiled binaries.
The tool can be found in this repository (https://github.com/zyedidia/lfi)
in `specinvoke/`.

Rename the original `specinvoke` tool to `specinvoke.orig` (this will be used
by our wrapper).

```
cd $CPU2017
mv bin/specinvoke bin/specinvoke.orig
```

Now build the wrapper:

```
cd /path/to/lfi
cd specinvoke
go build -o $CPU2017/bin/specinvoke
```

We also have a few patches to SPEC 2017 that must be applied so that benchmarks
work with recent versions of LLVM/GCC and with Musl.

```
cd $CPU2017
/path/to/lfi/specinvoke/patches/apply.sh
```

Finally, you must tell SPEC to not perform integrity checking, since we have
modified `specinvoke`:

```
cd $CPU2017
mv version.txt version.txt.old
echo '0.0.0' > version.txt
export SPEC_NOCHECK=1
```

We also recommend using our SPEC configuration files, located in `specinvoke/config`.

We also have scripts in `specinvoke/bench` for running all the benchmarks, and
for CPU shielding (pinning benchmarks to a core and moving all other processes
off of that core).

For example, to run all the benchmarks I do:

```
$ cd $CPU2017
$ ./shield-aarch64.sh # Enter shielded subshell
$ ./bench.sh
All benchmarks run, putting results in result/
```

## `lfi-bench`

See https://github.com/lfi-project/lfi-bench. More information coming soon!
