%macro interrupt_handler_no_error 1
    global handler_%1
    handler_%1:
        push byte 0    ;Dummy error code
        push byte %1   ;Interrupt number
        jmp common_handler
%endmacro

%macro interrupt_handler_error 1
    global handler_%1
    handler_%1:
        push byte %1   ;Interrupt number (error code already pushed by interrupt)
        jmp common_handler
%endmacro

[extern handler]
common_handler:
    pusha   ;Push all registers to stack

    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax 
    mov es, ax
    mov gs, ax
    mov fs, ax

    call handler 

    pop eax 
    mov ds, ax 
    mov es, ax
    mov gs, ax
    mov fs, ax

    popa
    add esp, 8 ;Reset esp -> error code (4 bytes) + interrupt number (4 bytes) = 8 bytes
    sti
    iret

interrupt_handler_no_error 0
interrupt_handler_no_error 1
interrupt_handler_no_error 2
interrupt_handler_no_error 3
interrupt_handler_no_error 4
interrupt_handler_no_error 5
interrupt_handler_no_error 6
interrupt_handler_no_error 7
interrupt_handler_error 8
interrupt_handler_no_error 9
interrupt_handler_error 10
interrupt_handler_error 11
interrupt_handler_error 12
interrupt_handler_error 13
interrupt_handler_error 14
interrupt_handler_no_error 15
interrupt_handler_no_error 16
interrupt_handler_no_error 17
interrupt_handler_no_error 18
interrupt_handler_no_error 19
interrupt_handler_no_error 20
interrupt_handler_no_error 21
interrupt_handler_no_error 22
interrupt_handler_no_error 23
interrupt_handler_no_error 24
interrupt_handler_no_error 25
interrupt_handler_no_error 26
interrupt_handler_no_error 27
interrupt_handler_no_error 28
interrupt_handler_no_error 29
interrupt_handler_no_error 30
interrupt_handler_no_error 31