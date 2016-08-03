import time

start = time.time()


total = 0

stack = [1, 2]
secondNum = 0

while secondNum < 4000000:
    secondNum = stack.pop()
    firstNum = stack.pop()

    if(secondNum % 2 == 0):
        total+=secondNum

    stack.append(secondNum)
    stack.append(firstNum+secondNum)


print total

elapsed = time.time() - start

print("found in %s seconds") % (elapsed)
