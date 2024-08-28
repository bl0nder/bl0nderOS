;Bootloader program
;Parameters:
;   NONE

;16-bit real mode
[bits 16]
[org 0x7c00]

real_mode:

    ;setting stack
    mov bp, 0x9000
    mov sp, bp

    ;printing string in 16-bit real mode
    mov bx, MSG_REAL
    call print_str

switch:
    call switch_to_pm
    jmp $

;Imports - 16 bit
%include "print_str.asm"
%include "switch_to_32bit_pm.asm"

;32-bit protected mode
[bits 32]
prot_mode:
    mov ebx, MSG_PROT
    call print_str_pm
    jmp $

;Imports - 32 bit
%include "print_str_pm.asm"
%include "gdt.asm"

;Data
MSG_REAL: db "16-bit real mode", 0
MSG_PROT: db "32-bit protected mode", 0

;padding & magic number
times 510-($-$$) db 0
dw 0xaa55