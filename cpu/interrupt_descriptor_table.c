#include "interrupt_descriptor_table.h"
#include "../utils/data_types.h"
#include "../drivers/screen.h"

//Given an interrupt number and handler, initialize an entry in IDT
void idt_entry_init(u32_T interrupt_num, u32_T interrupt_handler) {
    idt[interrupt_num].offset_1 = (interrupt_handler & 0x0000ffff);
    idt[interrupt_num].segment_selector = 0x08;
    idt[interrupt_num].reserved = 0x00;
    idt[interrupt_num].type_attributes = 0x8e;
    idt[interrupt_num].offset_2 = (interrupt_handler >> 16);
}

//Initialize IDTR and load IDT
void idt_init() {

    //Set params in IDT register
    idtr.size = (u16_T) NUM_IDT_ENTRIES * sizeof(idt_entry_T) - 1;
    idtr.offset = (u32_T) &idt;

    //Load IDT & Enable interrupts (sti)
    __asm__ __volatile__("lidt (%0)" : : "m" (idtr));
}

//Fill IDT with entries
void fill_idt() {
    idt_entry_init(0, (u32_T) handler_0);
    idt_entry_init(1, (u32_T) handler_1);
    idt_entry_init(2, (u32_T) handler_2);
    idt_entry_init(3, (u32_T) handler_3);
    idt_entry_init(4, (u32_T) handler_4);
    idt_entry_init(5, (u32_T) handler_5);
    idt_entry_init(6, (u32_T) handler_6);
    idt_entry_init(7, (u32_T) handler_7);
    idt_entry_init(8, (u32_T) handler_8);
    idt_entry_init(9, (u32_T) handler_9);
    idt_entry_init(10, (u32_T) handler_10);
    idt_entry_init(11, (u32_T) handler_11);
    idt_entry_init(12, (u32_T) handler_12);
    idt_entry_init(13, (u32_T) handler_13);
    idt_entry_init(14, (u32_T) handler_14);
    idt_entry_init(15, (u32_T) handler_15);
    idt_entry_init(16, (u32_T) handler_16);
    idt_entry_init(17, (u32_T) handler_17);
    idt_entry_init(18, (u32_T) handler_18);
    idt_entry_init(19, (u32_T) handler_19);
    idt_entry_init(20, (u32_T) handler_20);
    idt_entry_init(21, (u32_T) handler_21);
    idt_entry_init(22, (u32_T) handler_22);
    idt_entry_init(23, (u32_T) handler_23);
    idt_entry_init(24, (u32_T) handler_24);
    idt_entry_init(25, (u32_T) handler_25);
    idt_entry_init(26, (u32_T) handler_26);
    idt_entry_init(27, (u32_T) handler_27);
    idt_entry_init(28, (u32_T) handler_28);
    idt_entry_init(29, (u32_T) handler_29);
    idt_entry_init(30, (u32_T) handler_30);
    idt_entry_init(31, (u32_T) handler_31);

    idt_init();
}