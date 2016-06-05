#!/usr/bin/env python

import signal
import sys
import os
import time
import base64
import random
from Crypto.Cipher import AES
from Crypto.Hash import SHA256

sys.dont_write_bytecode = True
import myData

BS = 16
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS)
unpad = lambda s: s[:-ord(s[-1])]


class MyAES:
    def __init__(self, key):
        self.key = key
        self.iv = 'This is an IVIVI'

    def encrypt(self, raw):
        message = pad(raw)
        aes = AES.new(self.key, AES.MODE_CBC, self.iv)
        return base64.b64encode(aes.encrypt(message))

    def decrypt(self, enc):
        cipher = base64.b64decode(enc)
        aes = AES.new(self.key, AES.MODE_CBC, self.iv)
        return unpad(aes.decrypt(cipher))


def alarm(time):
    def handler(signum, frame):
        print 'QQ'
        exit()
    signal.signal(signal.SIGALRM, handler)
    signal.alarm(time)


def checkIntegrity(message, digest):
    sha256 = SHA256.new()
    sha256.update(message)
    if base64.b64encode(sha256.digest()) != digest:
        print 'Integrity error!'
        exit()


def findPW(ID):
    password = ''
    for each in myData.userAndPw:
        if each.split(':')[0] == ID:
            password = each.split(':')[1]
    if password == '':
        print 'ID not found!'
        exit()
    return password


def first():
    try:
        recv = raw_input('You should send your ID and a random string to me: ')
        ID, N, digest = recv.split('||')
    except:
        print 'Format error!'
        exit()
    checkIntegrity(ID + '||' + N, digest)
    return ID, N


def second(ID, Nc, password, Ns):
    # authenticate the server
    aes = MyAES(password)
    cipher = aes.encrypt(ID + '||' + Nc)
    message = Ns + '||' + cipher
    sha256 = SHA256.new()
    sha256.update(message)
    print message + '||' + base64.b64encode(sha256.digest())


def third(ID, password, Ns):
    try:
        recv = raw_input('You should encrypt your ID and my random string by your password,' +
            'then send it back to me for authentication: ')
        cipher, digest = recv.split('||')
    except:
        print 'Format error!'
        exit()
    checkIntegrity(cipher, digest)

    aes = MyAES(password)
    try:
        plaintext = aes.decrypt(cipher).split('||')
    except:
        print 'what?'
        exit()
    if plaintext[0] == ID and plaintext[1] == Ns:
        return True
    return False


if __name__ == '__main__':
    alarm(60)
    sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)
    sys.stdin = os.fdopen(sys.stdin.fileno(), 'r', 0)

    print 'Let me sleep first . . .'
#    time.sleep(5)
    print 'I\'m back!'

    ID, Nc = first()
    password = findPW(ID)
    Ns = str(random.randint(100000000, 999999999))
    second(ID, Nc, password, Ns)
    authen = third(ID, password, Ns)
    if authen:
        print 'Welcome! ' + ID
        if ID == 'admin':
            print myData.FLAG

