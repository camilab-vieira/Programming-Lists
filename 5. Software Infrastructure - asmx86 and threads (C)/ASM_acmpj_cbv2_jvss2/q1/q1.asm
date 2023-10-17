org 0x7c00                  ;Endereço inicial (Onde se espera que o programa fique na memória)
jmp main

data:

    codRGB db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 7, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 7, 8, 8, 8, 8, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 8, 8, 8, 8, 9, 1, 8, 8, 8, 8, 1, 8, 0, 0, 0, 0, 0, 0, 8, 8, 9, 9, 9, 9, 8, 9, 9, 8, 0, 0, 0, 0, 0, 0, 8, 1, 9, 9, 15, 15, 9, 9, 9, 8, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 1, 0, 0, 0, 0, 0, 0, 8, 9, 15, 15, 15, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9, 15, 15, 9, 9, 9, 8, 0, 0, 0, 0, 8, 8, 8, 8, 1, 9, 9, 9, 9, 8, 8, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 8, 1, 9, 9, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

printPixel:                ;Printar um pixel
    mov ah, 0ch            ;Chamada para escrever um pixel na coordenada [dx, cx]
    mov bh, 0              ;Numero da pagina
    int 10h                ;Interrupcao de video
    ret                    ;Retornar
            
printImage:                ;Printar a imagem
	xor ax, ax             ;Limpando registradores
    xor cx, cx
	mov bx, ax
    mov dx, ax
    mov si, codRGB         ;Ponteiro SI apontando para o inicio do codigo RGB
	
	.loop1:
        lodsb               ;Carrega em AL o conteudo apontado por SI e inc SI
        call printPixel
        inc cx              ;CX = x, deslocar um para o lado
        cmp cx, 16          ;Limite lateral (se passar dos 16 pixels por linha, ir para a proxima linha)
        je .proxlinha       ;Ir para proxima linha
        jmp .loop1          ;Carregar proximo pixel
        
        .proxlinha:
            mov cx, 0       ;Voltar para o inicio da linha (CX = x)
            inc dx          ;Ir para a linha de baixo (DX = y)
            cmp dx, 16      ;Limite vertical (verifica quando os 256 pixels foram postos)
            je .done        ;Encerra 
            jmp .loop1      ;Carregar o proximo pixel

        .done: 
            ret             ;Retornar

main:

    xor ax, ax              ;Limpando registradores
    mov ds, ax
    mov es, ax

    mov ah, 0              ;Numero de chamada (modo video)
    mov al, 12h            ;Modo de video (modo VGA)
    int 10h                ;Interrupcao de video

    call printImage

times 510-($-$$) db 0       ;512 bytes
dw 0xaa55                   ;Assinatura