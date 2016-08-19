#Credits goes to Jason at
#http://code.jasonbhill.com/python/project-euler-42/
#Alteration to his code includes different output specifications and sys command line.

import time
import sys

start = time.time()

with open(str(sys.argv[1]), 'r') as f :
    words = f.read().split(',')
    words = [list(word.strip('\"')) for word in words]
    f.close()

m = max([len(word) for word in words])

triangles = [n*(n+1)/2 for n in range(1,2*m)]

vals = {}
s = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
for c in s:
    vals[c] = s.index(c) + 1


triangle_words = 0
for word in words :
    if sum([vals[c] for c in word]) in triangles:
        triangle_words += 1

print "Total triangle words: %s" % (triangle_words)

elapsed = time.time() - start

print "found in: %s" % (elapsed)
