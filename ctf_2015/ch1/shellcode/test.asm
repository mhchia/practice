global _start
section .text
_start:
    push    0x00006873
    mov     bl, 1
    mov     ecx, esp
    mov     dl, 3
    mov     al, 4
    int     0x80

    mov     ebx, 10
    mov     eax, 1
    int     0x80
