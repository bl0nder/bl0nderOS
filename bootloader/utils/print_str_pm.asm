;Function to print a string in 32-bit protected mode
;Parameters:
;   ebx -> Starting address of string to be printed

[bits 32]

print_str_pm:
    pusha
    mov eax, VIDEO_MEMORY
    
    print_char_pm:
        mov dl, [ebx] ;Char stored as first byte of dx
        mov dh, CHAR_ATTR ;Char attributes to be printed 

        cmp dl, 0
        je exit_print_pm ;Exit if null char encountered
        
        mov [eax], dx ;Store char in video mem to be printed

        add eax, 2  ;Inc eax by 2 to skip next 2 bytes for char just printed
        inc ebx ;Inc ebx by 1 to access next char in string

        jmp print_char_pm ;Loop back

    exit_print_pm: 
        popa
        ret

;Data
VIDEO_MEMORY equ 0xb8000
CHAR_ATTR equ 0x0f 