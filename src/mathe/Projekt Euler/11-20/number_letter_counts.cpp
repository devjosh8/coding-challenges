#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


string zehner_zahlen[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eigthy", "ninety"};

string einser_zahlen[] = {"", "one","two","three","four","five","six","seven","eight","nine"};

string zehner_außnahmen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int main() {

    // (!) Außnahmen 11,12 ... 20

    // Außnahme 1000!

    string numbers_strings[1000] = {""};

    for(int i = 1; i < 1001; i++) {
        //cout << "Aktuelle Zahl: " << i << endl;
        int rem1 = i % 100; // Zehner und Einser bleiben übrig
        int div1 = i / 100; // Anzahl der Hunderterstelle


        int rem2 = rem1 % 10; // Einser bleiben übrig
        int div2 = rem1 / 10; // Anzahl der Zehnerstelle

        

        if(i < 10) {
            numbers_strings[i-1] = einser_zahlen[i];
            cout << "Zahl: " << einser_zahlen[i] << endl;
        } else if(i < 100 && i >= 10) {
            if(i % 10 == 0) {
                // Einzelne Zahl
                int a = i/10;
                cout << "Zahl: " << zehner_zahlen[a] << endl;
                numbers_strings[i] = zehner_zahlen[a];
                continue;
            } else {
                // Zusammengesetzte Zahl

                int a = i/10;
                int remainder = i - a*10;
                if(i > 10 && i < 20) {
                    cout << "Zahl: " << zehner_außnahmen[remainder] << endl;
                    numbers_strings[i] = zehner_außnahmen[remainder];
                } else {
                    cout << "Zahl: " << zehner_zahlen[a] << " " << einser_zahlen[remainder] << endl;
                    numbers_strings[i] = zehner_zahlen[a] + " " + einser_zahlen[remainder];
                }
                continue;
            }
        } else {
            // Zahl ist größer als Hundert
            if(i == 1000) {
                cout << "Zahl: " << "one thousand" << endl;
                numbers_strings[i-1] = "one thousand";
                continue;
            }

            int einser_stelle = i%10;
            int zehner_stelle = ((i/10) % 10);
            int hunderter_stelle = (i - einser_stelle - 10*zehner_stelle) / 100;
            
            if(zehner_stelle == 1) {
                cout << "Zahl: " << einser_zahlen[hunderter_stelle] << "-hundred " << "and " << zehner_außnahmen[einser_stelle] << endl;
                numbers_strings[i] = einser_zahlen[hunderter_stelle] + "-hundred " + "and " + zehner_außnahmen[einser_stelle];
                continue;
            }

            if(i % 100 == 0) {
                cout << "Zahl: " << einser_zahlen[hunderter_stelle] << "-hundred" << endl;
                numbers_strings[i] = einser_zahlen[hunderter_stelle] + "-hundred";
       
                continue;
            }
            if(zehner_stelle == 0) {
                cout << "Zahl: " << einser_zahlen[hunderter_stelle] << "-hundred " << "and " << einser_zahlen[einser_stelle] << endl;
                numbers_strings[i] = einser_zahlen[hunderter_stelle] + "-hundred " + "and " + einser_zahlen[einser_stelle];
        

                continue;
            }

            cout << "Zahl: " << einser_zahlen[hunderter_stelle] << "-hundred " << "and " << zehner_zahlen[zehner_stelle] << " " << einser_zahlen[einser_stelle] << endl;
            numbers_strings[i] = einser_zahlen[hunderter_stelle] + "-hundred " + "and " + zehner_zahlen[zehner_stelle] + " " + einser_zahlen[einser_stelle];
        }
    }

    int result = 0;

    for(string a : numbers_strings) {
        for(char c : a) {
            if(c != ' ' && c != '-') {
                //cout << "Char: " << c;
                result+=1;
            }
        }
    }

    cout << "Ergebnis, Anzahl an Chars: " << result << endl;

    return 0;
}