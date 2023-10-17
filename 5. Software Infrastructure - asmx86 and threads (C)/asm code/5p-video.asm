org 0x7c00            ; seleciona modo de video e muda cor da tela para vermelho
jmp main
data:

main:
xor ax, ax
mov ds, ax
mov es, ax
mov ah, 0xe

call _clear  ;  nesta função setamos o boot para modo de video

mov ah,0xb   ; 1º parametro para modo de video
mov bh, 0    ; 2º parametro para modo de video
mov bl, 4    ; cor da tela. podemos escolher entre 1 e 15
int 10h

jmp $

_clear:
        mov ah, 0       ; primeiro parametro para chamar modo de video
        mov al, 10h     ; segundo parametro para chamar modo de video
        int 10h
        ret

jmp $

times 510-($-$$) db 0
dw 0xaa55

