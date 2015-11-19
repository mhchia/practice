
def comp(a):
    return a ^ 0xFF

def decrypt(string):

    string = list(string)
    for i in reversed(xrange(0, len(string), 4)):
        b0 = ord(string[i])
        b1 = ord(string[i + 1])
        b2 = ord(string[i + 2])
        b3 = ord(string[i + 3])

        string[i]     = chr(b0 ^ b2 ^ b3)
        string[i + 1] = chr(b0 ^ b2)
        string[i + 2] = chr(b0 ^ b3)
        string[i + 3] = chr(b0 ^ b1 ^ b2)

        if i != 0:
            string[i - 4] = chr(ord(string[i - 4]) ^ comp(ord(string[i])))
            string[i - 3] = chr(ord(string[i - 3]) ^ comp(ord(string[i + 1])))
            string[i - 2] = chr(ord(string[i - 2]) ^ comp(ord(string[i + 2])))
            string[i - 1] = chr(ord(string[i - 1]) ^ comp(ord(string[i + 3])))
    string = ''.join(string)
    print string

with open('text-083fea73abe439fcc2e1ebf51d3aa201.enc', 'rb') as f:
    decrypt(f.read())

