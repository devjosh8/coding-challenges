#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int calculateDivisors(int number) {
    if(number <= 1)return 1;
    int div = 1;

    // Map die den Primfaktor und deren Anzahl enthält
    unordered_map<int, int> prime_factor_map;
    
    int find_prime_factor = number;

    while (true)
    {   

        if(find_prime_factor <= 1)break;
        bool found = false;
        for(int m = 2; m < int(sqrt(find_prime_factor)+1); m++) {
            if(find_prime_factor % m == 0) { // Erster Primfaktor gefunden

                if(prime_factor_map.find(m) == prime_factor_map.end()) {
                    prime_factor_map[m] = 1;
                } else {
                    prime_factor_map[m] = prime_factor_map[m] + 1;
                }
                find_prime_factor = find_prime_factor / m;
                found = true;
                break;
            }
        }

        

        if(!found) {
            if(prime_factor_map.find(find_prime_factor) == prime_factor_map.end()) {
                prime_factor_map[find_prime_factor] = 1;
            } else {
                prime_factor_map[find_prime_factor] = prime_factor_map[find_prime_factor] + 1;
            }
            break;
        }
    }
    

    
    for(auto& it : prime_factor_map) {
        div *= (prime_factor_map[it.first]+1);
    }

    return div;
}

int main() {

    int triangle_number = 0;

    int last_addition = 1;

    while (true)
    {
        triangle_number = triangle_number + last_addition;
        last_addition++;
        if( calculateDivisors(triangle_number) > 500) {       
            break;
        }
    }

    cout << "Erste Dreiecks-Zahl mit über 500 Teilern gefunden: " << triangle_number;
   
    return 0;
}


