#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import re
import requests

from urlparse import urlparse

from Queue import Queue

url = "http://tw.yahoo.com"

r = requests.get(url)

#test = re.findall(r'https?://\S+', r.text)
#test = [i.replace('"', '') for i in test]

print test[0:3]
