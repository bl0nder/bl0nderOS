#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

#include "../utils/data_types.h"

//Data
//Registers in order of how they will appear in the stack (bottom to top)
typedef struct {    
    
    u32_T ds;
    
    //Registers pushed by pusha
    u32_T edi; //<- esp
    u32_T esi;
    u32_T ebp;  
    u32_T esp;
    u32_T ebx;
    u32_T edx;
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
    u32_T ss;
} registers_T;

//Public functions
void handler(registers_T registers);
#endif