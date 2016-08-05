import time

start = time.time()

def isPrime(n) :
    for i in range(2, n/2):
        if n%i == 0 :
            return False

    return True

def findPrimeNumber(n) :
    result = 0
    ctr = 0
    start = 2

    while ctr != n:
        if isPrime(start) :
            result = start
            ctr += 1
        start += 1

    return result

print findPrimeNumber(10001)

elapsed = time.time()

print("found in %s seconds") % (elapsed)
