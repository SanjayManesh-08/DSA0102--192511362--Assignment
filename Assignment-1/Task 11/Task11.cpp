#include <iostream>
using namespace std;

const int INNER_FARE = 10;
const int MIDDLE_FARE = 20;
const int OUTER_FARE = 30;
const int PEAK_SURCHARGE_PERCENT = 20;
const int MIN_BALANCE = 50;

enum class Zone
{
    Inner,
    Middle,
    Outer
};

int getBaseFare(Zone zone)
{
    switch (zone)
    {
        case Zone::Inner:
            return INNER_FARE;

        case Zone::Middle:
            return MIDDLE_FARE;

        case Zone::Outer:
            return OUTER_FARE;
    }

    return 0;
}

bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

int calculateFare(Zone zone, int hour)
{
    int fare = getBaseFare(zone);

    if (fare == 0)
        return 0;

    if (isPeakHour(hour))
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;

    return fare;
}

class SmartCard
{
private:
    int balance;

public:
    SmartCard(int initialBalance)
    {
        balance = initialBalance;
    }

    bool canTravel(int fare) const
    {
        return fare > 0 &&
               balance - fare >= MIN_BALANCE;
    }

    bool deduct(int fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            return true;
        }

        return false;
    }

    int getBalance() const
    {
        return balance;
    }
};

int main()
{
    SmartCard card(100);

    cout << "===== FINAL METRO FARE DESIGN =====\n";
    cout << "Starting balance: Rs "
         << card.getBalance() << '\n';

    Zone zones[] = {
        Zone::Inner,
        Zone::Outer,
        Zone::Middle
    };

    int hours[] = {9, 18, 12};

    for (int i = 0; i < 3; i++)
    {
        int fare = calculateFare(zones[i], hours[i]);

        cout << "\nJourney " << i + 1 << '\n';
        cout << "Fare: Rs " << fare << '\n';

        if (card.deduct(fare))
            cout << "Journey accepted.\n";
        else
            cout << "Journey denied: minimum balance rule.\n";

        cout << "Balance: Rs "
             << card.getBalance() << '\n';
    }

    cout << "\n===== FINAL SUMMARY =====\n";
    cout << "Final balance: Rs "
         << card.getBalance() << '\n';

    return 0;
}

