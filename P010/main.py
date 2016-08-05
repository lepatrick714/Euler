import time
import math

def isPrime(n) :
    if n == 1 : return False

    i = 2
    while i <= math.sqrt(n) :
        if n%i==0 :
            return False
        i+=1
    return True

def sumOfPrimes(n) :
    result = 0
    i = 2
    while i < n :
        if isPrime(i) == True :
            result += i
        i+=1

    print result

start = time.time()

sumOfPrimes(2000000)

elapsed = time.time()

print("found in %s seconds") % (elapsed)
