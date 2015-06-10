# -*- coding: utf-8 -*-
days = "1 2 3 4"
months = "Jan\nFeb\nMar\nApr"

# Using %r will represent the raw objects, not parsed objects.
# so \n will be inactivated when print %r
print "Days : ", days
print "[Using Dot] Months : ", months
print "[Using %r]", "Months : %r" % months

# Using """ can let the string go across multiple lines, and the line changes
# will be parsed into \n in the string.
print """
ya
babe
ya
"""
