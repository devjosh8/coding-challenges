#include <stdio.h>
#include <math.h>

#include "BigInt.hpp"

using namespace std;

int main()  {

    BigInt result = 2;

    for(int i = 0; i < 999; i++) {
        result = result*2;
    }

    BigInt sum = 0;

    cout << result << endl;

    while(true) {

        BigInt rem = result % 10;
        result = result / 10;
        sum+=rem;


        if(result <= 0) {
            break;
        }
    }   


    

    cout << "Summe der Zahlen: " << sum << endl;

    return 0;
}