[BITS 32]   

section .asm

global print:function
global getkey:function
global modernos_malloc:function
global modernos_free:function

; void print(const char* message)
print:
    push ebp
    mov ebp, esp
    push dword[ebp + 8]
    mov eax, 1 ; Command print
    int 0x80
    add esp, 4  
    pop ebp
    ret

getkey:
    push ebp
    mov ebp, esp
    mov eax, 2 ; Command getkey
    int 0x80
    pop ebp
    ret

; void* modernos_malloc(size_t size)
modernos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 4 ; Command malloc (Allocates memory for the process)
    push dword[ebp + 8] ; Variable "size"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void modernos_malloc(void* ptr)
modernos_free:
    push ebp
    mov ebp, esp
    mov eax, 5 ; Command 5 free (Fress the allocated memory for this process)
    push dword[ebp + 8]
    int 0x80
    add esp, 4 
    pop ebp
    ret

