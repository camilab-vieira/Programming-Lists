org 0x7c00            ; aqui comparamos se as strig
jmp main
data:

str1 db "hello1", 0
str2 db "hello", 0

main:

xor ax, ax
mov ds, ax
mov es, ax

mov di, str1  ; movemos str1 para di
mov si, str2  ; movemos str2 para si

call _strcmp  ; chamamos a funçao

mov al, 'n'   ; movemos n primeiramente para al

jne _fim      ; jne checa os registradores de comparação e se for diferentes ele pula para fim sem mover 's' para al
mov al, 's'   ; caso sejam iguais 's' é carregado para al ao inves de 'n'

_fim:
	call _putchar
	jmp $

_putchar:
	mov ah, 0x0e
	int 10h
	ret

_strcmp:                             ; compara duas strings armazanadas em si e di
	.loop1:
		lodsb
		cmp byte[di], 0
		jne .continue
		cmp al, 0
		jne .done
		stc
		jmp .done
		
		.continue:
			cmp al, byte[di]
    			jne .done
			clc
    			inc di
    			jmp .loop1

		.done:
			ret

times 510-($-$$) db 0
dw 0xaa55

