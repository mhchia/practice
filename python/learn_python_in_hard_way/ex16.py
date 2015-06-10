# -*- coding: utf-8 -*-
from sys import argv
from time import sleep

# unpack argument variables
script, filename = argv

print """
We are going to erase %r.
If you don't want, press Ctrl+C (^C).
If you do want that, hit RETURN.""" % filename

raw_input('?')

# If open the file without 'w', the truncate method will cause an IOError : File not open for writing
txt = open(filename, 'w')
#txt = open(filename)

# At the time txt.truncate(), the file is already empty before txt.close()
# Thus, the write() & truncate() method are I/O without buffer?
print "Truncating the file, bye bye."
txt.truncate()

sleep(1000)
print "Now enter three lines and I will write them into %r" % filename
line1 = raw_input('line1 : ')
line2 = raw_input('line2 : ')
line3 = raw_input('line3 : ')

print "Im going to write them into the file"

txt.write(line1 + '\n' + line2 + '\n' + line3 + '\n')

print "And finally, we close it"
txt.close()
