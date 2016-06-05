import base64
import subprocess

from pwn import *


for i in xrange(1, 10000):
    print i,
    conn = remote('ctf2015.hitcon.org', i)
    print conn.recvrepeat(0.1)
