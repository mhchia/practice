
import random

def get_random_string():
    n = random.randint(4, 10)
    s = ""
    for i in xrange(n):
        s += random.choice("abcdef")
    return s

num = 10000
print(num)
for i in xrange(num):
    s = get_random_string()
    print(s)
