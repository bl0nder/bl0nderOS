[bits 16]
[org 0x7c00]
test_read_disk:

    ;Store boot drive in BOOT_DRIVE
    mov [BOOT_DRIVE], dl

    ;String to indicate start of routine
    mov bx, START_MSG
    call print_str

    ;Setting up stack
    mov bp, 0x8000
    mov sp, bp

    ;Read disk
    mov dh, 2
    mov dl, [BOOT_DRIVE]
    mov bx, 0x9000
    call read_disk
    
    ;Print values read from disk
    mov dx, [0x9000]
    call print_hex

    mov dx, [0x9000 + 512]
    call print_hex

    mov bx, END_MSG
    call print_str

    jmp $

;Import
%include "../print_str.asm"
%include "../print_hex.asm"
%include "../read_disk.asm"

;Data
START_MSG: db "Trying to read disk...", 0x0a, 0x0d, 0
END_MSG: db 0x0a, 0x0d, "Disk read successfully!", 0
BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xaa55

times 256 dw 0xface
times 256 dw 0x1234