init:
	addi x10, x0, 3
	add x11, x0, x0
	sb x10, 1033(x0)
loop:
	sb x11, 1034(x0)
	addi x11, x11, 1
	jal x12, loop






