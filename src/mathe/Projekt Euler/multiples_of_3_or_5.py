'''
https://projecteuler.net/problem=1
'''

result = 0



for i in range(1000):
    if i == 0: continue
    if i % 3 == 0 or i % 5 == 0:
        result+=i
        print(i)

print("Summe der gefundenen Zahlen: " + str(result))