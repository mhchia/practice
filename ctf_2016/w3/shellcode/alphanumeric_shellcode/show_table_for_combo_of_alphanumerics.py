from pwn import *
xx = {}
alphanumerics = string.letters + string.digits
for i in xrange(256):
    for x in alphanumerics:
        for y in alphanumerics:
            if i == ord(x) ^ ord(y):
                xx[i] = (x, y)
for x in xx:
    print x, xx[x]
