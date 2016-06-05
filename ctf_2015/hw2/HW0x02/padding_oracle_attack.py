from pwn import *
import base64


class Solver(object):

    def __init__(self):

        self.c_b64 ="NfHBHcVs1MzChTWg/yPibl97EcV9e566VfocKI60xhOVG/ko1PVQ2g9F5etdzLiAwPhczk8zPqJ99ohkKWehVg=="
        self.c = base64.b64decode(self.c_b64)
        chunks, chunk_size = len(self.c), 16
        self.cipher = [self.c[i:i + chunk_size]  for i in range(0, chunks, chunk_size)]

        self.r = remote('csie.ctf.tw', 10118)
        #self.r = remote('127.0.0.1', 8000)
#        print len(self.cipher[0])

    def send_cipher(self, message):

        self.r.send(base64.b64encode(message) + '\n')
        result = self.r.recvline()[:-1]
        if result == 'true':
            return True
        elif result == 'false':
            return False
        else:
            raise ValueError('send_cipher: %r' % result)

    def try_block(self, cipher):

        d = [''] * 16
        x = '\x00' * 16
        for index in xrange(15, -1, -1):
            print "start: %r" % x
            flag = False
            for char in xrange(256):
                # change the char whose pos = index
                tmp = x[0:index] + chr(char) + x[index + 1:]
                result = self.send_cipher(tmp + cipher)
                if result:
                    if index == 15:
                        #tmp1 = x[0:14] + chr(ord(x[14]) + 2) + x[15]
                        tmp1 = tmp[0:14] + chr(ord(tmp[14]) + 2) + tmp[15]
                        result = self.send_cipher(tmp1 + cipher)
                        if result:
                            flag = True
                            break
                    else:
                        flag = True
                        break
            if not flag:
                raise ValueError("no solution at index = %d, char = %d" % (index, ord(tmp[index])))
            org_value = (16 - index) ^ ord(tmp[index])
            d[index] = chr(org_value)
            x = ""
            for i in xrange(16):
                if i < index:
                    x += '\x00'
                else:
                    x += chr(ord(d[i]) ^ (16 - index + 1))
        return ''.join(d)

if __name__ == '__main__':
    s = Solver()
    decoded_ci = [s.try_block(s.cipher[i]) for i in xrange(4)]
    string = ""
    for i in xrange(3):
        for j in xrange(16):
            string += chr(ord(decoded_ci[i+1][j]) ^ ord(s.cipher[i][j]))
    print string
