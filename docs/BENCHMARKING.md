# Setting up SPEC 2017

First ensure that SPEC 2017 is installed. Next install our wrapper `specinvoke`
tool. You must first rename the original specinvoke tool:

```
cd /path/to/cpu2017
mv bin/specinvoke bin/specinvoke.orig
```

Then you can install ours to the same location:

```
cd /path/to/lfi
go build -o /path/to/cpu2017/bin/specinvoke ./specinvoke
```

If you would like to benchmark WebAssembly, you will also need to apply some
minor patches so that the nab and x264 benchmarks will build.

```
cd /path/to/cpu2017
/path/to/lfi/specinvoke/patches/apply.sh
```

Finally, you must tell SPEC to not perform integrity checking:

```
cd /path/to/cpu2017
mv version.txt version.txt.old
echo '0.0.0' > version.txt
export SPEC_NOCHECK=1
```

Please also install our SPEC 2017 configuration files:

```
cd /path/to/cpu2017
cp /path/to/lfi/specinvoke/config/* ./config
```

# Running SPEC 2017

A benchmarking script is provided in `specinvoke/bench/bench.sh`. You can move
that script to `/path/to/cpu2017`, and invoke it to run all the benchmarks.

Here is an overview of how to run individual benchmarks.

## LFI

To perform a test run of the small `mcf_r` benchmark:

```
LOADER=lfi-run runcpu --config=lfi-lto --action=run --size=test mcf_r
```

To perform a full run:

```
LOADER=lfi-run runcpu --config=lfi-lto --action=run --size=ref gcc_r omnetpp_r mcf_r xalancbmk_r deepsjeng_r leela_r xz_r namd_r parest_r povray_r lbm_r imagick_r nab_r x264_r
```

## LFI native

```
LOADER=lfi-run runcpu --config=lfi-native-lto --action=run --size=ref gcc_r omnetpp_r mcf_r xalancbmk_r deepsjeng_r leela_r xz_r namd_r parest_r povray_r lbm_r imagick_r nab_r x264_r
```

## WebAssembly
