import sys

from PIL import Image

im = Image.open("stego-e27e53959c0cf1dc83e52946ecc4044a.png")
pix = im.load()

string = ""
for i in xrange(im.size[0]):
    for j in xrange(im.size[1]):
        a = pix[i, j][2] & 0x01
        if a == 1:
            sys.stdout.write('.')
        else:
            sys.stdout.write(' ')
        string += str(a)

