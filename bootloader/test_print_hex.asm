[bits 16]
[org 0x7c00]

;Move some hex num to dx and call print_hex
mov dx, [HEX]
call print_hex

jmp $ ;Indefinitely jump

;Import
%include "print_str.asm"
%include "print_hex.asm"

;Data
HEX: dw 0x1fe2
SPACE: db " ", 0

;Padding + Magic number
times 510-($-$$) db 0
dw 0xaa55