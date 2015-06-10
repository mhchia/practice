# -*- coding: utf-8 -*-
from sys import argv

# unpack argument variables
script, filename = argv

# open returns a file object
# just like the file constructor
txt = open(filename)
print "I opened the fuking %r" % filename
# calling a function read() on the file object
# read from the file txt
print txt.read()

print "Type the filename again :",
# input the filename from stdin rather than argv
filename_again = raw_input()
txt_again = open(filename_again)
print "I opened %r, again!" % filename_again

print txt_again.read()
# tell txt, txt_again to close()
txt.close()
txt_again.close()
