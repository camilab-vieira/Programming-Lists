org 0x7c00                  ;Endereço inicial (Onde se espera que o programa fique na memória)
jmp main

data:

    input times 50 db 0
    amarelo db "amarelo", 0
    azul db "azul", 0
    verde db "verde", 0
    vermelho db "vermelho", 0
    inexistente db "NAO EXISTE", 0
    capsAmarelo db "AMARELO", 0
    capsAzul db "AZUL", 0
    capsVerde db "VERDE", 0
    capsVermelho db "VERMELHO", 0

putchar:                   ;Printar caracter                    
	mov ah, 0x0e           ;Teletype output (printar)
    mov bh, 0              ;Numero da pagina
    int 10h                ;Interrupcao de video
	ret                    ;Retornar
getchar:                   ;Ler caracter do teclado
	mov ah, 0x00           ;Chamada para ler tecla pressionada
	int 16h                ;Interrupcao de teclado
	ret                    ;Retornar
delchar:                   ;Deleta caracter
	mov al, 0x08           ;Chama um backspace (volta o cursor uma posicao)
    call putchar
	mov al, ''             ;Chama uma str vazia (substitui o ultimo caracter, ou seja, apaga)
	call putchar
	mov al, 0x08           ;Chama um backspace (volta o cursor uma posicao, a str vazia avanca o cursor)
	call putchar
	ret                    ;Retornar
endl:                      ;Quebra de linha
	mov al, 0x0a           ;Chama uma nova linha (contudo o cursor não vai para o inicio da proxima linha)
	call putchar
	mov al, 0x0d           ;Chama o carriage return (leva o cursor para o inicio da linha)
	call putchar
	ret                    ;Retornar

gets:                      ;Ler uma string
    xor ax, ax             ;Limpando registradores
    xor cx, cx
    .loop:
        call getchar
        cmp al, 0x08       ;Verifica se foi um backspace
        je .backspace      ;Se sim, apaga um caracter
        cmp al, 0x0d       ;Verifica se foi um carriage return
        je .done           ;Se sim, encerra a leitura
        cmp cl, 50         ;Verifica o tamanho da string
        je .loop
        stosb              ;O valor de AL é armazenado no endereço apontado por DI e DI é incrementado
        inc cl             ;Armazena a quantidade de caracteres lidos
        call putchar
        jmp .loop          ;Ler o proximo caracter

    .backspace:
        cmp cl, 0          ;Verifica se há algum caracter para ser apagado
        je .loop           ;Ler o proximo caracter
        dec di             ;Volta DI
        dec cl             ;Volta CL
        mov byte[di], 0    ;Apaga o que estava armazenado, apontado por DI
        call delchar	   ;Apaga na tela
        jmp .loop          ;Ler o proximo caracter

    .done:
        mov al, 0          ;Adiciona o 0 no fim, sinalizar o fim da string
        stosb              ;O valor de AL é armazenado no endereço apontado por DI e DI é incrementado
        inc cl             ;Armazena a quantidade de caracteres lidos
        call endl
        ret                ;Retornar

printString:               ;Printando uma String 
    xor ax, ax             ;Limpando registradores
	.loop:
        lodsb              ;Carrega em AL o conteudo apontado por SI e inc SI
        cmp al, 0          ;Verifica o fim da string
        je .done           ;Se sim, encerra 
        call putchar
        jmp .loop          ;Printa o proximo caracter
    .done:
		call endl
        ret                ;Retornar

strcmp:                    ;Compara duas strings 
    .loop:
        lodsb              ;Carrega em AL o conteudo apontado por SI e inc SI
        cmp byte[di], 0    ;Verifica se está no fim da string apontada por DI
		jne .continue      ;Se não, continua
		cmp al, 0          ;Verifica se está no fim da string apontada por SI
		jne .done          ;Se não, encerra (str DI acabou e a str SI continuou, nao sao iguais)
		stc                ;Marca a flag do comparador como 1 (ambas str acabaram e sao iguais)
		jmp .done          ;Encerra
		
    .continue:
        cmp al, byte[di]   ;Verifica se os caracteres sao iguais
        jne .done          ;Se nao forem, encerra
        clc                ;Limpa a flag do comparador
                           ;So sera marcada como 1 quando ambas str acabarem, tendo permanecido iguais ao longo do processo
        inc di             ;Passa para o proximo caracter para ser comparado
        jmp .loop

    .done:
        ret                ;Retornar

corAmarelo:                ;Printar texto na cor amarela
    mov si, capsAmarelo    ;Ponteiro SI apontando para o inicio da str capsAmarelo     
    mov bl, 14             ;Cor (amarelo)
    call printString
    jmp fim                ;Encerra

corAzul:                   ;Printar texto na cor azul
    mov si, capsAzul       ;Ponteiro SI apontando para o inicio da str capsAzul
    mov bl, 1              ;Cor (azul)
    call printString
    jmp fim                ;Encerra

corVerde:                  ;Printar texto na cor verde
    mov si, capsVerde      ;Ponteiro SI apontando para o inicio da str capsVerde
    mov bl, 2              ;Cor (verde)
    call printString
    jmp fim                ;Encerra

corVermelho:               ;Printar texto na cor vermelha
    mov si, capsVermelho   ;Ponteiro SI apontando para o inicio da str capsVermelho
    mov bl, 4              ;Cor (vermelho)
    call printString
    jmp fim                ;Encerra

main:

    xor ax, ax             ;Limpando os registradores
    mov ds, ax
    mov es, ax

    mov ah, 0              ;Numero de chamada (modo video)
    mov al, 12h            ;Modo de video (modo VGA)
    int 10h                ;Interrupcao de video

    mov bl, 15             ;Cor (branco)
    mov di, input          ;Ponteiro aponta para onde a str sera armazenada
    call gets

    mov ah, 0              ;Numero de chamada (modo video)
    mov al, 12h            ;Modo de video (modo VGA)
    int 10h                ;Interrupcao de video

    mov di, amarelo        ;Ponteiro DI apontando para o inicio da str amarelo
    mov si, input          ;Ponteiro aponta para onde a str esta armazenada
    call strcmp  
    je corAmarelo          ;Se a flag de comparação estiver marcada como 1 (iguais), vai printar de acordo com a cor

    mov di, azul           ;Ponteiro DI apontando para o inicio da str azul
    mov si, input          ;Ponteiro aponta para onde a str esta armazenada
    call strcmp  
    je corAzul             ;Se a flag de comparação estiver marcada como 1 (iguais), vai printar de acordo com a cor

    mov di, verde          ;Ponteiro DI apontando para o inicio da str verde
    mov si, input          ;Ponteiro aponta para onde a str esta armazenada
    call strcmp  
    je corVerde            ;Se a flag de comparação estiver marcada como 1 (iguais), vai printar de acordo com a cor

    mov di, vermelho       ;Ponteiro DI apontando para o inicio da str vermelho
    mov si, input          ;Ponteiro aponta para onde a str esta armazenada
    call strcmp  
    je corVermelho         ;Se a flag de comparação estiver marcada como 1 (iguais), vai printar de acordo com a cor

    mov si, inexistente    ;Ponteiro SI apontando para o inicio da str inexistente
    mov bl, 5              ;Cor (magenta)
    call printString

    fim:                   ;Encerra o programa
        jmp $

times 510-($-$$) db 0       ;512 bytes
dw 0xaa55                   ;Assinatura