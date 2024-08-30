gdt_start:
    
    NULL_entry:
        dd 0x0 ;Double word = 4 bytes
        dd 0x0 ;Another 4 bytes = 8 bytes in total

    code:
        dw 0xffff ;Limit (bits 0-15)
        dw 0x0000 ;Base (bits 16-31)
        db 0x00   ;Base (bits 32-39)
        db 0x9a   ;Access Byte  (bits 40-47)
        db 11001111b ;Limit + Flags (bits 48-55)
        db 0x00   ;Base (bits 56-63)
    
    data:
        dw 0xffff ;Limit (bits 0-15)
        dw 0x0000 ;Base (bits 16-31)
        db 0x00   ;Base (bits 32-39)
        db 0x92   ;Access Byte  (bits 40-47)
        db 11001111b ;Limit + Flags (bits 48-55)
        db 0x00   ;Base (bits 56-63)
    
    gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1 ;Size of GDT
    dd gdt_start ;Address of GDT

;Constants
GDT_CODE_SEGMENT equ code - gdt_start
GDT_DATA_SEGMENT equ data - gdt_start