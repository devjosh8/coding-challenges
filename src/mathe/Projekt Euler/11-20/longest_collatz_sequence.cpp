#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int calculateChainLength(int number) {
    if(number <= 1)return 0;
    int length = 0;

    long n = number;

    while(n > 1) {

        if(n % 2 == 0) {
            n = n/2;
        } else {
            n = n*3+1;
        }

        length++;
    }

    return length+1;
}

int main() {

    int max_length = 0;

    int number = 0;

    for(int i = 0; i < 1000001; i++) {
        int length = calculateChainLength(i);
        if(length > max_length) {
            max_length = length;
            number = i;
            cout << "Erreicht mit der Zahl: " << number  << " : " << length << endl;
        }
    }

    cout << "Größte Kettenlänge: " << max_length << endl;
    cout << "Erreicht mit der Zahl: " << number << endl;

    cout << "Test: " << calculateChainLength(40) << endl;

    return 0;
}


