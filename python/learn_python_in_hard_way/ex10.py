# -*- coding: utf-8 -*-

# In " we should use '
tabby_cat = "\tI'm tabbed in."
# ' is equaled to ", and still escape.
# backslash need to be escape.
persian_cat = 'I\'m split\non a line.'
backslash_cat = "I'm \\ a \\ cat."

# 1. """ is like ", moreover, """ turn line changes into \n, and escape them.
# 2. Using ''' instead of """, just based on style.
fat_cat = '''
I'll do a list:
\t* Cat Food
\t* Dog shit\n\t* Fishes
'''

print tabby_cat
print persian_cat
print backslash_cat
print fat_cat
# By this we can see """ turn line changes into \n automatically
print "[With %r]", "%r" % fat_cat

# play with escape sequences.
print "[normal] haha"
# when output a bell, some terminal would produce a beep. However, some not(such as ubuntu terminal)
print "[ascii bell] ha\aha"
print "[ascii backspace] ha\bha"
print "[horizontal tab] ha\tha"
print "[vertical tab] ha\vha"
print "[formfeed] ha\fha"
print "\u0120"
