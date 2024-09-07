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