import time
import math

start = time.time()

def findDifference(n):
    result = 0

    squared = (2*pow(n, 3) + 3*pow(n, 2) + n)/6
    addSquared = pow((n*(n+1))/2, 2)

    result = addSquared-squared
    print str(addSquared) + " - " + str(squared) + " = " + str(result)

findDifference(100)

elapsed = time.time()

print("found in %s seconds") % (elapsed)
