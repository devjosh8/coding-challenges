#include <iostream>
#include <math.h>
#include <stdio.h>
#include <unordered_map>
#include <map>

int calculateDivisors(int number);

int divSum(int num);

int main() {

    std::unordered_map<int, int> sums;
    
    for(int i = 1; i <= 10000; i++) {
        int a = divSum(i);
        sums[i] = a;
    }

    int sum = 0;

    for(auto &a : sums) {
        if(divSum(sums[a.first]) == a.first) {
            if(divSum(a.first) == a.first)continue;
            std::cout << "Befreundete Zahl gefunden: " << a.first  << " mit " << divSum(a.first) << std::endl;
            sum+= a.first;
        }
    }

    std::cout << "Summe der befreundeten Zahlen: " << sum << std::endl;
    return 0;
}

int divSum(int num)
{

    int result = 0;
    if(num == 1 || num == 0)
      return result;

    for (int i=2; i<=sqrt(num); i++)
    {

        if (num%i==0)
        {
            if (i==(num/i)) {
                result += i;
            } else {
                 result += (i + num/i);
            }
               
        }
    }
    return (result + 1);
}

