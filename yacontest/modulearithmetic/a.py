fib1 = fib2 = 1
 
n = input()
n = int(n) - 2
 
while n > -1:
    fib1, fib2 = fib2, fib1 + fib2
    n -= 1
 
print(fib2%10)