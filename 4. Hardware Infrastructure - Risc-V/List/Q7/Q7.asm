lb x10, 0(x0)           #Carrega x10 com 0
sb x10, 1030(x0)        #Escrita do num (0) do pino (analogico) para leitura

loop:
lh x10, 1031(x0)	    #Leitura analogica do pin A0

redR:
    addi x12, x0, 634   #634 = 31
    blt x10, x12, redL  #Se o numero informado na leitura for menor que isso, segue para os outros casos
    lb x14, 133(x0)     #Caso > 30, carrega o numero 2 no reg x14. 2 = 0b10, ou seja, pin 9
    sb x14, 1027(x0)    #Acende o led mapeado para o pin 9
    jal x1, loop        #Volta para o inicio do loop e recebe um novo valor

redL:
    addi x12, x0, 225
    bge x10, x12, yellowL
    lb x14, 132(x0)
    sb x14, 1027(x0)
    jal x1, loop

yellowL:
    addi x12, x0, 327
    bge x10, x12, yellowR
    lb x14, 134(x0) 
    sb x14, 1027(x0)
    jal x1, loop

yellowR:
    addi x12, x0, 429
    bge x10, x12, greenL
    lb x14, 135(x0)
    sb x14, 1027(x0)
    jal x1, loop

greenL: 
    addi x12, x0, 531
    bge x10, x12, greenR
    lb x14, 136(x0)
    sb x14, 1027(x0)
    jal x1, loop

greenR:
    addi x12, x0, 634
    bge x10, x12, loop
    lb x14, 137(x0)
    sb x14, 1027(x0)
    jal x1, loop

rl: .byte 1
rr: .byte 2
yl: .byte 4
yr: .byte 8
gl: .byte 16
gr: .byte 32