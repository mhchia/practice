
class aaa(object):

    def __init__(self):

        print "inited"

    def __enter__(self):

        print "entered"

    def __exit__(self, e1, e2, e3):

        print "exited"

    def __call__(self):

        print "called"

if __name__ == "__main__":

    with aaa():
        print "shit"
