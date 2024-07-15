#pragma once


#include "Date.h"
#include <chrono>

using namespace std;
class Clock {
private:
    int hour;
    int minutes;
    int seconds;
    Date date;

    bool stopwatchRunning;
    chrono::time_point<chrono::steady_clock> stopwatchStart;
    chrono::duration<double> stopwatchElapsed;

public:
    int GetHour() { return hour; }

    void SetHour(int newHour) { hour = newHour; }

    int GetMinutes() { return minutes; }

    void SetMinutes(int newMinutes) { minutes = newMinutes; }

    int GetSeconds() { return seconds; }

    void SetSeconds(int newSeconds) { seconds = newSeconds; }
    
    
    Clock(int h, int m, int s, Date d);
    void showTime() const;
    void showMinut() const;
    void showSec() const;
    void changeTime(int newHour, int newMinutes, int newSeconds);
    void showDate() const;

    void startStopwatch();
    void stopStopwatch();
    void resetStopwatch();
    void displayStopwatch() const;
};


