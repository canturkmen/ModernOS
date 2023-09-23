#ifndef KERNEL_H
#define KERNEL_H

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

#define MODERNOS_MAX_PATH 108
     
#define ERROR(value) (void*)value
#define ERROR_I(value) (int)value
#define ISERR(value) ((int)value) < 0

void kernel_registers();
void kernel_page();
void kernel_main();
void print(const char* str);
void panic(const char* message);

#endif 