srcs += files(
  'amd64.c',
  'display.c',
  'flags.c',
)

leg_inputs = [
  'parse.leg',
  'syscall.leg',
  'special.leg',
  'decl.leg',
  'pextelim.leg',
  'tls.leg',
  'meter.leg',
]

leg_addr_inputs = [
  'branch.leg',
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
