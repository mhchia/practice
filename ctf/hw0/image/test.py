import binascii
import sys
import string

from PIL import Image

im = Image.open("stego-e27e53959c0cf1dc83e52946ecc4044a.png")
pix = im.load()

#new_image = Image.new("RGB",im.size)
#newim = new_image.load()



s1 = ""
count = 0
char = 0
for j in xrange(im.size[0]):
    for i in xrange(im.size[1]):
        if i % 8 == 0:
            char = 0
        a = pix[i, j][2] % 2
        char += a * (2 ** (i % 8))
        if i % 8 == 7:
            if chr(char) in string.printable:
                s1 += chr(char)

print s1
#n = int(string, 2)
#print binascii.unhexlify('%x' % n)
'''
print string
new_image.save('newnew.png')
'''
