srcs += files(
  'display.c',
  'flags.c',
  'riscv64.c',
)

leg_inputs = [
  'branch.leg',
  'syscall.leg',
  'parse.leg',
  'special.leg',
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
