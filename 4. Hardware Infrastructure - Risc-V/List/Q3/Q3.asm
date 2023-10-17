lw x10, x       #Lendo variavel x
lw x11, y       #Lendo variavel y
lw x12, mask1   #Lendo variavel mask1
lw x13, mask2   #Lendo variavel mask2

and x14, x10, x12       #Extrai os bits 15 a 8 do registrador x10
and x11, x11, x13       #Valor do registrador x11 com os bots 31 a 24 zerados
slli x14, x14, 16       #Posicionar o valor extraido
or x11, x11, x14        #Substitui em x11 o valor extraido de x10, sem alterar esses registradores
halt                    #Encerra o programa

x: .word 0xfff00ff0    #Declara a variavel x
y: .word 0xf0f000ff    #Declara a variavel y
mask1: .word 0xff00    #Declara mask1
mask2: .word 0xffffff  #Declara mask2
