#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> get_names(std::string file_content) {

    std::vector<std::string> names;

    std::string temp = "";

    for(char c : file_content) {
        if(c == ',') {
            names.push_back(temp);
            temp = "";
            continue;
        }

        if(c != '"') { // ' " ' ignorieren
            temp += c;
        }
    }

    return names;
}

bool compare_function(std::string a, std::string b) {
    return a<b;
}

int get_letter_value(char letter) {
    return letter - '@';
}

int get_name_value(std::string name, int number) {
    int result = 0;

    for(char a : name) {
        result += get_letter_value(a);
    }

    return result*number;
}

int main() {

    std::ifstream stream;
    std::string content;
    stream.open("names.txt", stream.in);

    if(stream.is_open()) {
        stream >> content;
        stream.close();

        std::vector<std::string> names = get_names(content);
        std::sort(names.begin(), names.end(), compare_function);


        int sum = 0;
        int counter = 1;
        for(auto &a : names) {
           
            sum+= get_name_value(a, counter);
            counter++;
        }

        std::cout << "Summe der Namen: " << sum << std::endl;
    }
    return 0;
}