srcs += files(
  'amd64.c',
  'display.c',
  'flags.c',
)

leg_inputs = [
  'parse.leg',
  'syscall.leg',
  'decl.leg',
  'pextelim.leg',
  'meter.leg',
  'poc.leg',
]

leg_addr_inputs = [
  'branch.leg',
  'loads.leg',
  'stores.leg',
  'special.leg',
  'tls.leg',
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
