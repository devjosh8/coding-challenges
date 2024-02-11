#include <iostream>
#include <math.h>
#include <vector>
#include <array>

int divSum(int num);

int main() {

    std::vector<int> abundant_numbers;

    int i;
    for(i = 0; i < 28124; i++) {
        if(divSum(i) > i) {
            abundant_numbers.push_back(i);
        }
    }   

    std::array<int, 28124> numbers;

    for(int a = 1; a < 28124; a++) {
        numbers[a] = a;
    }  

    for(auto &first : abundant_numbers) {
        for(auto &second : abundant_numbers) {
            if(first+second > 28123)continue;
            numbers[first + second] = 0;
        }   
    }

    int sum = 0;
    for(int b = 0; b < numbers.size(); b++) {
        if(numbers[b] != 0) {
            sum+= numbers[b];
        }
    }

    std::cout << "Summe: " << sum << std::endl;

    
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
