#include "../drivers/screen.h"
#include "../cpu/interrupt_handler.h"

void main() {
    clear_screen_k();

    assign_interrupt_handlers();
    // test();
    __asm__ __volatile__("int $0");
    print_k((char*) "\ntesting", WHITE, GREEN);
    __asm__ __volatile__("int $0");
}