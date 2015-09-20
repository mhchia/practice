from sys import argv
from os.path import exists

open(argv[2], 'w').write(open(argv[1]).read())
