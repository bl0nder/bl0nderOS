;Function to switch from 16-bit real mode to 32-bit protected mode
;Parameters:
;   NONE

;16-bit real mode
[bits 16]

switch_to_pm:
    cli ;Disable interrupts
    lgdt [gdt_descriptor] ;Load GDT using GDT descriptor

    ;Set bit 0 in CR0 control register
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    
    jmp GDT_CODE_SEGMENT:protected_mode

;32-bit protected mode
[bits 32]
protected_mode:

    ;Init segment regisers to data segment
    mov eax, GDT_DATA_SEGMENT 
    mov ds, eax
    mov es, eax
    mov ss, eax
    mov fs, eax
    mov gs, eax

    ;Init stack pointers to address just above free space
    mov ebp, 0x90000
    mov esp, ebp

    call prot_mode