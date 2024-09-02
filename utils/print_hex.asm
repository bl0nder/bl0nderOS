;Function to print a hexadecimal address as a string
;Parameters:
;   dx -> Hex number to be printed
[bits 16]
print_hex:
    pusha

    mov cx, 4 ;Counter to count the number of nibbles that have been converted    
    
    convert_hex:
        mov ax, dx ;Copy dx into ax
        and ax, 0x000f ;Get LSB

        ;If LSB is a digit, add 0x30 to it to get the ASCII code for it
        cmp ax, 0x0009
        jle convert_digit
        add ax, 0x0037 ;Else, add 0x37
        jmp convert_nibble
        
        convert_digit:
            add ax, 0x0030 

        convert_nibble:
            ;Offset address of HEX_STRING according to counter
            mov bx, HEX_TO_STRING+1 
            add bx, cx

            ;Move only LOWER BYTE of ax to proper byte in HEX_TO_STRING
            ;If al is replaced by ax, 2 bytes will be transferred which will be wrong
            mov [bx], al
        
        shr dx, 4 ;SHR dx by 4 bits to get next nibble in next iteration
        
        ;Decrement counter and exit if it reaches 0
        dec cx 
        cmp cx, 0
        je exit_fn
        
        ;Else loop 
        jmp convert_hex

    exit_fn:
        mov bx, HEX_TO_STRING
        call print_str
        popa
        ret

;Data
HEX_TO_STRING: db "0x0000", 0