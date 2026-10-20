
#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
    // 1. Display data type sizes
    cout << "===== DATA TYPE SIZES =====" << endl;
    cout << "sizeof(bool): " << sizeof(bool) << " byte(s)" << endl;
    cout << "sizeof(char): " << sizeof(char) << " byte(s)" << endl;
    cout << "sizeof(int): " << sizeof(int) << " byte(s)" << endl;
    cout << "sizeof(unsigned int): " << sizeof(unsigned int) << " byte(s)" << endl;
    cout << "sizeof(long long): " << sizeof(long long) << " byte(s)" << endl;
    cout << "sizeof(float): " << sizeof(float) << " byte(s)" << endl;
    cout << "sizeof(double): " << sizeof(double) << " byte(s)" << endl;

    auto journeyCount = 3000000;
    auto exampleFare = 30.0;

    cout << "\n===== AUTO TYPE =====" << endl;
    cout << "Journey count: " << journeyCount << endl;
    cout << "Example fare: Rs " << exampleFare << endl;

    // 2. Display integer and floating-point limits
    cout << "\n===== TYPE LIMITS =====" << endl;
    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "UINT_MAX: " << UINT_MAX << endl;
    cout << "LLONG_MIN: " << LLONG_MIN << endl;
    cout << "LLONG_MAX: " << LLONG_MAX << endl;
    cout << "FLT_MAX: " << FLT_MAX << endl;
    cout << "DBL_MAX: " << DBL_MAX << endl;

    // 3. Example metro data types, with fares in rupees
    cout << "\n===== METRO DATA TYPES =====" << endl;
    bool peakHour = true;
    char zoneCode = 'O';
    int hour = 9;
    long long cardBalance = 500;
    unsigned int stationJourneys = 20000;
    double fare = 10.50;

    cout << boolalpha;
    cout << "Peak hour: " << peakHour << endl;
    cout << "Zone code: " << zoneCode << endl;
    cout << "Journey hour: " << hour << endl;
    cout << "Card balance: Rs " << cardBalance << endl;
    cout << "Station journeys: " << stationJourneys << endl;
    cout << "Example fare: Rs " << fare << endl;

    // 4. Type compatibility
    cout << "\n===== TYPE COMPATIBILITY =====" << endl;
    int a = 7;
    int b = 2;

    double result1 = a / b;
    double result2 = static_cast<double>(a) / b;
    bool flag = 5;

    cout << "Integer division stored in double: "
         << result1 << endl;
    cout << "Division after conversion to double: "
         << result2 << endl;
    cout << "Boolean created from integer 5: "
         << flag << endl;

    // 5. Daily network collection using rupees
    cout << "\n===== DAILY COLLECTION CHECK =====" << endl;

    long long journeys = 3000000LL;
    long long fareInRupees = 30LL;
    long long dailyCollection = journeys * fareInRupees;

    cout << "Journeys per day: " << journeys << endl;
    cout << "Fare per journey: Rs " << fareInRupees << endl;
    cout << "Daily collection: Rs " << dailyCollection << endl;
    cout << "INT_MAX: " << INT_MAX << endl;

    if (dailyCollection > INT_MAX) {
        cout << "int is NOT sufficient for this total." << endl;
    } else {
        cout << "int is sufficient for this total." << endl;
    }

    cout << "long long is used for the large total." << endl;

    // 6. Compare double rupees with repeated additions
    cout << "\n===== ROUNDING ERROR EXPERIMENT =====" << endl;
    cout << fixed << setprecision(15);

    int testCounts[] = {20000, 500000, 3000000};

    for (int i = 0; i < 3; i++) {
        int n = testCounts[i];
        double doubleTotal = 0.0;
        double exactReferenceTotal = 0.0;

        for (int j = 0; j < n; j++) {
            doubleTotal += 10.01;
            exactReferenceTotal += 10.01;
        }

        
        double reference = n * 10.01;
        double difference = doubleTotal - reference;

        cout << "Journeys: " << n << endl;
        cout << "Repeated addition total: Rs " << doubleTotal << endl;
        cout << "Multiplication reference: Rs " << reference << endl;
        cout << "Measured difference: Rs " << difference << endl;
    }

    return 0;
}

