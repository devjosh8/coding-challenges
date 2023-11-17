#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>

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

void findLongestPath(int triangle_ints[15][15]);
bool pathValueFinderRecursive(int current_row, int index, int triangle_ints[15][15], bool triangle_mask[15][15], string currentID, map<string, int> &pathValues, int current_path_value);

bool wayExists(bool allowed_array[15][15], int current_row, int index, int triangle_ints[15][15]) {
    if(current_row >= 15) {
        return true;
    }

    if(!allowed_array[current_row][index]) {
        return false;
    }

    bool exists = false;

    if((allowed_array[current_row+1][index])) {
        if(wayExists(allowed_array, current_row+1, index, triangle_ints)) {
            triangle_mask[current_row+1][index] = 1;
            exists = exists | true;
        }
    }

    if((allowed_array[current_row+1][index+1])) {
        if(wayExists(allowed_array, current_row+1, index+1, triangle_ints)) {
            triangle_mask[current_row+1][index+1] = 1;
            exists = exists | true;
        }
    }

    return exists;
}


int main() {

    int triangle[15][15] = {0};


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

    // Dreieck Eingabe wurde in ein nutzbares Array umgewandelt

    // Array, das speichert, welche der Nodes in dem Array "erlaubt" sind
    bool allowed_array[15][15] = {false};


    // Idee: Langsam aber sicher die größten Zahlen aus der Pyramide raussuchen und in ein Array packen
    // Nach jeder Hinzufügung einer Zahl versuchen, einen Pfad zu generieren
    // Der erste Pfad der möglich ist, ist auch der beste Pfad
    // Wenn mehrere Pfade gleichzeitig möglich werden, alle Möglichkeiten überprüfen, welcher der "beste" Pfad ist
    while (true)
    {
        int currentMin = 0;
        int maxX, maxY;
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

    // Mögliche Wege wurden gefunden und alle Nodes die für die Wege verwendet wurden sind in der Triangle-Mask gespeichert

    cout << "Wege wurden gefunden!" << endl;

    /*for(int x = 0; x < 15; x++) {
        for(int y = 0; y < 15; y++) {
            cout << allowed_array[x][y] << " ";
        }
        cout << endl;
    }*/

    cout << "Dreieck-Maske:" << endl;


    for(int x = 0; x < 15; x++) {
        for(int y = 0; y < 15; y++) {
            cout << triangle_mask[x][y] << " ";
        }
        cout << endl;
    }

    findLongestPath(triangle);

    return 0;
}

void findLongestPath(int triangle_ints[15][15]) {

    triangle_mask[0][0] = 1;

    map<string, int> pathValues; // String (ID) / Int (Wert)
    pathValueFinderRecursive(0, 0, triangle_ints, triangle_mask, " ", pathValues, 0);

    cout << "Anzahl an gefundener möglicher Pfade: " << pathValues.size() << endl;

    int longest_path = 0;

    for(auto const& x : pathValues) {
        if(x.second > longest_path) {
            longest_path = x.second;
        }
    }
    cout << "--------------------------------------------------------" << endl;

    cout << "Längster Pfad: " << longest_path;
}

bool pathValueFinderRecursive(int current_row, int index, int triangle_ints[15][15], bool triangle_mask[15][15], string currentID, map<string, int> &pathValues, int current_path_value) {

    if(current_row >= 15) {
        pathValues.insert({currentID, current_path_value});
        current_path_value = 0;
        return true;
    }


    bool exists = false;

    current_path_value+=triangle_ints[current_row][index];

    if((triangle_mask[current_row+1][index])) {
        exists = exists | pathValueFinderRecursive(current_row+1, index, triangle_ints, triangle_mask, currentID + "0", pathValues, current_path_value);
    }

    if((triangle_mask[current_row+1][index+1])) {
        exists = exists | pathValueFinderRecursive(current_row+1, index+1, triangle_ints, triangle_mask, currentID + "1", pathValues, current_path_value);
    }

    if(!exists) {
        currentID = "";
        current_path_value = 0;
    }
    return exists;
}
