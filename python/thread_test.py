import threading
import time

def ha():

    print "ha"
    time.sleep(10)
    print "ooo"

if __name__ == "__main__":

    t = threading.Thread(target = ha)
    t.start()
    print "shit!"
