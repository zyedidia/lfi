ld t0, (t1)
>>>
add.uw x18, t1, x21
ld t0, (x18)
------
ld t0, 16(t1)
>>>
add.uw x18, t1, x21
ld t0, 16(x18)
------
sd t0, (t1)
>>>
add.uw x18, t1, x21
sd t0, (x18)
------
sd t0, 16(t1)
>>>
add.uw x18, t1, x21
sd t0, 16(x18)
------
lw t0, (t1)
>>>
add.uw x18, t1, x21
lw t0, (x18)
------
lhu t0, 16(t1)
>>>
add.uw x18, t1, x21
lhu t0, 16(x18)
------
sb t0, (t1)
>>>
add.uw x18, t1, x21
sb t0, (x18)
------
ld t5, (gp)
sd t0, 25(t1)
>>>
add.uw x18, gp, x21
ld t5, (x18)
add.uw x18, t1, x21
sd t0, 25(x18)
