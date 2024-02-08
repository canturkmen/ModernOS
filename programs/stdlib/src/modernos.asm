[BITS 32]   

section .asm

global print:function
global modernos_getkey:function
global modernos_putchar:function
global modernos_malloc:function
global modernos_free:function
global modernos_process_load_start:function
global modernos_process_get_arguments:function
global modernos_system:function
global modernos_exit:function

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

; int modernos_getkey()
modernos_getkey:
    push ebp
    mov ebp, esp
    mov eax, 2 ; Command getkey
    int 0x80
    pop ebp
    ret

; void modernos_putchar(char c)
modernos_putchar:
    push ebp
    mov ebp, esp
    mov eax, 3 ; Command putchar
    push dword[ebp + 8] ; Variable c
    int 0x80
    add esp, 4
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

; void modernos_process_load_start(const char* filename)
modernos_process_load_start:
    push ebp
    mov ebp, esp
    mov eax, 6 ; Command 6 process load start (Starts a process)
    push dword[ebp + 8] ; Variable "filename"
    int 0x80
    add esp, 4
    pop ebp
    ret

; int modernos_system(struct command_argument* arguments)
modernos_system:
    push ebp
    mov ebp, esp
    mov eax, 7 ; Command 7 process_system (runs a system command based on the arguments)
    push dword[ebp + 8] ; Variable "arguments"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void modernos_process_get_arguments(struct process_arguments* arguments)
modernos_process_get_arguments:
    push ebp
    mov ebp, esp
    mov eax, 8 ; Command 8
    push dword[ebp + 8] ; Variable "arguments"
    int 0x80
    add esp, 4
    pop ebp
    ret

; void modernos_exit()
modernos_exit:
    push ebp
    mov ebp, esp
    mov eax, 9 ; Command 9
    int 0x80
    add esp, 4
    pop ebp
    ret