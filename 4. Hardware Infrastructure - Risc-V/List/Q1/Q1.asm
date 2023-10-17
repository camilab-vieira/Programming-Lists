lw x5, a	#Lendo variavel a 
lw x6, b	#Lendo variavel b
lw x7, m	#Lendo variavel m

add x7, x0, x5	#Armazenando valor de a em m

bne x5, x6, else	#Verifica se a e b sao iguais (nao sendo, pula para 'else')
	sub x7, x6, x5	#Armazena em m a subtracao de b por a
else: sub x7, x5, x6	#Armazena em m a subtracao de a por b

halt	#Encerra a execucao

a: .word 5	#Declara a variavel a
b: .word 9	#Declara a variavel b
m: .word 0	#Declara a variavel m 
