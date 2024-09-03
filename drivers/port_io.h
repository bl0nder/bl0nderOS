#ifndef PORT_IO_H 
#define PORT_IO_H

unsigned char port_byte_in(unsigned short int port);
void port_byte_out(unsigned short int port, unsigned char byte_out);
unsigned short int port_word_in(unsigned short int port);
void port_word_out(unsigned short int port, unsigned short int word_out);

#endif