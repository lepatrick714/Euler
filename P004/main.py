import time

start = time.time()

#def is_palindrome2(num):
#    if str(num)==str(num)[::-1]: return True
#            else: return False
#Faster way found on code.jasonbhill.com

def is_palindrome(n):
    oldNum = n
    newNum = 0

    while n >= 1:
        newNum = (newNum*10) + n%10
        n /= 10

    if oldNum == newNum: return True
    else: return False

a = 0
for i in range(100, 999):
    for j in range(i, 999):
        calc = i*j
        if calc > a and is_palindrome(calc):
            a = calc

print a

elapsed = time.time() - start

print("found in %s seconds") % (elapsed)
