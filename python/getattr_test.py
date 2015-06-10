#!/usr/bin/python

import threading

'''
class ha(object):
    def __getattr__(self, name):
        print name
    def __init__(self):
        print "in init"
    def __call__(self, a):
        print "in call"
'''

if __name__ == "__main__":
    h = ha() # print "in init"
    h("haha") # print "in call"
    h.yaya # print yaya
