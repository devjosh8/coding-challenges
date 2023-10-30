'''
https://projecteuler.net/problem=4
'''

results = []

for x in reversed(range(100, 1000)):
    for y in reversed(range(100, 1000)):
        result = x*y

        palindrome = [int(x) for x in str(result)]
        rev = list(reversed(palindrome))

        #print("Palindrom gefunden: " + str(palindrome))

        if result == 0: continue

        if palindrome == rev and palindrome not in results:
            results.append(result)


print(results)

largest = max(results)

print("Größtes Palindrom: " + str(largest))