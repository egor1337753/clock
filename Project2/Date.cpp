#include "Date.h"
#include <iomanip>
using namespace std;




Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}


void Date::showDate() const {
    cout << setw(2) << setfill('0') << day << "-"
        << setw(2) << setfill('0') << month << "-"
        << year << endl;
}
