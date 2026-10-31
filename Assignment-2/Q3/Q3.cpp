#include <iostream>
#include <iomanip>
using namespace std;

class Parcel {
public:
    double weightKg;
    bool express;
    bool insured;

    Parcel(double w, bool e, bool i) {
        weightKg = w;
        express = e;
        insured = i;
    }
};

// Weight given in grams
double charge(int weightGrams, bool express = false, bool insured = false) {
    double weightKg = weightGrams / 1000.0;
    double amount = weightKg * 100;

    if (express)
        amount += 50;
    if (insured)
        amount += 30;

    cout << "Integer overload (grams): ";
    return amount;
}

// Weight given in kilograms
double charge(double weightKg, bool express = false, bool insured = false) {
    double amount = weightKg * 100;

    if (express)
        amount += 50;
    if (insured)
        amount += 30;

    cout << "Double overload (kg): ";
    return amount;
}

// Parcel object overload
double charge(const Parcel& p) {
    double amount = p.weightKg * 100;

    if (p.express)
        amount += 50;
    if (p.insured)
        amount += 30;

    cout << "Parcel object overload: ";
    return amount;
}

int main() {
    cout << fixed << setprecision(2);

    cout << "Charge 1: Rs. " << charge(2000) << endl;
    cout << "Charge 2: Rs. " << charge(2.0f) << endl;
    cout << "Charge 3: Rs. " << charge(2.0) << endl;
    cout << "Charge 4: Rs. " << charge(3000, true) << endl;
    cout << "Charge 5: Rs. " << charge(3.0, true, true) << endl;

    Parcel p(4.0, false, true);
    cout << "Charge 6: Rs. " << charge(p) << endl;

    return 0;
}

