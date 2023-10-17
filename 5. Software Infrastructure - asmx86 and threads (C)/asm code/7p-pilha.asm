org 0x7c00            ; pilha é usada para salvar valores
jmp main
data:

main:
xor ax, ax
mov ds, ax
mov es, ax

mov al, 'a'    ; movemos 'a' para al
push ax        ; salvamos na pilha

mov al, 'b'    ; sobreescrevamos al
call _putchar 

pop ax          ; resgatamos o valor 'a' da pilha e salvamos de volta no registrador
call _putchar   

call _fim

_putchar:
	mov ah, 0x0e
	int 10h
	ret

_fim:
	jmp $

times 510-($-$$) db 0
dw 0xaa55

