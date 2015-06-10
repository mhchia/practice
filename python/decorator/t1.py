#!/usr/bin/env python
# -*- coding: utf-8 -*-

# assign an function to a variable.
def greet(name):
    return 'Hey ' + name
greet_someone = greet
print greet_someone('John')

# define an function inside a function.
def greet1(name):
    def get_message():
        return "Hey "
    return get_message() + name
print greet1('Kevin')

# a function return an function which is defined inside itself.
def gee():
    def get_message(yo):
        return "Hey " + yo
    return get_message
greet3 = gee()
print greet3('Mag')

# the function inside has access to the enclosing scope.
def geee(name):
    def get_message():
        return "Hey " + name
    return get_message
greet4 = geee('Jerry')
print greet4()

# compose a decorating function ourselves.
def dec(func):
    # to test when the dec is done
    print "outside do_decorating"
    def do_decorating(name):
#        print "decorating function"
        result = "[Dec] " + func(name)
        return result
    return do_decorating

def greet5(name):
    return "Hey " + name

decorated_greet = dec(greet5)
#print "after decorating"
print decorated_greet('Ken')

# Using syntactic sugar(easy-reading expression) provided by python to
# do decorating.
# Using @dec, python will immediately run dec to decorate the greet6
# function. Thus, if you write something print in dec function, it will
# print out at that time.
@dec
def greet6(name):
    return "Hey " + name
#print "after decorating"
print greet6('David')

# Conclusion: decorating function eat a function as input, defining a new
# function that extending the input function's functionality, and at last
# output the new function.


# Considering decorating twice.
def dec_again(func):
    # compared to the print in do_decorating
    #print "outside dec_againing
    def do_decorating(name):
#        print "dec_againing function"
        return "[Dec_again]" + func(name)
    return do_decorating
decorated_greet = dec_again(dec(greet5))
#print "after decorating"
print decorated_greet('Alice')
print "fsaksdfa", decorated_greet.__name__

# And the corresponding syntax in python decorator is...
# we can see that the order of decoration is from inside to outside.
@dec_again
@dec
def greet7(name):
    return "Hey " + name
#print "after decorating"
print greet7('Bob')

def test_keyword_arguments(*args, **kwargs):
    print '{0} {1}'.format(args, kwargs)
test_keyword_arguments(1, 2, 5, kk='shit', a={'ha':90})
