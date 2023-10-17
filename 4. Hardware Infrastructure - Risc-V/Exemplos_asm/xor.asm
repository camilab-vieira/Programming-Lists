lw x10, v1
lw x11, v2
xor x12, x10, x11
halt
v1: .word 0x80
v2: .word 0x400
