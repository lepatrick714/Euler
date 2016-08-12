import time
import math

def is_prime(a) :
    if a == 1:
        return False

    i = 2
    while i <= int(math.sqrt(a)) :
        if a%i==0 :
            return False
        i+=1
    return True


def isPandigital(a) :
    stringTemp = str(a)
    temp = list(stringTemp)

    ctr = 1
    while ctr <= len(stringTemp) :
        for item in temp :
            if str(ctr) in temp :
                ctr += 1
            else :
                return False
    return True

start = time.time()

i = 7654321
while i >= 2143 :
    if is_prime(i) :
        if isPandigital(i) :
            print i
            break;
    i-=2

elapsed = time.time()

print("found in %s seconds") % (elapsed)
