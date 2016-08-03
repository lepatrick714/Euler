import time

start = time.time()

def calculateTotal(ending):
    total = (ending * (ending+1))/2
    return total


find3 = 3*calculateTotal(333)
find5 = 5*calculateTotal(199)
findRepeat = 15*calculateTotal(66)

total3And5 = find3+find5-findRepeat
print total3And5



elapsed = time.time() - start

print("found in %s seconds") % (elapsed)
