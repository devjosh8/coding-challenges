'''
https://projecteuler.net/problem=7
'''

# TODO Umschreiben(!)

array = []
primes = []

current_prime = 0

current_number = 1

n = 120000 # Annäherung, wie viele Zahlen die 10001'ste Primzahl enthalten könnten, pi(x)~x/ln(x)

for a in range(n):
    array.append(a)

array.remove(0)
array.remove(1)

print("Array aufgefüllt")


while(True):
    c = array[0]
    array.remove(c)

    is_not_prime = False
    for b in primes:
        if c % b == 0:
            is_not_prime = True
            continue

    if not is_not_prime:
        primes.append(c)
        print("Primzahl gefunden: " + str(c))

    if len(primes) > 10001:
        break


print("100001' Primzahl: " + str(primes[10000]))