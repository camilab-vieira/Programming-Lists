loop:
	lb x10, 20(x0)
	sb x10, 1027(x0)
	lb x10, 21(x0)
	sb x10, 1027(x0)
	jal x11, loop

HIGH: .byte 1
LOW: .byte 0
