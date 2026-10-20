#include <iostream>
using namespace std;


constexpr int BASE_FARE_INNER = 10;
constexpr int BASE_FARE_MIDDLE = 20;
constexpr int BASE_FARE_OUTER = 30;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int MIN_BALANCE = 50;


enum class Zone {
    Inner,
    Middle,
    Outer
};


int getBaseFare(Zone zone) {
    switch (zone) {
        case Zone::Inner:
            return BASE_FARE_INNER;

        case Zone::Middle:
            return BASE_FARE_MIDDLE;

        case Zone::Outer:
            return BASE_FARE_OUTER;
    }

    return 0;
}

int main() {
    Zone selectedZone = Zone::Middle;

    cout << "Inner zone fare: Rs "
         << BASE_FARE_INNER << endl;

    cout << "Middle zone fare: Rs "
         << BASE_FARE_MIDDLE << endl;

    cout << "Outer zone fare: Rs "
         << BASE_FARE_OUTER << endl;

    cout << "Peak surcharge: "
         << PEAK_SURCHARGE_PERCENT << "%" << endl;

    cout << "Minimum balance: Rs "
         << MIN_BALANCE << endl;

    cout << "Selected zone base fare: Rs "
         << getBaseFare(selectedZone) << endl;

    return 0;
}

