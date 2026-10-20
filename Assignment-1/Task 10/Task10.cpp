#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
    const double FARE_RUPEES = 10.01;
    const int FARE_WHOLE_RUPEES = 10;

    const int STATION_JOURNEYS = 20000;
    const int LINE_JOURNEYS = 500000;
    const int NETWORK_JOURNEYS = 3000000;

    cout << fixed << setprecision(2);

    cout << "===== TASK 10: TOTAL FARE COMPARISON =====\n";
    cout << "Fare per journey: Rs " << FARE_RUPEES << "\n\n";

    int journeyCounts[] = {
        STATION_JOURNEYS,
        LINE_JOURNEYS,
        NETWORK_JOURNEYS
    };

    for (int i = 0; i < 3; i++)
    {
        int journeys = journeyCounts[i];

        double doubleTotal = journeys * FARE_RUPEES;
        long long longTotal =
            static_cast<long long>(journeys) * FARE_WHOLE_RUPEES;

        cout << "Journeys: " << journeys << '\n';
        cout << "Double total: Rs " << doubleTotal << '\n';
        cout << "Long long total using Rs 10: Rs "
             << longTotal << '\n';
        cout << "------------------------------\n";
    }

    long long networkTotal =
        static_cast<long long>(NETWORK_JOURNEYS)
        * FARE_WHOLE_RUPEES;

    int intTotal = NETWORK_JOURNEYS * FARE_WHOLE_RUPEES;

    cout << "\n===== INTEGER RANGE CHECK =====\n";
    cout << "Maximum int value: " << INT_MAX << '\n';
    cout << "Network total using int: Rs "
         << intTotal << '\n';
    cout << "Network total using long long: Rs "
         << networkTotal << '\n';

    cout << "\n===== FLOATING-POINT CHECK =====\n";
    double repeatedTotal = 0.0;

    for (int i = 0; i < 1000; i++)
    {
        repeatedTotal += FARE_RUPEES;
    }

    double directTotal = 1000 * FARE_RUPEES;

    cout << "Repeated addition: Rs " << repeatedTotal << '\n';
    cout << "Direct multiplication: Rs " << directTotal << '\n';
    cout << "Difference: Rs "
         << (repeatedTotal - directTotal) << '\n';

    return 0;
}

