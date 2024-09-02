unsigned char port_byte_in(unsigned short int port) {
    unsigned char byte;
    __asm__("in %%dx, %%al" : "=a" (byte) : "d" (port));
    return byte;
}

void port_byte_out(unsigned short int port, unsigned char byte_out) {
    __asm__("out %%al, %%dx" : : "d" (port), "a" (byte_out));
}

unsigned short int port_word_in(unsigned short int port) {
    unsigned short int word;
    __asm__("in %%dx, %%ax" : "=a" (word) : "d" (port));
    return word;
}

void port_word_out(unsigned short int port, unsigned short int word_out) {
    __asm__("out %%ax, %%dx" : : "d" (port), "a" (word_out));
}