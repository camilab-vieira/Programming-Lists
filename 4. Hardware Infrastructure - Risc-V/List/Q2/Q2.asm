addi x12, x0, 13    #Verificar se eh uma quebra de linha
addi x17, x0, 10    #x17 armazena o valor 10
addi x29, x0, 65    #Definindo valores para comparacao
addi x30, x0, 24    #Definindo valores para comparacao
    
main:
    addi x11, x0, 236   #Endereco da str que sera printada
    addi x13, x11, 3    #Num de caracteres que serao printados
    jal x18, print      #Printar
    jal x18, read       #Ler variavel a
    sb x14, 220(x0)     #Armazena esse valor na memoria
        
    addi x11, x0, 239   #Endereco da str que sera printada
    addi x13, x11, 3    #Num de caracteres que serao printados 
    jal x18, print      #Printar
	add x14, x0, x0     #Zerar x14 para realizar a leitura
    jal x18, read       #Ler variavel b
    sb x14, 224(x0)     #Armazena esse valor na memoria
    
    addi x11, x0, 242   #Endereco da str que sera printada
    addi x13, x11, 3    #Num de caracteres que serao printados
    jal x18, print      #Printar
	add x14, x0, x0     #Zerar x14 para realizar a leitura
    jal x18, read       #Ler variavel c
    sb x14, 228(x0)     #Armazena esse valor na memoria

    lw x5, a    #Lendo variavel a
    lw x6, b    #Lendo variavel b
    lw x7, c    #Lendo variavel c
    lw x28, x   #Lendo variavel x (inicializa como 0)

    blt x5, x0, end      #Verifica condicao do if (se for menor que 0, nao entra no if, pula para o fim)
    bge x6, x29, end     #Verifica condicao do if (se for maior ou igual a 65, nao entra no if, pula para o fim)
    blt x7, x30, end     #Verifica condicao do if (se for menor que 23, nao entra no if, pula para o fim)
    	addi x28, x0, 1  #Se entrou no if, x recebe o valor 1
    jal x18, end

read:
    lb x10, 1025(x0)        #Ler input do teclado (um caracter)
    beq x10, x0, read       #Se nao tiver nada no buffer, tenta ler de novo
    sb x10, 1024(x0)        #Printa o input
    beq x10, x12, endRead   #Se for uma quebra de linha, encerra
    addi x13, x10, -48      #Subtrai 48 para converter de char para int (tabela ASCII)
    add x15, x0, x14        #Armazena em x15 o valor anterior de x14 
    addi x16, x0, 1         #Inicializa x16 como 1 (ira contar a qntd de vezes ja somou o num)
    mult:
        add x14, x14, x15   #Adicionar o valor inicial de x14 ao novo x14
        addi x16, x16, 1    #Repetir o processo 10x para ter o resultado de uma multiplicacao por 10
    bne x16, x17, mult      #Verifica se ja foi adicionado 10x
    add x14, x14, x13       #Apos multiplicar o num por 10, adiciona o novo caracter (sera a unidade do novo num)
    jal x11, read           #Repete o precesso para o proximo caracter
endRead: jalr x0, 0(x18)    #Volta para onde chamou a funcao

print:
    lb x10, 0(x11)      #Carregar caracter em x10
    sb x10, 1024(x0)    #Printa o valor de x10
    addi x11, x11, 1    #Incrementar contador de caracter lido
    bne x11, x13, print #Continua printando se nao tiver acabado
jalr x0, 0(x18)         #Retornar para onde foi chamada a funcao

end: 
    addi x11, x0, 245   #Endereco da str que sera printada   
    addi x13, x11, 3    #Num de caracteres que serao printados
    jal x18, print      #Printar
    addi x28, x28, 48   #Passando de int para char (como so tem um algorismo, basta somar 48, devido a tabela ASCII)
    sb x28, 1024(x0)    #Printando valor de x
	sb x12, 1024(x0)
jal x0, main

a: .word 0  #Declara a variavel a
b: .word 0  #Declara a variavel b
c: .word 0  #Declara a variavel c
x: .word 0  #Declara a variavel x
str: .string "a: b: c: x: " #Declara a variavel str
