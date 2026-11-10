
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual double calculateCharge(int days) const = 0;

    virtual ~Vehicle() {
    }
};

class Bicycle : public Vehicle {
public:
    double calculateCharge(int days) const override {
        return 100 * days;
    }
};

class Car : public Vehicle {
public:
    double calculateCharge(int days) const override {
        return 1000 * days;
    }
};

int main() {
    Bicycle b;
    Car c;

    Vehicle* v[2] = {&b, &c};

    cout << "Bicycle Charge: Rs. "
         << v[0]->calculateCharge(2) << endl;

    cout << "Car Charge: Rs. "
         << v[1]->calculateCharge(2) << endl;

    return 0;
}

