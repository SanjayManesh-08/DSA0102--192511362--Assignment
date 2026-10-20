#include <iostream>
using namespace std;

enum class Zone
{
    Inner,
    Middle,
    Outer
};

const int INNER_FARE = 10;
const int MIDDLE_FARE = 20;
const int OUTER_FARE = 30;
const int PEAK_SURCHARGE_PERCENT = 20;
const int MIN_BALANCE = 50;

int getFare(Zone zone, bool peak)
{
    int baseFare = 0;

    switch (zone)
    {
        case Zone::Inner:
            baseFare = INNER_FARE;
            break;

        case Zone::Middle:
            baseFare = MIDDLE_FARE;
            break;

        case Zone::Outer:
            baseFare = OUTER_FARE;
            break;

        default:
            return 0;
    }

    if (peak)
    {
        baseFare = baseFare +
                   (baseFare * PEAK_SURCHARGE_PERCENT / 100);
    }

    return baseFare;
}

bool canTravel(int balance, int fare)
{
    return fare > 0 && balance - fare >= MIN_BALANCE;
}

int main()
{
    int balance = 100;
    int zoneChoice;
    int hour;

    cout << "Initial balance: Rs " << balance << '\n';

    for (int i = 1; i <= 3; i++)
    {
        cout << "\nJourney " << i << '\n';
        cout << "Select zone (1=Inner, 2=Middle, 3=Outer): ";
        cin >> zoneChoice;

        cout << "Enter hour (0-23): ";
        cin >> hour;

        if (zoneChoice < 1 || zoneChoice > 3 ||
            hour < 0 || hour > 23)
        {
            cout << "Invalid input. Journey skipped.\n";
            continue;
        }

        Zone zone;

        switch (zoneChoice)
        {
            case 1:
                zone = Zone::Inner;
                break;
            case 2:
                zone = Zone::Middle;
                break;
            default:
                zone = Zone::Outer;
                break;
        }

        bool peak = (hour >= 8 && hour < 10) ||
                    (hour >= 17 && hour < 20);

        int fare = getFare(zone, peak);

        if (canTravel(balance, fare))
        {
            balance -= fare;
            cout << "Journey accepted. Fare: Rs "
                 << fare << '\n';
        }
        else
        {
            cout << "Journey denied. Minimum balance rule.\n";
        }

        cout << "Remaining balance: Rs "
             << balance << '\n';
    }

    cout << "\nFinal balance: Rs " << balance << '\n';

    return 0;
}

