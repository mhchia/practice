# -*- coding: utf-8 -*-
from sys import argv

# Unpack the argument variables, which will limit the exact number of arguments
# for this example, we need 3 arguments exactly to run this script without
# errors.
script, first, second, third = argv

print "script     :", script
print "first arg  :", first
print "second arg :", second
print "third arg  :", third

print "What do you want?"
ret = raw_input('> ')
b = "You just said %r, shit!"
print b % ret

print '''
hey
asshole!
I am chatting with you without using \\n
%s
''' % (b % ret)
