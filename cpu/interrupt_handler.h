#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

#include "../utils/data_types.h"

//Data
//Registers in order of how they will appear in the stack (bottom to top)
typedef struct {
    //Data segment descriptor
    u32_T ds;   //<- esp
    
    //Registers pushed by pusha
    u32_T edi;
    u32_T esi;
    u32_T ebp;
    u32_T esp;
    u32_T ebx;
    u32_T ecx;
    u32_T eax;

    //Interrupt number & error code
    u32_T interrupt_num;
    u32_T error_code;

    //Registers pushed when interrupt is called
    u32_T eip;
    u32_T cs;
    u32_T eflags;
    u32_T useresp;
    u32_T ss;   //<- ebp
} registers_T;

//extern functions (defined in assembly)
extern void handler0();
extern void handler1();
extern void handler2();
extern void handler3();
extern void handler4();
extern void handler5();
extern void handler6();
extern void handler7();
extern void handler8();
extern void handler9();
extern void handler10();
extern void handler11();
extern void handler12();
extern void handler13();
extern void handler14();
extern void handler15();
extern void handler16();
extern void handler17();
extern void handler18();
extern void handler19();
extern void handler20();
extern void handler21();
extern void handler22();
extern void handler23();
extern void handler24();
extern void handler25();
extern void handler26();
extern void handler27();
extern void handler28();
extern void handler29();
extern void handler30();
extern void handler31();

//Public functions
void handler(registers_T registers);
void fill_idt();
#endif