//programmed by Jean Karst
//CS 210 Project One

#include <iostream>
#include <iomanip>

class Clock {
protected:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void addHour() {
        //24 hour range
        hours = (hours + 1) % 24;
    }

    void addMinute() {
        minutes = (minutes + 1) % 60;
        //if minutes roll over
        if (minutes == 0) addHour();
    }

    void addSecond() {
        seconds = (seconds + 1) % 60;
        //if second roll over
        if (seconds == 0) addMinute();
    }

    virtual void displayTime() const = 0;
};

class TwelveHourClock : public Clock {
public:
    //constructor
    using Clock::Clock;

    void displayTime() const override {
        bool isPM = hours >= 12;
        int displayHour = hours % 12;
        //if hour is 0
        if (displayHour == 0) displayHour = 12;

        std::cout << "12-Hour Clock: ";
        std::cout << std::setw(2) << std::setfill('0') << displayHour << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds
            << (isPM ? " PM" : " AM") << std::endl;
    }
};

class TwentyFourHourClock : public Clock {
public:
    //constructor
    using Clock::Clock;

    void displayTime() const override {
        std::cout << "24-Hour Clock: ";
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};
//main menu
void displayMenu() {
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1. Add One Hour" << std::endl;
    std::cout << "2. Add One Minute" << std::endl;
    std::cout << "3. Add One Second" << std::endl;
    std::cout << "4. Goodbye" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    TwelveHourClock twelveHourClock(10, 59, 58);
    TwentyFourHourClock twentyFourHourClock(22, 59, 58);

    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        displayMenu();
        std::cin >> choice;
        //swtich statements based on users input
        switch (choice) {
        case 1:
            twelveHourClock.addHour();
            twentyFourHourClock.addHour();
            std::cout << "One hour added." << std::endl;
            break;
        case 2:
            twelveHourClock.addMinute();
            twentyFourHourClock.addMinute();
            std::cout << "One minute added." << std::endl;
            break;
        case 3:
            twelveHourClock.addSecond();
            twentyFourHourClock.addSecond();
            std::cout << "One second added." << std::endl;
            break;
        case 4:
            exitProgram = true;
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
