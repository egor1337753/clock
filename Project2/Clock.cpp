#include "Clock.h"
#include <iostream>
#include <iomanip>
#include <thread>


Clock::Clock(int h, int m, int s, Date d)
    : hour(h), minutes(m), seconds(s), date(d),
    stopwatchRunning(false), stopwatchElapsed(chrono::duration<double>::zero())
{}


void Clock::showTime() const {
    cout << setw(2) << setfill('0') << hour << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << endl;
}


void Clock::showMinut() const {
    cout << setw(2) << setfill('0') << minutes << endl;
}


void Clock::showSec() const {
    cout << setw(2) << setfill('0') << seconds << endl;
}


void Clock::changeTime(int newHour, int newMinutes, int newSeconds) {
    if (newHour >= 0 && newHour < 24 && newMinutes >= 0 && newMinutes < 60 && newSeconds >= 0 && newSeconds < 60) {
        hour = newHour;
        minutes = newMinutes;
        seconds = newSeconds;
    }
    else {
        cerr << "Invalid time values!" << endl;
    }
}


void Clock::showDate() const {
    date.showDate();
}


void Clock::startStopwatch() {
    if (!stopwatchRunning) {
        stopwatchRunning = true;
        stopwatchStart = chrono::steady_clock::now();
    }
}


void Clock::stopStopwatch() {
    if (stopwatchRunning) {
        stopwatchElapsed += chrono::steady_clock::now() - stopwatchStart;
        stopwatchRunning = false;
    }
}


void Clock::resetStopwatch() {
    stopwatchRunning = false;
    stopwatchElapsed = chrono::duration<double>::zero();
}

void Clock::displayStopwatch() const {
   chrono::duration<double> elapsed = stopwatchElapsed;
    if (stopwatchRunning) {
        elapsed += chrono::steady_clock::now() - stopwatchStart;
    }
    cout << "Stopwatch: " << elapsed.count() << " seconds" << endl;
}
