import time
import math

start = time.time()

def primeFactors(n):
    while n%2==0:
        print "2 "
        n /= 2

    for i in range(3, int(math.sqrt(n))):
        while n%i == 0:
            print str(i) + " "
            n/=i

    if n>2:
        print n



primeFactors(600851475143)

elapsed = time.time()

print("found in %s seconds") % (elapsed)
