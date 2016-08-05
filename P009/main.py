import time
import math

def findProduct() :
    a = 0
    sum = 1000

    for a in range(1, int(sum/3)) :
        b = a+1
        while b < int(sum/2) :
            c = sum-a-b
            if a*a + b*b == c*c :
                return a*b*c
            b+=1
    return -1

start = time.time()

result = findProduct()
print result



elapsed = time.time()

print("found in %s seconds") % (elapsed)
