#include <iostream>
#include <iomanip>
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
            {
                return value;
            }

            cout << "Invalid value. Please try again.\n";
        }
        else
        {
            cout << "Invalid input. Enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int getFare(int zone, bool peak)
{
    int fare;

    switch (zone)
    {
        case 1:
            fare = INNER_FARE;
            break;

        case 2:
            fare = MIDDLE_FARE;
            break;

        case 3:
            fare = OUTER_FARE;
            break;

        default:
            return 0;
    }

    if (peak)
    {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

int main()
{
    int balance = 100;
    int journeyCount = 3;
    int totalPaid = 0;

    cout << "====================================\n";
    cout << "      CITY METRO SMART CARD\n";
    cout << "====================================\n";
    cout << "Starting balance: Rs "
         << fixed << setprecision(2)
         << balance << "\n";

    cout << "\nEnter details for " << journeyCount
         << " journeys.\n";

    cout << "\n";

    cout << left << setw(10) << "Journey"
         << setw(12) << "Zone"
         << setw(10) << "Fare"
         << "Balance\n";

    cout << "------------------------------------\n";

    for (int i = 1; i <= journeyCount; i++)
    {
        cout << "\nJourney " << i << '\n';

        int zone = readInteger(
            "Enter zone (1=Inner, 2=Middle, 3=Outer): ",
            1, 3
        );

        int hour = readInteger(
            "Enter hour (0-23): ",
            0, 23
        );

        bool peak = (hour >= 8 && hour < 10) ||
                    (hour >= 17 && hour < 20);

        int fare = getFare(zone, peak);

        cout << left << setw(10) << i;

        if (zone == 1)
            cout << setw(12) << "Inner";
        else if (zone == 2)
            cout << setw(12) << "Middle";
        else
            cout << setw(12) << "Outer";

        if (balance - fare >= MIN_BALANCE)
        {
            balance -= fare;
            totalPaid += fare;

            cout << "Rs " << setw(6) << fare
                 << "Rs " << balance << '\n';
        }
        else
        {
            cout << "Denied: minimum balance rule\n";
            cout << "Balance unchanged: Rs "
                 << balance << '\n';
        }
    }

    cout << "\n====================================\n";
    cout << "          JOURNEY SUMMARY\n";
    cout << "====================================\n";
    cout << "Journeys processed: " << journeyCount << '\n';
    cout << "Total fare paid:    Rs " << totalPaid << '\n';
    cout << "Final balance:      Rs " << balance << '\n';

    return 0;
}

