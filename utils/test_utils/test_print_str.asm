[bits 16] ;16-bit real mode while booting
[org 0x7c00] ;Convenient mem offsetting

mov bx, STRING
call print_str
mov bx, STRING2
call print_str
jmp $ ;Loop indefinitely to prevent BIOS from accessing random mem address after fn returns

%include "../print_str.asm"

;Data
STRING: db "Hello World!", 0x0a, 0
STRING2: db 0x0d, "This is another string", 0

;Padding & Magic number
times 510-($-$$) db 0
dw 0xaa55