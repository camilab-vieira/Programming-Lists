data:
	addi x27, x0, 13	#Armazena a quebra de linha em x27
	addi x26, x0, 48	#Armazena zero em ASCII em x26
	addi x25, x0, 10    #Armazena 10 em x25
	jal x0, main	    #Pula para main

	str1: .string "AEIOU0"
	str2: .string "DGT0"
	str3: .string "BCMNP0"
	str4: .string "FHVWY0"
	str5: .string "KRS0"
	str6: .string "JLX0"
	str7: .string "QZ0"
	player1: .string "Jogador 1: 0"
	player2: .string "Jogador 2: 0"
	points1: .string "Pontuacao 1: 0"
	points2: .string "Pontuacao 2: 0"
	wins1: .string "Jogador 1 vence 0"
	wins2: .string "Jogador 2 vence 0"
	draw: .string "Empate0"
	num1: .word 5
	num2: .word 7
	value: .string "555"

main:
	addi x24, x0, 56   #Endereco da str que sera printada (Jogador 1)
	jal x18, print     #Printar 
	jal x18, readStr   #Ler a string
	sb x22, 156(x0)    #Armazena a pontuacao na memoria

	addi x24, x0, 82   #Endereco da str que sera printada (Pontuacao 1)
    jal x18, print     #Printar
	addi x24, x0, 164  #Endereco da str que sera printada (Valor da pontuacao 1)
	jal x18, printNum  #Printar valor

	addi x24, x0, 69   #Endereco da str que sera printada (Pontuacao 1)
    jal x18, print     #Printar 
	jal x18, readStr   #Ler a string
	sb x22, 160(x0)    #Armazena a pontuacao na memoria
    
	addi x24, x0, 97   #Endereco da str que sera printada (Pontuacao 1)
    jal x18, print     #Printar
	addi x24, x0, 164  #Endereco da str que sera printada (Valor da pontuacao 1)
	jal x18, printNum  #Printar valor

	lw x23, num1	            #Carrega a pontuacao 1 em x23
    lw x24, num2	            #Carrega a pontuacao 2 em x24
    beq x23, x24, tie	        #Verifica se foi empate		
    blt x23, x24, player2Wins	#Verifica se o jogador 2 venceu
	
player1Wins:
    addi x24, x0, 112  #Endereco da str que sera printada
    jal x18, print     #Printar
    sb x27, 1024(x0)
	halt
	
player2Wins:
    addi x24, x0, 130  #Endereco da str que sera printada
    jal x18, print     #Printar
    sb x27, 1024(x0)
	halt

tie:
    addi x24, x0, 148  #Endereco da str que sera printada
    jal x18, print     #Printar
    sb x27, 1024(x0)
	halt
 

print:   
	lb x10, 0(x24)          #Carregar caracter em x10
    beq x10, x26, endPrint  #Continua printando se nao tiver acabado
    sb x10, 1024(x0)        #Printa o valor de x10
    addi x24, x24, 1        #Incrementar contador de caracter lido
    jal x10, print
endPrint: jalr x0, 0(x18)   #Retornar para onde foi chamada a funcao

readStr:
    lb x10, 1025(x0)            #Ler input do teclado (um caracter)
    beq x10, x0, readStr        #Se nao tiver nada no buffer, tenta ler de novo
    sb x10, 1024(x0)            #Printa o input
    beq x10, x27, endReadStr    #Se for uma quebra de linha, encerra
	
	addi x24, x0, 16            #Endereco da str1 que sera lida 
    addi x23, x0, 1             #Valor que sera inc 
    jal x19, iterate
    
    addi x24, x0, 23            #Endereco da str2 que sera lida 
    addi x23, x0, 2             #Valor que sera inc 
    jal x19, iterate
    
    addi x24, x0, 28            #Endereco da str3 que sera lida 
    addi x23, x0, 3             #Valor que sera inc 
    jal x19, iterate
    
    addi x24, x0, 35            #Endereco da str4 que sera lida 
    addi x23, x0, 4             #Valor que sera inc 
    jal x19, iterate 
    
    addi x24, x0, 42            #Endereco da str5 que sera lida 
    addi x23, x0, 5             #Valor que sera inc 
    jal x19, iterate
    
    addi x24, x0, 47            #Endereco da str6 que sera lida 
    addi x23, x0, 8             #Valor que sera inc 
    jal x19, iterate
    
    addi x24, x0, 52            #Endereco da str7 que sera lida 
    addi x23, x0, 10            #Valor que sera inc 
    jal x19, iterate 
   
	jal x0, readStr             #Ler prox caracter
endReadStr: jalr x0, 0(x18)	    #Retornar para onde foi chamada a funcao

iterate:
    lb x11, 0(x24)              #Carrega o caracter
    addi x24, x24, 1            #Incrementa o endereco
    bne x11, x10, continue      #Verifica se eh um dos caracteres, se sim, incrementa x13
    jal x0, inc 
continue: bne x11, x26, iterate #Verifica se eh o fim da str
jalr x0, 0(x19)	                #Retornar para onde foi chamada a funcao
   
inc: 
    add x22, x22, x23           #Incrementa 
jal x0, readStr                 #Ler prox caracter

printNum:
	add x21, x24, x0            #Contara o num de algorismo
	nextNum:
        add x20, x0, x0	        #Zera x20
    div:
    		blt x22, x25, continueDiv  #Verifica se o num ja eh menor que 10
        sub x22, x22, x25              #Subtrai 10 do num
        addi x20, x20, 1               #Adiciona um ao resultado da divisao
    		bge x22, x25, div          #Verifica se o resto ja eh menor que 10 ou se ainda pode ser dividido
    continueDiv:
        add x22, x22, x26              #Adiciona 48 para converter de int para char (tabela ASCII)
        sb x22, 0(x24)                 #Armazena esse valor na memoria
        addi x24, x24, 1               #Incrementa o contador de caracteres lidos (avanÃ§a um endereco na memoria)
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