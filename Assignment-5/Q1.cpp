
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Bill {
protected:
    string patient;
    int billId;

public:
    Bill(string p, int id) {
        patient = p;
        billId = id;
    }

    virtual double total() const = 0;

    virtual string type() const = 0;

    virtual void print() const {
        cout << type() << " Bill" << endl;
        cout << "Patient: " << patient << endl;
        cout << "Bill ID: " << billId << endl;
        cout << "Total: Rs. " << total() << endl;
    }

    virtual ~Bill() {
    }
};

// Out-Patient Bill
class OutPatientBill : public Bill {
    double consultation;
    double tests;

public:
    OutPatientBill(string p, int id,
                   double c, double t)
        : Bill(p, id), consultation(c), tests(t) {
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "Out-Patient";
    }
};

// In-Patient Bill
class InPatientBill : public Bill {
    int days;
    double perDay;
    double procedures;
    double medicines;

public:
    InPatientBill(string p, int id, int d,
                  double rate, double proc,
                  double med)
        : Bill(p, id), days(d), perDay(rate),
          procedures(proc), medicines(med) {
    }

    double total() const override {
        return days * perDay + procedures + medicines;
    }

    string type() const override {
        return "In-Patient";
    }
};

// Day-Care Bill
class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(string p, int id, double price)
        : Bill(p, id), packagePrice(price) {
    }

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "Day-Care";
    }
};

// Emergency Bill
class EmergencyBill : public Bill {
    double baseCharge;
    int hours;
    double hourlyCharge;

public:
    EmergencyBill(string p, int id,
                  double base, int h,
                  double hourly)
        : Bill(p, id), baseCharge(base),
          hours(h), hourlyCharge(hourly) {
    }

    double total() const override {
        return baseCharge + hours * hourlyCharge;
    }

    string type() const override {
        return "Emergency";
    }
};

int main() {

    Bill* bills[4];

    bills[0] = new OutPatientBill(
        "Ravi", 101, 500, 1200
    );

    bills[1] = new InPatientBill(
        "Meena", 102, 3, 2500, 40000, 5000
    );

    bills[2] = new DayCareBill(
        "Arun", 103, 15000
    );

    bills[3] = new EmergencyBill(
        "Kumar", 104, 2000, 4, 500
    );

    double dailyTotal = 0;

    cout << "HOSPITAL BILLING DETAILS" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "\n----------------------" << endl;

        bills[i]->print();

        dailyTotal += bills[i]->total();
    }

    cout << "\nDaily Total: Rs. "
         << dailyTotal << endl;

    for (int i = 0; i < 4; i++) {
        delete bills[i];
    }

    return 0;
}

