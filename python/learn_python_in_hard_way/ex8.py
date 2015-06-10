# -*- coding: utf-8 -*-

# using %r to print the raw programmer's view of the variable
formatter = "%r %r %r %r"
print formatter % (1, 2, 3, 4)
print formatter % ('one', 'two', 'three', 'four')
print formatter % (True, False, False, True)

# the formatter is just a string.
print formatter % (formatter, formatter, formatter, formatter)

# This will end up printing the 1st, 2nd, 4th strings with single quotes,
# and 3rd with double quotes. Due to the fact that python will print strings
# with the most efficient way it can. So if a string contains \', the quotes
# must be double quotes to prevent confusion.
print formatter % (
    "I had this thing.",
    "That you could type up right.",
    "But it didn't sing.",
    "So I said goodnight."
)
