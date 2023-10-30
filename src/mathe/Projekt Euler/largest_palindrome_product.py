'''
https://projecteuler.net/problem=4
'''

numbers = []


p = [int(x) for x in str(9009)]
a = list(reversed(p))
if p == a:
    print("Palindrom!")


value = 0


results = []

for x in reversed(range(100, 1000)):
    for y in reversed(range(100, 1000)):
        result = x*y

        palindrome = [int(x) for x in str(result)]
        rev = list(reversed(palindrome))

        #print("Palindrom gefunden: " + str(palindrome))

        if result == 0: continue

        if palindrome == rev:
            print("Palindrom gefunden: " + str(palindrome))
            results.append(result)


print(results)

largest = max(results)

print("Größtes Palindrom: " + str(largest))