;Bootloader program
;Parameters:
;   NONE
;TODO:
;   Check & Enable A20 (even though Qemu already does it mp)
;   Load kernel

;16-bit real mode
[bits 16]
[org 0x7c00]

real_mode:
    ;Storing boot drive
    mov [BOOT_DRIVE], dl

    ;setting stack
    mov bp, 0x9000
    mov sp, bp

    ;printing string in 16-bit real mode
    mov bx, MSG_REAL
    call print_str

    ;Load kernel
    mov bx, KERNEL_OFFSET
    mov dl, [BOOT_DRIVE]
    mov dh, 15 ;Load 15 sectors after boot sector 
    call read_disk

    switch:
        call switch_to_pm
        jmp $

;Imports - 16 bit
%include "utils/print_str.asm"
%include "utils/print_hex.asm"
%include "utils/read_disk.asm"
%include "switch_to_32bit_pm.asm"

;32-bit protected mode
[bits 32]
prot_mode:
    mov ebx, MSG_PROT
    call print_str_pm

    ;Go to address where kernel code is stored and start executing
    call KERNEL_OFFSET

    jmp $

;Imports - 32 bit
%include "utils/print_str_pm.asm"
%include "global_descriptor_table.asm"

;Data
MSG_REAL: db "16-bit real mode", 0xd, 0xa, 0
MSG_PROT: db "32-bit protected mode", 0
MSG_KERNEL_LOAD: db "Loading kernel...", 0xd, 0xa, 0
BOOT_DRIVE: db 0
KERNEL_OFFSET equ 0x1000 ;Address at which kernel will be loaded

;padding & magic number
times 510-($-$$) db 0
dw 0xaa55

; times 256 dw 0xface
; times 512 db 0x12