#include "interrupt_handler.h"
#include "interrupt_descriptor_table.h"
#include "../utils/data_types.h"
#include "../drivers/screen.h"

//Data
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

void handler_0() {
    // __asm__ __volatile__ ("cli");
    print_k(exception_messages[0], WHITE, RED);
}
void handler_1() {
    // __asm__ __volatile__ ("cli");
    print_k(exception_messages[1], WHITE, RED);
}
void handler_2() {
    // __asm__ __volatile__ ("cli");
    print_k(exception_messages[2], WHITE, RED);
}
void handler_3() {
    // __asm__ __volatile__ ("cli");
    print_k(exception_messages[3], WHITE, RED);
}
void handler_4() {
    print_k(exception_messages[4], WHITE, RED);
}
void handler_5() {
    print_k(exception_messages[5], WHITE, RED);
}
void handler_6() {
    print_k(exception_messages[6], WHITE, RED);
}
void handler_7() {
    print_k(exception_messages[7], WHITE, RED);
}
void handler_8() {
    print_k(exception_messages[8], WHITE, RED);
}
void handler_9() {
    print_k(exception_messages[9], WHITE, RED);
}
void handler_10() {
    print_k(exception_messages[10], WHITE, RED);
}
void handler_11() {
    print_k(exception_messages[11], WHITE, RED);
}
void handler_12() {
    print_k(exception_messages[12], WHITE, RED);
}
void handler_13() {
    print_k(exception_messages[13], WHITE, RED);
}
void handler_14() {
    print_k(exception_messages[14], WHITE, RED);
}
void handler_15() {
    print_k(exception_messages[15], WHITE, RED);
}
void handler_16() {
    print_k(exception_messages[16], WHITE, RED);
}
void handler_17() {
    print_k(exception_messages[17], WHITE, RED);
}
void handler_18() {
    print_k(exception_messages[18], WHITE, RED);
}
void handler_19() {
    print_k(exception_messages[19], WHITE, RED);
}
void handler_20() {
    print_k(exception_messages[20], WHITE, RED);
}
void handler_21() {
    print_k(exception_messages[21], WHITE, RED);
}
void handler_22() {
    print_k(exception_messages[22], WHITE, RED);
}
void handler_23() {
    print_k(exception_messages[23], WHITE, RED);
}
void handler_24() {
    print_k(exception_messages[24], WHITE, RED);
}
void handler_25() {
    print_k(exception_messages[25], WHITE, RED);
}
void handler_26() {
    print_k(exception_messages[26], WHITE, RED);
}
void handler_27() {
    print_k(exception_messages[27], WHITE, RED);
}
void handler_28() {
    print_k(exception_messages[28], WHITE, RED);
}
void handler_29() {
    print_k(exception_messages[29], WHITE, RED);
}
void handler_30() {
    print_k(exception_messages[30], WHITE, RED);
}
void handler_31() {
    print_k(exception_messages[31], WHITE, RED);
}
void assign_interrupt_handlers() {
    print_k((char*) "Hello there!", WHITE, RED);

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