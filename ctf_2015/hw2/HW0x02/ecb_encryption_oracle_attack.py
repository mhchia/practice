import base64
import string

from pwn import *



def get_cookie(password):

    username = ''
    r = remote('csie.ctf.tw', 10117)
    r.send(username + '\n')
    r.send(password + '\n')
    cookie = r.recvline()[len('username: password: Cookie: '):-1]
    r.close()
    return base64.b64decode(cookie)

def get_min_L():

    username = ''
    password = 'a' * 1
    # ? = \xe9\xe1\xaa
#    cycle = '4\x05i>O7\x91\x87\x0b\x84\"@\xe9\xe1\xaa\x13'
    cycle = '\xe1\xaa\x134\x05i>O7\x91\x87\x0b\x84"@\xe9'
    while True:
        cookie = get_cookie(password)
        if cookie.find(cycle * 2) != -1:
            print cookie.find(cycle * 2)
            break
        password += 'a'
    return cookie, len(password)

def try_char(cookie, L):
    ''' n = 1 to L? '''

    username = ""
    solved = ""

    for i in xrange(32):
        c = get_cookie('a' * (L - 1 - len(solved)))[48:64]
        for x in string.printable:
            c_prime = get_cookie('a' * (L - 1 - len(solved)) + solved + x)[48:64]
            if c == c_prime:
                solved += x
                print x
                break
    print "!@#!@# " + solved

if __name__ == '__main__':
#    cookie, L = get_min_L()
    cookie, L = get_cookie('a' * 46), 47 # cookie[32~47], cookie[48~63]
#    print "%r" % cookie[32:48]
#    print "%r" % cookie[48:64]
    try_char(cookie, L)
