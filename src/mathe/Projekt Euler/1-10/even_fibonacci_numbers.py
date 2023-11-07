'''
https://projecteuler.net/problem=2
'''

nums = [1, 2]

fibonacci = [1, 2]

fib_result = 0



while True:
    fib_result = nums[0] + nums[1]

    if fib_result > 4000000:
        break

    nums[0] = nums[1]
    nums[1] = fib_result

    print("Fibonacci Zahl: " + str(fib_result))
    fibonacci.append(fib_result)

result = 0

for fib in fibonacci:
    if fib % 2 == 0:
        print("gerade Fibonacci Zahl: " + str(fib))
        result+=fib

print("Summe aller geraden Fibonacci-Zahlen: " + str(result))