tests = {
  'arm64': [
    'arm64/arith.s',
    'arm64/br.s',
    'arm64/decl.s',
    'arm64/fixup.s',
    'arm64/guardelim.s',
    'arm64/ldst.s',
    'arm64/meter.s',
    'arm64/meter_fp.s',
    'arm64/meter_timer.s',
    'arm64/poc.s',
    'arm64/storesonly.s',
    'arm64/syscall.s',
    'arm64/sysexternal.s',
    'arm64/tls.s',
  ],
  'amd64': [
    'amd64/branch.s',
    'amd64/bundle16.s',
    'amd64/bundlejumps.s',
    'amd64/decl.s',
    'amd64/ldst.s',
    'amd64/mod.s',
    'amd64/nosegue.s',
    'amd64/singlethread.s',
    'amd64/storesonly.s',
    'amd64/string.s',
    'amd64/syscall.s',
    'amd64/variable.s',
    'amd64/tls.s',
    'amd64/meter_timer.s',
    'amd64/meter.s',
    'amd64/poc.s',
  ],
  'riscv64': [
    'riscv64/arith.s',
    'riscv64/br.s',
    'riscv64/ldst.s',
    'riscv64/storesonly.s',
    'riscv64/syscall.s',
  ]
}


foreach arch, atests : tests
  foreach t : atests
    test(t, go, args: ['run', 'runtest.go', '-arch', arch, lfi_leg, t], workdir: meson.current_source_dir(), suite: ['lfi-leg', arch], protocol: 'tap')
  endforeach
endforeach
