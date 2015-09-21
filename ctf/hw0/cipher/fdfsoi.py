import base64
import subprocess

from pwn import *


alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
conn = remote('csie.ctf.tw', 10112)

def get_cipher():
    string = conn.recvrepeat(0.5)
    string = string[string.find('Ciphertext') + len('Ciphertext: '):]
    string = string[:string.find('\n')]
    return string

# round 1

s = get_cipher()
conn.send(s+'\n')

# round 2
s = get_cipher()
r = ""
for char in s:
    r += alpha[(alpha.find(char) - 7 + len(alpha)) % len(alpha)]
conn.send(r+'\n')

# round 3
s = get_cipher()
r = ""
for i in range(len(s)):
    r += alpha[(alpha.find(s[i]) - i - 1 + len(alpha)) % len(alpha)]
conn.send(r+'\n')

# round 4
s = get_cipher()
transform = "rlN7utjd0S5qp1EX2nT34eWQhoVHJigwGMmFYzxcvPDkK8CayR6LBZfAsbU9IO"
r = ""
for char in s:
    r += alpha[transform.find(char)]
conn.send(r+'\n')

# round 5
s = get_cipher()
r = ""
for i in xrange(len(s)):
    # i % 5 == 0 -> -26
    # i % 5 == 1 -> -41
    # i % 5 == 2 -> -41
    # i % 5 == 3 -> -37
    # i % 5 == 4 -> -30
    if i % 5 == 0:
        r += alpha[(alpha.find(s[i]) - 26 + len(alpha)) % len(alpha)]
    elif i % 5 == 1 or i % 5 == 2:
        r += alpha[(alpha.find(s[i]) - 41 + len(alpha)) % len(alpha)]
    elif i % 5 == 3:
        r += alpha[(alpha.find(s[i]) - 37 + len(alpha)) % len(alpha)]
    elif i % 5 == 4:
        r += alpha[(alpha.find(s[i]) - 30 + len(alpha)) % len(alpha)]
conn.send(r+'\n')

# round 6
s = get_cipher()
r = ""
for i in xrange(len(s)):
    if i == 0:
        r += s[i]
    else:
        r += alpha[(alpha.find(s[i]) - alpha.find(s[i - 1]) + len(alpha)) % len(alpha)]

conn.send(r+'\n')


# round 7
s = get_cipher()
r = base64.decodestring(s).replace('\n', '')
conn.send(r+'\n')

print conn.recvrepeat(0.5)
conn.send(raw_input('')+'\n')
print conn.recvrepeat(0.5)
