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
    temp = range(len(stringTemp))

    for i in range(len(stringTemp)) :
        temp[i] = 0

    for i in range(len(stringTemp)-1) :
        yes = int(stringTemp[i])-1
        if temp[yes] == 1:
            return False
        else:
            return True

    for i in range(len(stringTemp)-1) :
        if temp[i] != 1 :
            return False

    return True



start = time.time()

temp = 0

i = 7654321
while i >= 2143 :
    if is_prime(i) :
        if isPandigital(i) :
            print i
            break
    i-=2

elapsed = time.time()

print("found in %s seconds") % (elapsed)
