#include "interrupt_handler.h"
#include "interrupt_descriptor_table.h"
#include "../utils/data_types.h"
#include "../drivers/screen.h"

void fill_idt() {
    idt_entry_init(0, (u32_T) handler0);
    idt_entry_init(1, (u32_T) handler1);
    idt_entry_init(2, (u32_T) handler2);
    idt_entry_init(3, (u32_T) handler3);
    idt_entry_init(4, (u32_T) handler4);
    idt_entry_init(5, (u32_T) handler5);
    idt_entry_init(6, (u32_T) handler6);
    idt_entry_init(7, (u32_T) handler7);
    idt_entry_init(8, (u32_T) handler8);
    idt_entry_init(9, (u32_T) handler9);
    idt_entry_init(10, (u32_T) handler10);
    idt_entry_init(11, (u32_T) handler11);
    idt_entry_init(12, (u32_T) handler12);
    idt_entry_init(13, (u32_T) handler13);
    idt_entry_init(14, (u32_T) handler14);
    idt_entry_init(15, (u32_T) handler15);
    idt_entry_init(16, (u32_T) handler16);
    idt_entry_init(17, (u32_T) handler17);
    idt_entry_init(18, (u32_T) handler18);
    idt_entry_init(19, (u32_T) handler19);
    idt_entry_init(20, (u32_T) handler20);
    idt_entry_init(21, (u32_T) handler21);
    idt_entry_init(22, (u32_T) handler22);
    idt_entry_init(23, (u32_T) handler23);
    idt_entry_init(24, (u32_T) handler24);
    idt_entry_init(25, (u32_T) handler25);
    idt_entry_init(26, (u32_T) handler26);
    idt_entry_init(27, (u32_T) handler27);
    idt_entry_init(28, (u32_T) handler28);
    idt_entry_init(29, (u32_T) handler29);
    idt_entry_init(30, (u32_T) handler30);
    idt_entry_init(31, (u32_T) handler31);

    idt_init();
}

void handler(registers_T registers) {

    char *exception_messages[] = {
        "Division By Zero",
        "Debug",
        "Non Maskable Interrupt",
        "Breakpoint",
        "Into Detected Overflow",
        "Out of Bounds",
        "Invalid Opcode",
        "No Coprocessor",

        "Double Fault",
        "Coprocessor Segment Overrun",
        "Bad TSS",
        "Segment Not Present",
        "Stack Fault",
        "General Protection Fault",
        "Page Fault",
        "Unknown Interrupt",

        "Coprocessor Fault",
        "Alignment Check",
        "Machine Check",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",

        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved"
    };

    print_k(exception_messages[registers.interrupt_num], WHITE, RED);
}