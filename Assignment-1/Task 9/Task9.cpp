#include <iostream>
#include <limits>
using namespace std;

const int INNER_FARE = 10;
const int MIDDLE_FARE = 20;
const int OUTER_FARE = 30;
const int PEAK_SURCHARGE_PERCENT = 20;
const int MIN_BALANCE = 50;

int readInteger(string prompt, int minimum, int maximum)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value)
        {
            if (value >= minimum && value <= maximum)
                return value;

            cout << "Invalid value. Try again.\n";
        }
        else
        {
            cout << "Invalid input. Enter numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int getFare(int zone, int hour)
{
    int fare;

    switch (zone)
    {
        case 1: fare = INNER_FARE; break;
        case 2: fare = MIDDLE_FARE; break;
        case 3: fare = OUTER_FARE; break;
        default: return -1;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;

    return fare;
}

int main()
{
    int balance = 100;
    int totalPaid = 0;

    cout << "===== CITY METRO FARE SYSTEM =====\n";
    cout << "Starting balance: Rs " << balance << '\n';

    int recharge = readInteger(
        "Enter recharge amount (Rs -10000 to 10000): ",
        -10000, 10000);

    if (recharge < 0)
    {
        cout << "Negative recharge rejected.\n";
    }
    else
    {
        balance += recharge;
        cout << "Balance after recharge: Rs "
             << balance << '\n';
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << "\nJourney " << i << '\n';

        int zone = readInteger(
            "Enter zone (1=Inner, 2=Middle, 3=Outer): ",
            1, 3);

        int hour = readInteger(
            "Enter hour (0-23): ", 0, 23);

        int fare = getFare(zone, hour);

        if (fare < 0)
        {
            cout << "Unknown zone. Journey rejected.\n";
            continue;
        }

        cout << "Calculated fare: Rs " << fare << '\n';

        if (balance - fare >= MIN_BALANCE)
        {
            balance -= fare;
            totalPaid += fare;
            cout << "Journey accepted.\n";
        }
        else
        {
            cout << "Journey denied: minimum balance rule.\n";
        }

        cout << "Remaining balance: Rs " << balance << '\n';
    }

    cout << "\n===== FINAL REPORT =====\n";
    cout << "Journeys attempted: 5\n";
    cout << "Total fare deducted: Rs " << totalPaid << '\n';
    cout << "Final balance: Rs " << balance << '\n';

    return 0;
}

