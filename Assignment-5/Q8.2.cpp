
#include <iostream>
#include <chrono>
#include <stdexcept>
#include <iomanip>
using namespace std;
using namespace chrono;

// Exception-based validation
bool validateException(double amount) {
    if (amount < 0)
        throw invalid_argument("Invalid amount");

    return true;
}

// Return-code validation
bool validateReturnCode(double amount) {
    if (amount < 0)
        return false;

    return true;
}

volatile long long resultCount = 0;

void compareMethods(int n, int invalidCount) {
    long long exceptionValid = 0;
    long long returnValid = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        double amount = (i < invalidCount) ? -100 : 500;

        try {
            if (validateException(amount))
                exceptionValid++;
        }
        catch (const invalid_argument&) {
            // Invalid claim handled
        }
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        double amount = (i < invalidCount) ? -100 : 500;

        if (validateReturnCode(amount))
            returnValid++;
    }

    auto end2 = high_resolution_clock::now();

    resultCount = exceptionValid + returnValid;

    double exceptionTime =
        duration<double, milli>(end1 - start1).count();

    double returnTime =
        duration<double, milli>(end2 - start2).count();

    cout << "Invalid claims: "
         << (invalidCount * 100.0 / n) << "%\n";

    cout << "Exception time: "
         << exceptionTime << " ms\n";

    cout << "Return code time: "
         << returnTime << " ms\n";

    cout << "Valid claims match: "
         << (exceptionValid == returnValid ? "Yes" : "No")
         << "\n\n";
}

int main() {
    cout << fixed << setprecision(3);

    int n = 1000000;

    cout << "EXCEPTION VS RETURN CODE COMPARISON\n\n";

    compareMethods(n, 0);
    compareMethods(n, 10000);
    compareMethods(n, 500000);

    return 0;
}

