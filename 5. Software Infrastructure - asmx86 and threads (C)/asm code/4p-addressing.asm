org 0x7c00            ; “Oi”
jmp main
data:

letra times 3 db 48     ;aqui letra armazena 3 bytes. cada um com o valor 48

main:
xor ax, ax
mov ds, ax
mov es, ax
mov ah, 0xe    

mov al, byte[letra]     ; aqui movemos para al o primeiro byte de letra
mov ah, 0xe    
int 10h

mov byte[letra+1], 49    ; já aqui movemos para o segundo byte de letra o numero 49
mov al, byte[letra+1]    ; devolvemos de novo para al para printa-lo
mov ah, 0xe    
int 10h

times 510-($-$$) db 0
dw 0xaa55

