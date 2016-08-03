import time

start = time.time()

def checkMultiple(n):
    for i in range(2, 20):
        if n%i != 0: return False

    return True

ctr = 20
while True:
    if checkMultiple(ctr):
        print ctr
        break
    ctr+=20


elapsed = time.time() - start

print("found in %s seconds") % (elapsed)
