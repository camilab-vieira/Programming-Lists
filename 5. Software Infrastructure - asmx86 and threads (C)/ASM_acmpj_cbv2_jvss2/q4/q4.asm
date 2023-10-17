org 0x7c00                 ;Endereço inicial (Onde se espera que o programa fique na memória)
jmp main
 
data:

    input times 50 db 0
    position times 50 db 0
    
putchar:                   ;Printar caracter                    
	mov ah, 0x0e           ;Teletype output (printar)
    mov bh, 0              ;Numero da pagina
    mov bl, 0xf            ;Cor (branco)
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

stoi:                      ;Transformando de string para inteiro
    xor ax, ax             ;Limpando registradores
    xor cx, cx
    .loop:
        push ax            ;Bota AX na pilha 
        lodsb              ;Carrega em AL o conteudo apontado por SI e inc SI
        mov cl, al         ;Passa AL para CL
        pop ax             ;Retira da pilha
        cmp cl, 0          ;Verifica o fim da string
        je .done           ;Se sim, encerra
        sub cl, 48         ;Pela tabela ASCII, o codigo do numero tem 48 a mais
        mov bx, 10         ;Passa o valor 10 para BX
        mul bx             ;Multiplica AX por BX (para transformar em dezena, centena, milhar...)
        add ax, cx         ;Soma AX e CX (CX representa as unidades)
        jmp .loop
    .done:
        ret                ;Retornar

main:

    xor ax, ax             ;Limpando os registradores
    mov ds, ax
    mov es, ax

    mov ah, 0              ;Numero de chamada (modo video)
    mov al, 12h            ;Modo de video (modo VGA)
    int 10h                ;Interrupcao de video

    mov di, input          ;Ponteiro aponta para onde a str sera armazenada
    call gets              ;Ler mensagem
    mov di, position       ;Ponteiro aponta para onde a str sera armazenada
    call gets              ;Ler numero da posicao desejada
     
    mov si, position       ;Ponteiro aponta para onde a str esta armazenada
    call stoi

    mov si, input          ;Ponteiro aponta para onde a str esta armazenada
    add si, ax             ;SI recebe o numero correspondente a posição esperada
    dec si                 ;A contagem em ASM começa do 0 e na questão do 1, entao é necessario decrementar
    
    mov ah, 0              ;Numero de chamada (modo video)
    mov al, 12h            ;Modo de video (modo VGA)
    int 10h                ;Interrupcao de video

    mov al, [si]           ;Carrega em AL o caracter que deve ser printado
    
    call putchar           ;Printar o caracter correspondente a posição desejada

times 510-($-$$) db 0      ;512 bytes
dw 0xaa55                  ;Assinatura