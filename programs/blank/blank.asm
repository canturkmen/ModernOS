[BITS 32]

section .asm

global _start

_start:

label:
    push 30
    push 20
    mov eax, 0 ; Command 0 SUM
    int 0x80
    add esp, 8

    jmp $
