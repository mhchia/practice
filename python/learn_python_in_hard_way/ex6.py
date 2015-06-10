# -*- coding: utf-8 -*-
# string formats and operators

# this suggest that format string is just a string, and we can use % operator to format it with formatter and objects
old = 23
my_words = "I am %d years old"
print my_words % old

# The operation , is different from + with space between strings.
me = "Kevin"
operation = "loves"
you = "Maggie"
print me, operation, you
print me + operation + you

# The %r formatter makes % format object with its type
time = '20150324'
print "Now time is %r" % time
