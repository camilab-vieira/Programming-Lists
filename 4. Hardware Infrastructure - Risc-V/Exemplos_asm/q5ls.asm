addi x18, x0, 64
addi x19, x0, 64
addi x20, x0, 64
addi x21, x0, 64
addi x22, x0, 64
addi x23, x0, 64
addi x24, x0, 64
addi x25, x0, 64
add x26, x0, x0
add x27, x0, x0
addi x16, x0, 48
add x14, x0, x18
addi x13, x0, 1

loop:
lb x10, 1025(x0) 
beq x10, x16, end1

loop2:
lb x11, 0(x14) 
beq x10, x11, inc1
addi x14, x14, 1
bne x11, x16, loop2 

jal x15, loop

inc:
addi x13, x13, 1
jal x15, loop

end1:
addi x14, x0, x19
addi x13, x13, 1
jal x15, loop2

end:
addi x13, x13, 48
sb x13, 1024(x0)

x1: .string "AEIOU0"
x2: .string "DGT0"
x3: .string "BCMNP0"
x4: .string "FHVWY0"
x5: .string "KRS0"
x6: .string "JLX0"
x7: .string "QZ0"
