addi x28, x0, 1		#Armazena 1 em x28
addi x27, x0, 13	#Armazena a quebra de linha em x27
addi x26, x0, 48	#Armazena zero em ASCII em x26
addi x25, x0, 10    #Armazena 10 em x25
addi x19, x0, 100   #Armazena 100 em x19
addi x18, x0, 1000  #Armazena 1000 em x18
lw x17, x    		#Armazena 10000 em x27
addi x24, x0, 248   #Armazena posicao de value em x24

read:
	lb x10, 1025(x0)		#Ler input do teclado (um caracter)
	beq x10, x0, read		#Se nao tiver nada no buffer, tenta ler de novo
	sb x10, 1024(x0)		#Printa o input
	beq x10, x27, printNum	#Se for uma quebra de linha, encerra
	sub x10, x10, x26 		#Subtrai 48 para converter de char para int (tabela ASCII)
	
	add x9, x10, x0 		#x9 armazenara o resultado de cada fatorial
	beq x10, x28, end 		#Caso seja 1, pula pro fim
	
	add x15, x0, x10 		#x15 armazena o valor que esta sendo multiplicado a cada iteracao
	sub x13, x10, x28 		#x13 armazena quantos num da fatorial ja foram multiplicados
	sub x11, x10, x28 		#x11 armazena quantas vezes ja somou dentro da multiplicacao

	mult:
		beq x11, x28, end	#Verifica se ja chegou em 1 (fim da fatorial)
		add x9, x9, x15 	#Soma a x9 o valor que esta sendo multiplicado 
		sub x11, x11, x28 	#Dec x11 (contador multiplicacao)
		beq x11, x28, dec	#Verifica se ja chegou em 1 (fim da multiplicacao)
	jal x1, mult

	dec:
		add x15, x0, x9 	#Armazena em x15 o proximo valor que sera multiplicado
		sub x13, x13, x28 	#Dec x13 (contador fatorial)
		add x11, x0, x13 	#Valor pelo qual sera multplicado
		beq x13, x28, end 	#Fim da fatorial (x13 = 1)
	jal x1, mult

end:
	add x5, x5, x9 			#Armazena o resultado total	
jal x0, read

printNum: 
	add x22, x5, x0
	add x21, x24, x0            #Contara o num de algorismo
	nextNum:
        add x20, x0, x0	        #Zera x20
    div10000:
    		blt x22, x17, div1000     #Verifica se o num ja eh menor que 10000
        sub x22, x22, x17             #Subtrai 10000 do num
        addi x20, x20, 1000           #Adiciona um ao resultado da divisao
    		bge x22, x17, div10000    #Verifica se o resto ja eh menor que 10000 ou se ainda pode ser dividido
    div1000:
    		blt x22, x18, div100 	   #Verifica se o num ja eh menor que 1000
        sub x22, x22, x18              #Subtrai 1000 do num
        addi x20, x20, 100             #Adiciona um ao resultado da divisao
    		bge x22, x18, div1000      #Verifica se o resto ja eh menor que 1000 ou se ainda pode ser dividido
    div100:
    		blt x22, x19, div10         #Verifica se o num ja eh menor que 100
        sub x22, x22, x19               #Subtrai 100 do num
        addi x20, x20, 10               #Adiciona um ao resultado da divisao
    		bge x22, x19, div100        #Verifica se o resto ja eh menor que 100 ou se ainda pode ser dividido
    div10:
    		blt x22, x25, continueDiv  #Verifica se o num ja eh menor que 10
        sub x22, x22, x25              #Subtrai 10 do num
        addi x20, x20, 1               #Adiciona um ao resultado da divisao
    		bge x22, x25, div10        #Verifica se o resto ja eh menor que 10 ou se ainda pode ser dividido
    continueDiv:
        add x22, x22, x26              #Adiciona 48 para converter de int para char (tabela ASCII)
        sb x22, 0(x24)                 #Armazena esse valor na memoria
        addi x24, x24, 1               #Incrementa o contador de caracteres lidos (avança um endereco na memoria)
        add x22, x20, x0               #Armazena o resultado para ser o proximo num dividido
    		bne x20, x0, nextNum       #Se o resultado da divisao for diferente de 0, repete para o proximo algorismo
    printing:
        addi x24, x24, -1              #Decrementa o num de algorismo ja printados
        lb x10, 0(x24)                 #Armazena em x10 o valor a ser printado
        sb x10, 1024(x0)               #Printa o valor de x10
	    bne x21, x24, printing         #Verifica se ainda tem algorismo para ser printado
		add x10, x0, x27	           #Quebra de linha em x10	
    		sb x10, 1024(x0)	       #Printar quebra de linha
endPrintNum: jalr x0, 0(x18)           #Retorna para onde a funcao foi chamada 
halt 

value: .string "5555"	#Variavel para armazenar a resposta
x: .word 10000			