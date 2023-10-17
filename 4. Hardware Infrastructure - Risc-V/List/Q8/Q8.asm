init:
    addi x20, x0, 344   #Posicao da str na memoria
    addi x23, x0, 0     #Var auxiliar de contagem
    addi x27, x0, 13    #Quebra de linha
    addi x5, x0, 0      #Resultado 
    addi x6, x0, 48     #Char to int

read:
    lb x10, 1025(x0)       #Ler input do teclado (um caracter)
    beq x10, x0, read      #Se nao tiver nada no buffer, tenta ler de novo
    sb x10, 1024(x0)       #Printa o input
    beq x10, x27, somar    #Se for uma quebra de linha, encerra
	
    add x20, x20, x23   #Add 1 ao offset da string a cada iteração
    addi x23, x0, 1     #Incrementa x23
    sub x10, x10, x6    #Char para inteiro
    beq x10, x0, read   #Caso o bit tenha sido 0, lê o proximo
    lb x21, 0(x20)      #Carrega o conteudo da string em x21
    sub x7, x21, x6     #Char para inteiro (string)
    add x5, x5, x7      #x5 armazena o resultado
    jal x1, read

somar:
    add x10, x0, x5 		 #Adiciona o resultado a x10
    addi x2, x0, 0 			 #Contagem começa do 
    addi x4, x0, 0b100000 	 #Acende o segmento de led g

zero:
    addi x2, x2, 1	        #Add 1 a x2 em cada label.. ou seja, chega todos os caso 0..9
    bge x10, x2, um         #Caso o valor digitado seja maior ou igual a 1, pula
    addi x10, x0, 63        #63 = 00111111, ou seja, segmentos a, b, c, d, e e f acesos
    sb x10, 1029(x0)        #Acende os leds
    sb x0, 1027(x0)         #Nao acende o leg g
    jal x1, init           #Pula pro clear
um: 
    addi x2, x2, 1 
    bge x10, x2, dois 
    addi x10, x0, 6 
    sb x10, 1029(x0) 
    sb x0, 1027(x0) 
    jal x1, init 
dois:
    addi x2, x2, 1
    bge x10, x2, tres
    addi x10, x0, 27
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
tres:
    addi x2, x2, 1
    bge x10, x2, quatro
    addi x10, x0, 15
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
quatro:
    addi x2, x2, 1
    bge x10, x2, cinco
    addi x10, x0, 38
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
cinco:
    addi x2, x2, 1
    bge x10, x2, seis
    addi x10, x0, 45
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
seis:
    addi x2, x2, 1
    bge x10, x2, sete
    addi x10, x0, 61
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
sete:
    addi x2, x2, 1
    bge x10, x2, oito
    addi x10, x0, 7
    sb x10, 1029(x0)
    sb x0, 1027(x0)
    jal x1, init
oito:
    addi x2, x2, 1
    bge x10, x2, nove
    addi x10, x0, 63
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
nove:
    addi x2, x2, 1
    bge x10, x2, clear
    addi x10, x0, 47
    sb x10, 1029(x0)
    sb x4, 1027(x0)
    jal x1, init
clear:
    addi x2, x2, 7
    bge x10, x2, init
    add x10, x0, x0
    sb x10, 1029(x0)
    sb x0, 1027(x0)
    jal x1, init

num: .string "8421" #Mais signicativo primeiro, soma o offset e iniciamos digitando o bit mais significativo