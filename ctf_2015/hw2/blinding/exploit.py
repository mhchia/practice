import sympy

from pwn import *

r = remote('csie.ctf.tw', 10119)

n = 29483112906907846550407371381907804051925957834404110624325531950200215274674279351500117069061279396866776918114198748748643519779529947303729199772247349
e = 65537
c = "0x1c9d992fd1c6c9f26b24fb127e3e1ac343eadb0dad36c27747111ad07238bf9bc76d16737f8f7fc6752df563027fc6614a8c803de38bbe6aefca0e7f3ec739ba4"
c = int(c, 16)

inverse_of_2 = int(sympy.invert(2, n))

c_prime = pow(pow(2, e, n) * c, 1, n)

r.send(str(c_prime) + '\n')

c_prime_power_d = int(pow(int(r.recvline()[:-1]), 1, n))

m = int(pow(c_prime_power_d * inverse_of_2, 1, n))

stripped_message = str(hex(m))[2:].decode('hex')

print stripped_message
