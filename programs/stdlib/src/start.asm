[BITS 32]

section .asm

global _start
extern c_start
extern modernos_exit

_start:
    call c_start
    call modernos_exit
    ret