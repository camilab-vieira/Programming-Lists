org 0x7c00            ; esse programa printa um pixel na tela
jmp main
data:

main:
xor ax, ax
mov ds, ax
mov es, ax

call _clear      ; setamos modo de video

mov ah, 00h
mov al, 08h
int 10h

mov dx,10        ; dx e cx controlam a posição do pixel
mov cx,10

mov al, 4         ; em al guardamos a cor do pixel

call _print_pixel
call _fim

_putchar:
	mov ah, 0x0e
	int 10h
	ret

_print_pixel:      	  			; printa um pixel na posição coluna = dx , linha = cx
        mov ah, 0ch  ; numero da interrupção
        mov bh, 0    ; parametro da interrupçao
        int 10h      ; chamamos a interrupção
        ret
_clear:
        mov ah, 0
        mov al, 10h
        int 10h
        ret
        
_fim:
	jmp $

times 510-($-$$) db 0
dw 0xaa55

