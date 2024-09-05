#ifndef IDT_H
#define IDT_H

#include "../utils/data_types.h"

#define NUM_IDT_ENTRIES 256
#define KERNEL_CS 0x08

//Public functions
void idt_entry_init(u32_T interrupt_num, u32_T interrupt_handler);
void idt_init();

//Struct for entry in IDT
typedef struct { 
    u16_T offset_1;             // Offset bits 0-15
    u16_T segment_selector;     
    u8_T reserved;              // Set to 0
    u8_T type_attributes;       // Gate type (4 bits), DPL (2 bits), P (1 bit) and 1 unset bit
    u16_T offset_2;             // Offset bits 16-31
} __attribute__((packed)) idt_entry_T;

//Struct for IDT Register
typedef struct {
    u16_T size;
    u32_T offset;
} __attribute__((packed)) idtr_T;

//Create IDT & IDT Register and align to 16-byte boundary
static idt_entry_T idt[NUM_IDT_ENTRIES] __attribute__((aligned(0x10)));   
static idtr_T idtr;
#endif