#ifndef IO_H
#define IO_H

unsigned char insb(unsigned short port); // Read one byte from the given port
unsigned short insw(unsigned short port); // Reado one word from the given port

void outb(unsigned short port, unsigned char val); // Write one byte to the given port
void outw(unsigned short port, unsigned short val); // Write one word to the given port

#endif
