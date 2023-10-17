loop:
	lb x10, 1026(x0)
	andi x10, x10, 0x1
	jal x11, loop

