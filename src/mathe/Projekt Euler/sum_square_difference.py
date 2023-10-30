'''
https://projecteuler.net/problem=6
'''




# 0-100 mit Gauß'scher Summenformel
n = 100

square_of_sum = float((n * (n + 1))/2)
square_of_sum = float(square_of_sum * square_of_sum) # quadrieren


# 0-100 jeweils quadriert umgeschrieben als kubisches Polynom

sum_of_squares = float((2*n*n*n + 3*n*n + n)/6)

# finale Berechnung

result = square_of_sum - sum_of_squares

print("Ergebnis: " + str(result))