#include <iostream>
#include <stdio.h>
#include "BigInt.hpp"


using namespace std;


int main() {

    BigInt fact = 100;

    for(int i = 99; i > 1; i--) {
        fact*=i;
    }

    BigInt sum = 0;

    while(fact > 0) {
       
        BigInt rem = fact % 10;
        fact = fact / 10;

        sum+=rem;
    }


    cout << "Summe der Zahlen: " << sum << endl;
    return 0;
}