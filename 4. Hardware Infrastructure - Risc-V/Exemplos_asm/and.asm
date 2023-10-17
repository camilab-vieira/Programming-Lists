lw x10, v1
lw x11, v2
and x12, x10, x11
halt
v1: .word 0x8000000
v2: .word 0x100000
