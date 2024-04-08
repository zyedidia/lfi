bar:
nop
nop
nop
b foo

foo:
nop
nop
nop
b bar

b.ls bar
