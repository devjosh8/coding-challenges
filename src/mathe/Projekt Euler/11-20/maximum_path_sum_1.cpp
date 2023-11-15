#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int result_sum = 0;

string input = "75 \n"
"95 64 \n"
"17 47 82 \n"
"18 35 87 10 \n"
"20 04 82 47 65 \n"
"19 01 23 75 03 34 \n"
"88 02 77 73 07 63 67 \n"
"99 65 04 28 06 16 70 92 \n"
"41 41 26 56 83 40 80 70 33 \n"
"41 48 72 33 47 32 37 16 94 29 \n"
"53 71 44 65 25 43 91 52 97 51 14 \n"
"70 11 33 28 77 73 17 78 39 68 17 57 \n"
"91 71 52 38 17 14 91 43 58 50 27 29 48 \n"
"63 66 04 68 89 53 67 30 73 16 69 87 40 31 \n"
"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23 \n";

bool triangle_mask[15][15] = {0};

int way_sum = 0;

bool wayExists(bool triangle[15][15], int current_row, int index, int triangle_ints[15][15]) {

    way_sum += triangle_ints[current_row][index];

    if(current_row == 14) {
        triangle_mask[current_row][index] = 1;

        cout << "Weg gefunden mit Wert: " << way_sum << endl;
        way_sum = 0;
        return true;
    }

    

    bool exists = false;

    if((triangle[current_row][index])) {
        triangle_mask[current_row][index] = 1;
        exists = exists | wayExists(triangle, current_row+1, index, triangle_ints);
    }

    if((triangle[current_row][index+1])) {
        triangle_mask[current_row][index+1] = 1;
        exists = exists | wayExists(triangle, current_row+1, index+1, triangle_ints);
    }

    // Entweder rechts oder links, index oder index+1

    if (!exists) {
        way_sum = 0;
    } 

    return exists;
}


int main() {
    // Idee: Langsam aber sicher die größten Zahlen aus der Pyramide raussuchen und in ein Array packen
    // Nach jeder Hinzufügung einer Zahl versuchen, einen Pfad zu generieren
    // Der erste Pfad der möglich ist, ist auch der beste Pfad

    int triangle[15][15] = {01};


    string current_char = "";
    int current_row = 0;
    int current_column_index = 0;

    for(char c : input) {
        if(c == '\n') {
            current_row++;
            current_column_index = 0;
            continue;
        }
        
        if (c == ' ') {
            triangle[current_row][current_column_index] = stoi(current_char);
            current_column_index++;
            current_char = "";
            continue;
        }
        
        if(isalnum(c)) {
            current_char+=c;
        }
        
    }


    for(int x = 0; x < 15; x++) {
        for(int y = 0; y < 15; y++) {
            cout << triangle[x][y] << " ";
        }

        cout << endl;
    }

    // Erlaubter Weg: Entweder selber Index oder +1
    bool allowed_array[15][15] = {false};

    int sum = 0;

    while (true)
    {
        result_sum = 0;
        int currentMin = 0;
        int maxX, maxY;
        sum = 0;
        for(int x = 0; x < 15; x++) {
            for(int y = 0; y < 15; y++) {
                if(allowed_array[x][y])continue;
                if(triangle[x][y] > currentMin) {
                    maxX = x; maxY = y;
                    currentMin = triangle[x][y];
                }
            }
        }

        // Größte Zahl steht fest
        allowed_array[maxX][maxY] = true;

       

        // Überprüfen, ob es einen Pfad gibt
        if(wayExists(allowed_array, 0, 0, triangle)) {
            break;
        }
        
    }

    // Mögliche Wege wurden gefunden
    // Alle mögliche Wege müssen nun gefunden werden und der beste muss herausgesucht werden
    

    // Jeder möglicher Weg bekommt eine ID: 
    cout << "Weg gefunden!" << endl;

    for(int x = 0; x < 15; x++) {
        for(int y = 0; y < 15; y++) {
            cout << allowed_array[x][y] << " ";
        }
        cout << endl;
    }


    cout << "Summe: " << sum << endl;
    

    for(int x = 0; x < 15; x++) {
        for(int y = 0; y < 15; y++) {
            cout << triangle_mask[x][y] << " ";
        }
        cout << endl;
    }

    if(wayExists(triangle_mask, 0, 0, triangle)) {
        cout << "Weg existiert" << endl;
    }

    return 0;
}