#!/usr/bin/env python

def encrypt(plaintext):
    ciphertext = ""
    for c in plaintext:
        ciphertext += chr((ord(c) - ord('a') + 13) % 26 + ord('a'))
    return ciphertext

def decrypt(ciphertext):
    plaintext = ""
    for c in ciphertext:
        plaintext += chr((ord(c) - ord('a') - 13 + 26) % 26 + ord('a'))
    return plaintext

if __name__ == "__main__":
    print encrypt(raw_input("> "))
