#include "Clock.h"
#include <iostream>
#include <thread>
#include <limits>
using namespace std;
void displayMenu() {
    cout << "\nClock Menu:\n";
    cout << "1. Show current time\n";
    cout << "2. Show current date\n";
    cout << "3. Show only minutes\n";
    cout << "4. Show only seconds\n";
    cout << "5. Change time\n";
    cout << "6. Start stopwatch\n";
    cout << "7. Stop stopwatch\n";
    cout << "8. Reset stopwatch\n";
    cout << "9. Display stopwatch time\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Date date(15, 7, 2024);
    Clock clock(12, 30, 45, date);
    int choice;

    do {
        displayMenu();
        cin >> choice;

       
        while (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            cout << "Current time: ";
            clock.showTime();
            break;
        case 2:
            cout << "Current date: ";
            clock.showDate();
            break;
        case 3:
            cout << "Current minutes: ";
            clock.showMinut();
            break;
        case 4:
            cout << "Current seconds: ";
            clock.showSec();
            break;
        case 5:
            int h, m, s;
            cout << "Enter new time (hour minute second): ";
            cin >> h >> m >> s;
            clock.changeTime(h, m, s);
            break;
        case 6:
            clock.startStopwatch();
            cout << "Stopwatch started.\n";
            break;
        case 7:
            clock.stopStopwatch();
            cout << "Stopwatch stopped.\n";
            break;
        case 8:
            clock.resetStopwatch();
            cout << "Stopwatch reset.\n";
            break;
        case 9:
            clock.displayStopwatch();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
