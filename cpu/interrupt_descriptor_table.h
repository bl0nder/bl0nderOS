#ifndef IDT_H
#define IDT_H

#include "../utils/data_types.h"

#define NUM_IDT_ENTRIES 256
#define KERNEL_CS 0x08

//Public functions
void idt_entry_init(u32_T interrupt_num, u32_T interrupt_handler);
void idt_init();
void fill_idt();

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

//extern functions (defined in assembly)
extern void handler_0();
extern void handler_1();
extern void handler_2();
extern void handler_3();
extern void handler_4();
extern void handler_5();
extern void handler_6();
extern void handler_7();
extern void handler_8();
extern void handler_9();
extern void handler_10();
extern void handler_11();
extern void handler_12();
extern void handler_13();
extern void handler_14();
extern void handler_15();
extern void handler_16();
extern void handler_17();
extern void handler_18();
extern void handler_19();
extern void handler_20();
extern void handler_21();
extern void handler_22();
extern void handler_23();
extern void handler_24();
extern void handler_25();
extern void handler_26();
extern void handler_27();
extern void handler_28();
extern void handler_29();
extern void handler_30();
extern void handler_31();
#endif