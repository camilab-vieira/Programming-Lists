;Gabarito - Questão 1 - Lista Assembly 2019.2 - Infraestrutura de Software

org 0x7c00
jmp 0x0000:main

;Cores da BIOS
blue equ 1 
red equ 4
yellow equ 14
green equ 10
magenta equ 5
white equ 15
black equ 0

;Dados do programa
data:
    string times 15 db 0
    azul db 'AZUL', 0
    amarelo db 'AMARELO', 0
    verde db 'VERDE', 0
    vermelho db 'VERMELHO', 0
    outro db 'NAO EXISTE', 0

;Printa um char na tela
putchar:
    mov ah, 0x0e
    int 10h
ret

;Lê um char do teclado
getchar:
    mov ah, 0x00
    int 16h
ret

;Deleta um char
delchar:
    mov al, 0x08
    call putchar
    mov al, ' '
    call putchar
    mov al, 0x08
    call putchar
ret

;Quebra de linha
endl:
    mov al, 0x0a
    call putchar
    mov al, 0x0d
    call putchar
ret

;Printa uma string
prints:

    .loop:
        lodsb                   ;Carrega caracter em al              
        cmp al, 0
        je .endloop
        call putchar
        jmp .loop
    .endloop:
ret

;Lê uma string
gets:                           
    xor cx, cx

    .loop1:
        call getchar

        cmp al, 0x08                ;0x08 == Backspace                
        je .backspace

        cmp al, 0x0d                ;0x0d == ENTER
        je .done

        cmp cl, 15                  ;Tamanho maximo da string
        je .loop1
        
        mov dl, al                  ;Copia al para dl, para nao perder o char posteriormente...

        sub al, 32                  ;Torna o char salvo em al maiusculo
        stosb                       ;Salva al na string
        
        inc cl                      ;Incrementa o contador

        mov  bh, 0                  ;
        mov  bl, white              ;Define posição e cor da letra
        mov  al, 02h                ;
        int  10h                    ;

        mov al, dl                  ;Retoma o valor de al para printar

        call putchar
        
        jmp .loop1                  ;Mantem-se o loop

        ;Caso o usuário apague um char
        .backspace:
            cmp cl, 0           
            je .loop1
            dec di
            dec cl
            mov byte[di], 0
            call delchar
        jmp .loop1

    ;Fim do loop == String salva
    .done:
    mov al, 0
    stosb
    call endl
ret

compara_aux:

    .loopi:
        xor ax, ax
        mov bx, ax

        ;Carrega em bx o char em questão da string 'vermelho'
        mov si, dx
        lodsb
        mov bx, ax

        ;Incrementa a posição de dx
        inc dx

        ;Limpa ax
        xor ax, ax

        ;Carrega em ax o char em questão da string lida
        mov si, cx
        lodsb

        ;Incrementa a posição de cx
        inc cx

        ;Comparamos os caracteres
        cmp ax, bx
        jne .diff

        ;Se chegamos ao fim da string
        cmp ax, 0
        je .done

        ;Buscamos o próximo char
        jmp .loopi

        ;Caracteres diferentes, flag = 0 = FASLE
        .diff:
            mov dx, 0
            jmp .end

    ;Caracteres sempre iguais, flag = 1 = TRUE e retornamos
    .done:
        mov dx, 1

    .end:
ret

compara:

    ;Limpa o dx
    xor dx, dx

    ;Compara com a string "amarelo"
    
    ;Salvamos o início da string em cx
    mov si, string
    mov cx, si

    ;Salvamos o início de 'amarelo' em dx
    mov si, amarelo
    mov dx, si

    call compara_aux
    cmp dx, 1
    je .amarelo

    ;Compara com a string "azul"

    ;Salvamos o início da string em cx
    mov si, string
    mov cx, si

    ;Salvamos o início de 'azul' em dx
    mov si, azul
    mov dx, si

    call compara_aux
    cmp dx, 1
    je .azul

    ;Compara com a string "verde"
    
    ;Salvamos o início da string em cx
    mov si, string
    mov cx, si

    ;Salvamos o início de 'verde' em dx
    mov si, verde
    mov dx, si

    call compara_aux
    cmp dx, 1
    je .verde

    ;Compara com a string "vermelho"

    ;Salvamos o início da string em cx
    mov si, string
    mov cx, si

    ;Salvamos o início de 'vermelho' em dx
    mov si, vermelho
    mov dx, si

    call compara_aux
    cmp dx, 1
    je .vermelho

    ;Caso seja uma cor inexistente
    .outro:
        mov si, outro
        mov  dl, 0
        mov  bl, magenta
        jmp .done

    ;Caso a cor tenha sido "amarelo"
    .amarelo:
        mov si, amarelo
        mov  dl, 0
        mov  bl, yellow
        jmp .done

    ;Caso a cor tenha sido "azul"
    .azul:
        mov si, azul
        mov  dl, 0
        mov  bl, blue
        jmp .done
    
    ;Caso a cor tenha sido "verde"
    .verde:
        mov si, verde
        mov  dl, 0
        mov  bl, green
        jmp .done

    ;Caso a cor tenha sido "vermelho"
    .vermelho:
        mov si, vermelho
        mov  dl, 0
        mov  bl, red
        jmp .done

    ;Printa a cor desejada
    .done:
        mov  dh, 0
        mov  bh, 0
        mov  ah, 02h
        int  10h
        call prints

ret

;Printa um pixel na tela
print_pixel:
    
    mov ah, 0Ch
    int 10h
ret

;Desenha em toda janela com a cor em al
clean:

    ;Janela preta
    mov al, black

    push dx
    push cx

    mov dx, 0

    ;Percorre toda a janela printando pixels da cor preta
    .loopLine:

        cmp dx, 200
        je .endLoopLine

        mov cx, 0

        .loopColumn:
        
            cmp cx, 320
            je .endLoopColumn

            call print_pixel
            inc cx
            jmp .loopColumn

        .endLoopColumn:

            inc dx
            jmp .loopLine

    .endLoopLine:

        pop cx
        pop dx
ret

;Inicia modo de vídeo
initVideo:
    
    mov al, 13h
    mov ah, 0
    int 10h
ret

main:
    
    ;Inicia o modo vídeo 
    call initVideo
    
    ;Lê a string
    mov di, string
    call gets

    ;Limpa a tela
    call clean

    ;Compara as strings
    call compara

    jmp $    
    
times 510-($-$$) db 0
dw 0xaa55