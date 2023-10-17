lw x10, v1
lw x11, v2
sltu x12, x10, x11
halt
v1: .word 0xdfffffff
v2: .word 0x10000
