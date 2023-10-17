addi x14, x0, 13    #Verificar se eh uma quebra de linha
addi x16, x0, 48    #x16 armazena o valor 0 em char
addi x17, x0, 10

readStr:
    lb x10, 1025(x0)    #Ler caracter
    beq x10, x14, print #Verifica se eh o fim da str
    addi x12, x0, 116    #Endereco da str que sera lida

    checkVowel:
        lb x11, 0(x12)  #Carrega o caracter
        beq x10, x11, inc   #Verifica se eh uma vogal, se sim, incrementa x14
        addi x12, x12, 1    #Incrementa o endereco
    bne x11, x16, checkVowel   #Verifica se eh o fim da str
    
jal x18, readStr    #Ler prox caracter

inc: 
    addi x13, x13, 1   #Incrementa x14
    jal x18, readStr    #Ler prox caracter

print: 
	add x15, x0, x0 #Conta o num de algorismo
    nextNum:
        add x16, x0, x0
    div:
        blt x13, x17, continue  #Verifica se o num ja eh menor que 10
        sub x13, x13, x17   #Subtrai 10 do num
        addi x16, x16, 1    #Adiciona um ao resultado da divisao
    bge x13, x17, div   #Verifica se o resto ja eh menor que 10 ou se ainda pode ser dividido
    continue:
        addi x13, x13, 48   #Adiciona 48 para converter de int para char (tabela ASCII)
        sb x13, 128(x15)    #Armazena esse valor na memoria
        addi x15, x15, 1    #Incrementa o contador de caracteres lidos (avanÃƒÂ§a um endereco na memoria)
        add x13, x16, x0    #Armazena o resultado em x13 para ser o proximo num dividido
    bne x16, x0, nextNum  #Se o resultado da divisao for diferente de 0, repete para o proximo algorismo
    printing:
        addi x15, x15, -1   #Decrementa o num de algorismo ja printados
        lb x10, 128(x15)    #Armazena em x10 o valor a ser printado
        sb x10, 1024(x0)    #Printa o valor de x10
bne x15, x0, printing  #Verifica se ainda tem algorismo para ser printado
sb x14, 1024(x0)
x: .string "aAeEiIoOuU0"    #Declara a variavel str
num: .string "5" #Declara a variavel num