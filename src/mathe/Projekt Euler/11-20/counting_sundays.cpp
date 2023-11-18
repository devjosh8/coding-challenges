#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int current_day = 0;

int sundays_on_first_of_month = 0;

int main() {
    // 1. Januar 1901 ist ein Dienstag

    // Bedeutet: Sobald der Tag durch 7 teilbar ist, war es ein Dienstag
    // Sobald der Tag-5 durch 7 teilbar ist, war es ein Sonntag

    for(int year = 1901; year < 2001; year++) {

        for(int month = 1; month < 13; month++) {

            cout << "Jahr " << year << " mit " << month << endl;;
            int days_in_month = 31;
            if(month == 4 || month == 6 || month == 9 || month == 11) days_in_month = 30;// April, Juni, September und November haben 30 Tage

            if(month == 2) { // Februar hat 28 Tage, außer jedes Schaltjahr, da hat er 29 Tage
                days_in_month = 28;
                if(year % 4 == 0)days_in_month = 29;
            }


            for(int day = 0; day < days_in_month; day++) {
                current_day++;
                if(day == 0 && (current_day-5) % 7 == 0) {
                    cout << "Es ist Sonntag am ersten des Monats! " << endl;
                    sundays_on_first_of_month++;
                }
            }
        }
    }

    cout << "Es gab insgesamt " << current_day << " Tage!" << endl;
    cout << "Sonntage an Monats-Anfängen: " << sundays_on_first_of_month << "!" << endl;

    return 0;
}