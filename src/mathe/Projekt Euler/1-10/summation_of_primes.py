'''
https://projecteuler.net/problem=10
'''

import math

n = 2000000

primes = [True] * (n)

print("Array aufgefüllt")

primes[0]=primes[1]=False


for a in range(2, int(math.sqrt(n)) + 1):
    if primes[a]:
        for b in range(a*a, n, a):
            primes[b] = False

summe = sum(i for i in range(2, n) if primes[i])

print(f"Summe ={summe}")