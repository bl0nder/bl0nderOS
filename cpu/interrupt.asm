[extern handler]

common_handler:
    ;Push all registers
    pusha 

    ;Push data segment descriptor
    mov ax, ds
    push eax
    
    ;Copy kernel data segment descriptor to all other descriptorsa
    mov ax, 0x10
    mov ds, ax
    mov es, ax 
    mov fs, ax 
    mov gs, ax
    
    ;Call interrupt handler 
    call handler 

    ;Pop registers & assign previous data segment descriptor to all descriptors
    pop eax
    mov ds, ax
    mov es, ax 
    mov fs, ax 
    mov gs, ax 

    ;Return execution to whatever function was originally running
    popa 
    add esp, 8  ;Clean up 2 bytes stored on stack for interrupt number & error code
    sti 
    iret

global handler0
global handler1
global handler2
global handler3
global handler4
global handler5
global handler6
global handler7
global handler8
global handler9
global handler10
global handler11
global handler12
global handler13
global handler14
global handler15
global handler16
global handler17
global handler18
global handler19
global handler20
global handler21
global handler22
global handler23
global handler24
global handler25
global handler26
global handler27
global handler28
global handler29
global handler30
global handler31

handler0:
    cli 
    push byte 0 ;Error code
    push byte 0 ;Interrupt num
    jmp common_handler

handler1:
    cli 
    push byte 0 ;Error code
    push byte 1 ;Interrupt num
    jmp common_handler

handler2:
    cli 
    push byte 0 ;Error code
    push byte 2 ;Interrupt num
    jmp common_handler

handler3:
    cli 
    push byte 0 ;Error code
    push byte 3 ;Interrupt num
    jmp common_handler

handler4:
    cli 
    push byte 0 ;Error code
    push byte 4 ;Interrupt num
    jmp common_handler

handler5:
    cli 
    push byte 0 ;Error code
    push byte 5 ;Interrupt num
    jmp common_handler

handler6:
    cli 
    push byte 0 ;Error code
    push byte 6 ;Interrupt num
    jmp common_handler

handler7:
    cli 
    push byte 0 ;Error code
    push byte 7 ;Interrupt num
    jmp common_handler

handler8:
    cli 
    push byte 8 ;Interrupt num
    jmp common_handler

handler9:
    cli
    push byte 0 ;Error code
    push byte 9 ;Interrupt num
    jmp common_handler

handler10:
    cli 
    push byte 10 ;Interrupt num
    jmp common_handler

handler11:
    cli 
    push byte 11 ;Interrupt num
    jmp common_handler

handler12:
    cli 
    push byte 12 ;Interrupt num
    jmp common_handler

handler13:
    cli 
    push byte 13 ;Interrupt num
    jmp common_handler

handler14:
    cli 
    push byte 14 ;Interrupt num
    jmp common_handler

handler15:
    cli 
    push byte 0 ;Error code
    push byte 15 ;Interrupt num
    jmp common_handler

handler16:
    cli 
    push byte 0 ;Error code
    push byte 16 ;Interrupt num
    jmp common_handler

handler17:
    cli 
    push byte 17 ;Interrupt num
    jmp common_handler

handler18:
    cli 
    push byte 0 ;Error code
    push byte 18 ;Interrupt num
    jmp common_handler

handler19:
    cli 
    push byte 0 ;Error code
    push byte 19 ;Interrupt num
    jmp common_handler

handler20:
    cli 
    push byte 0 ;Error code
    push byte 20 ;Interrupt num
    jmp common_handler

handler21:
    cli 
    push byte 0 ;Error code
    push byte 21 ;Interrupt num
    jmp common_handler

handler22:
    cli 
    push byte 0 ;Error code
    push byte 22 ;Interrupt num
    jmp common_handler

handler23:
    cli 
    push byte 0 ;Error code
    push byte 23 ;Interrupt num
    jmp common_handler

handler24:
    cli 
    push byte 0 ;Error code
    push byte 24 ;Interrupt num
    jmp common_handler

handler25:
    cli
    push byte 0 ;Error code
    push byte 25 ;Interrupt num
    jmp common_handler

handler26:
    cli 
    push byte 0 ;Error code
    push byte 26 ;Interrupt num
    jmp common_handler

handler27:
    cli 
    push byte 0 ;Error code
    push byte 27 ;Interrupt num
    jmp common_handler

handler28:
    cli 
    push byte 0 ;Error code
    push byte 28 ;Interrupt num
    jmp common_handler

handler29:
    cli 
    push byte 0 ;Error code
    push byte 29 ;Interrupt num
    jmp common_handler

handler30:
    cli 
    push byte 0 ;Error code
    push byte 30 ;Interrupt num
    jmp common_handler

handler31:
    cli 
    push byte 0 ;Error code
    push byte 31 ;Interrupt num
    jmp common_handler