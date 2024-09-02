;Function to read 'n' sectors from disk
;Parameters:
;   dh -> Number of sectors to read
;   dl -> Drive to read
;   es:bx -> Buffer address pointer (address where disk contents are to be stored)

[bits 16]

read_disk:
    pusha
    push dx

    mov ah, 0x02 ;Read floppy/disk
    mov al, dh ;Num sectors to read

    ;Setting CHS address 
    mov ch, 0x00 ;Cylinder
    mov dh, 0x00 ;Head
    mov cl, 0x02 ;Sector

    int 0x13 ;BIOS interrupt for disk I/O operations

    jc disk_read_error ;Show error if something screws up while doing the operation

    ;Pop original value of dx so we can compare the prev and curr values of al
    pop dx  
    cmp dh, al
    jne disk_read_error ;Error if #sectors read != #sectors EXPECTED to be read

    jmp exit_disk_read

    disk_read_error:
        mov bx, DISK_READ_ERROR
        call print_str

        mov bx, ERROR_CODE
        call print_str

        mov dh, 0x00
        mov dl, ah
        call print_hex 

        mov bx, NEWLINE
        call print_str

        mov bx, ACTUAL_SECTORS_READ
        call print_str

        mov dh, 0x00 
        mov dl, al
        call print_hex

        jmp $ ;Infinite loop in case of error

    exit_disk_read: 
        popa 
        ret

;Import
; %include "print_hex.asm"

;Data
DISK_READ_ERROR: db "There was an error reading the disk.", 0xd, 0xa, 0
ERROR_CODE: db "Error code: ", 0
ACTUAL_SECTORS_READ: db "Actual sectors read: ", 0
NEWLINE: db 0xd, 0xa, 0