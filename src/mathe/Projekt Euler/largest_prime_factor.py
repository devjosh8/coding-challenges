import math

'''
https://projecteuler.net/problem=3
'''

num = 600851475143

# Mithilfe Sieb des Eratosthenes Primzahlen von 0 bis 600851475143 ermitteln
# nur Teiler bis sqrt(num) müssen überprüft werden
teiler = []

for i in range(int(math.sqrt(num)) + 1):
    if i == 0 or i == 1: continue
    if 600851475143 % i == 0:
        teiler.append(i)

# Überprüfen ob gefundene Teiler Primzahlen sind

print("Alle Teiler: " + str(teiler))

temp = []

for a in teiler:
    for b in range(int(math.sqrt(a))+1): 

        if b == 0 or b == 1: continue

        if a % b == 0: # Zahl ist durch mögliche Faktoren von 2 bis sqrt(teiler)+1 teilbar also keine Primzahl
            temp.append(a)


for a in temp:
    teiler.remove(a)

print("Teiler, die Primzahlen sind: " + str(teiler))
# Überprüfen, ob durch das Teilen durch die Primzahl eine Primzahl als Ergebnis rauskommt