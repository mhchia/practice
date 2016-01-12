from pwn import *
import sympy


p = "acceptyourfailureandmoveon"



def encrypt(p):

    alphabet = "abcdefghijklmnopqrstuvwxyz"
    m = 3
    c = ""
    for i in p:
        if i in alphabet:
            index = alphabet.find(i)
            encrypted_char = alphabet[pow(index * m, 1, 26)]
            c += encrypted_char
        else:
            c += i
    return c

def decrypt(c):

    alphabet = "abcdefghijklmnopqrstuvwxyz"
    m = 3
    p = ""
    m_inverse = int(sympy.invert(m, 26))
    print m_inverse
    for i in c:
        if i in alphabet:
            index = alphabet.find(i)
            decrypted_char = alphabet[pow(m_inverse * index, 1, 26)]
            p += decrypted_char
        else:
            p += i
    return p


print encrypt(p)
