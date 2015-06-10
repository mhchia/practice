# -*- coding: utf-8 -*-

import sys

# 1. raw_input([prompt]) shows the prompt in the begin of the line,
# and waiting for the user enter their response.
# At last, return the value.
# e.g.
# age = raw_input('> ')
# > 23
# age will be assigned with '23'

# 2. input([prompt]) shows the prompt in the begin of line,
# and waiting for user enter their response.
# What is different from raw_input() is that input() will parse the input
# sequence type. If the input is an expression, the expression will be
# calculated first and then return the result. Else if the input is a string,
# value, or variable, this input will be return directly. Else, python
# interpreter will return error.

prompt = '> '

# Using ',' to prevent from python output the end-of-line.
print "How old are you?",
age = raw_input()

# Using a customized prompt instead, to imitate bash.
print "How tall are you?"
height = raw_input(prompt)
print "How much do you weigh?"
weight = raw_input(prompt)

# Using %r we can see the inputs are strings.
print "So you are %r years old, %r cm tall, %r kg heavy" % (age, height, weight)

# Testint input() = eval(raw_input())
while True:
    try:
        print "Try out for input()          ",
        a = input()
        print "Try out for eval(raw_input())",
        b = eval(raw_input())
        print "input()           result: %r" % a
        print "eval(raw_input()) result: %r" % b
    except EOFError:
        sys.exit(1)
