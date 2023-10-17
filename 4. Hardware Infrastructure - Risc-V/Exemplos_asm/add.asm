lw x10, v1
lw x11, v2
add x12, x10, x11
halt
v1: .word 0x4
v2: .word 0x1000
