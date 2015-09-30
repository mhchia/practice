import binascii
import sys

from PIL import Image

im = Image.open("stego-e27e53959c0cf1dc83e52946ecc4044a.png")
pix = im.load()

new_image = Image.new("RGB",im.size)
newim = new_image.load()



string = ""
for i in xrange(im.size[0]):
    for j in xrange(im.size[1]):
        a = pix[i, j][2] & 1
        if a == 1:
            sys.stdout.write('1')
        else:
            sys.stdout.write('.')
        string += str(a)
        if pix[i, j][2] & 1:
            newim[i, j] = (pix[i, j][0], pix[i, j][1], 255)
        else:
            newim[i, j] = (pix[i, j][0], pix[i, j][1], pix[i, j][2])
'''
string = "0b" + string[::-1]
n = int(string, 2)
print binascii.unhexlify('%x' % n)
'''
new_image.save('newnew.png')
