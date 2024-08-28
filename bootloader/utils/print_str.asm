;Function to print a string to screen using BIOS routines
;Parameters:
;   bx -> starting ADDRESS of string to be printed (string MUST terminate with NULL char)
;   NOTE: bx is NOT the string itself
print_str:
    pusha
    mov ah, 0x0e ;Print char in teletype mode

    print_char:
        mov al, [bx] ;al -> char to be printed 
        int 0x10 ;BIOS interrupt for video services

        inc bx ;inc bx to address of next character in string
        
        cmp byte[bx], 0 ;Check if current char is NULL char
        je exit_print ;If yes, exit loop
        jmp print_char ;Else, loop again

    exit_print:
        popa
        ret
