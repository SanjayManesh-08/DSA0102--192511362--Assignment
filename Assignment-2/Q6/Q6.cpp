
#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) {
        hours = h;
        minutes = m;
    }

    // Friend function declarations
    friend int minutesBetween(const Time& t1, const Time& t2);
    friend bool earlier(const Time& t1, const Time& t2);
};

// Friend function to calculate difference in minutes
inline int minutesBetween(const Time& t1, const Time& t2) {
    int total1 = t1.hours * 60 + t1.minutes;
    int total2 = t2.hours * 60 + t2.minutes;

    return abs(total1 - total2);
}

// Friend function to compare two times
inline bool earlier(const Time& t1, const Time& t2) {
    int total1 = t1.hours * 60 + t1.minutes;
    int total2 = t2.hours * 60 + t2.minutes;

    return total1 < total2;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "Time Difference: "
         << minutesBetween(departure, arrival)
         << " minutes" << endl;

    cout << "Is departure earlier than arrival? "
         << (earlier(departure, arrival) ? "Yes" : "No")
         << endl;

    Time t1(11, 30);
    Time t2(12, 30);

    cout << "Time Difference: "
         << minutesBetween(t1, t2)
         << " minutes" << endl;

    cout << "Is first time earlier? "
         << (earlier(t1, t2) ? "Yes" : "No")
         << endl;

    Time t3(10, 15);
    Time t4(10, 15);

    cout << "Same Time Difference: "
         << minutesBetween(t3, t4)
         << " minutes" << endl;

    return 0;
}

