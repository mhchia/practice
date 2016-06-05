global _start
section .text
_start:
    push    0x0068732f
    push    0x6e69622f
    mov     ebx, esp
    mov     al, 11
    int     0x80

    mov     ebx, 10
    mov     eax, 1
    int     0x80
