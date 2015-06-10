# -*- coding: utf-8 -*-
a = "哈"
b = 5
# 1. Using " or ' seems no difference, unlike bash strings.
# 2. And if a formatter is not correspond to a variable, it is interpreted as normal string.
print "Print with %r", "%r" % a
print "Print with", '%s', "%s" % a
print "Print with", '%r', "%r" % b
print "Print with", '%d', "%d" % b
