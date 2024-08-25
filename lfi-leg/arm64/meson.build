srcs += files(
  'arm64.c',
  'fixup.c',
  'flags.c',
)


leg_inputs = [
  'branch.leg',
  'guardelim.leg',
  'parse.leg',
  'poc.leg',
  'special.leg',
  'meter.leg',
  'syscall.leg',
  'tls.leg',
]

leg_addr_inputs = [
  'loads.leg',
  'stores.leg',
]

foreach l : leg_inputs
  leg_srcs += custom_target(f'@l@.c',
    output: [f'@l@.c'],
    input: files(l, 'common.leg'),
    command: [leg, '-P', '-o', '@OUTPUT@', '@INPUT@'])
endforeach

foreach l : leg_addr_inputs
  leg_srcs += custom_target(f'@l@.c',
    output: [f'@l@.c'],
    input: files(l, 'addr.leg', 'common.leg'),
    command: [leg, '-P', '-o', '@OUTPUT@', '@INPUT@'])
endforeach
