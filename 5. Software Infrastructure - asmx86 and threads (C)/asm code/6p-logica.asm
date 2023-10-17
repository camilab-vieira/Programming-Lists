org 0x7c00            ; esse programa compara se os registradores al e bl tem o mesmo valor
jmp main	      ; se sim ele printa S
data:                 ; se não ele printa N



main:
xor ax, ax
mov ds, ax
mov es, ax


mov al, 11h   
mov bl, 10h

cmp al, bl              ; comparamos al com bl      
jne nao_eh_igual        ; caso sejam diferentes pulamos para nao_eh_igual
je eh_igual             ; caso iguais pulamos para eh_igual

eh_igual:
	mov al,'s'
	call _putchar
	call _fim


nao_eh_igual:
	mov al,'n'
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

