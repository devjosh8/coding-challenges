#include <iostream>
#include <math.h>
#include <array>
#include <string>
#include <algorithm>

// Zahlenwerte werden nach Wert georndet, insgesamt gibt es für 10 Zahlen 10! Möglichkeiten

int main() {    

    unsigned int permutations = 1000000;
    std::string current = "0123456789";
    while(--permutations) {
        std::next_permutation(current.begin(), current.end());
    }

    std::cout << "Permutation: " << current << std::endl;

    return 0;
}