#include <stdio.h>
#include <iostream>
#include <math.h>
#include "BigInt.hpp"
using namespace std;

int n = 20;

BigInt fact(BigInt n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}


int main() {
    BigInt result = fact(40)/(fact(20)*fact(20));  

    cout << "Wege: " << result << endl;

    // Damit ein Pfad entsteht, werden 40 Wegelemente über ein 20x20 Grid angeordnet

    return 0;
}


