'''
https://projecteuler.net/problem=9
'''

import math

def is_natural(x):
    if x % 1:
        return True
    return False


# Wenn gilt: a < b < c und a+b+c=1000 dann ist c größer als 500, somit ist b größer als 250 und a kleiner als 250

found = False

for c in range(int(1000/3+1), 1000):
    for b in range(251, c):
        a = 1000 - b - c
        if a <= 0: continue
        print(".")
        if a*a + b*b == c*c:
            print("Ergebnis gefunden, a=" + str(a) + ", b=" + str(b) + ", c=" + str(c))
            print("Zusammengerechnet: " + str(int(a+b+c)))
            print("Formel: " + str(int(a*a)) + " + " + str(int(b*b)) + " = " + str(int(c*c)))
            print("Produkt der Ergebnisse: " + str(int(a*b*c)))
            found = True
            break
    if found: break