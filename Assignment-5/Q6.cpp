
#include <iostream>
#include <string>
#include <iomanip>
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
        cout << "Patient: " << patient
             << "\nBill ID: " << billId
             << "\nBill Type: " << type()
             << "\nTotal: Rs. " << total() << endl;
    }

    virtual ~Bill() {}
};

// Outpatient bill
class OutPatientBill : public Bill {
    double consultation, tests;

public:
    OutPatientBill(string p, int id, double c, double t)
        : Bill(p, id) {
        consultation = c;
        tests = t;
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

// Inpatient bill
class InPatientBill : public Bill {
    int days;
    double perDay, procedures, medicines;

public:
    InPatientBill(string p, int id, int d,
                  double rate, double proc, double med)
        : Bill(p, id) {
        days = d;
        perDay = rate;
        procedures = proc;
        medicines = med;
    }

    double total() const override {
        return days * perDay + procedures + medicines;
    }

    string type() const override {
        return "IP";
    }
};

// Day-care bill
class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(string p, int id, double price)
        : Bill(p, id) {
        packagePrice = price;
    }

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "DayCare";
    }
};

// Emergency bill
class EmergencyBill : public Bill {
    double baseCharge, hours, hourlyCharge;

public:
    EmergencyBill(string p, int id, double base,
                  double h, double rate)
        : Bill(p, id) {
        baseCharge = base;
        hours = h;
        hourlyCharge = rate;
    }

    double total() const override {
        return baseCharge + hours * hourlyCharge;
    }

    string type() const override {
        return "Emergency";
    }
};

// Abstract payer class
class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual string name() const = 0;

    virtual ~Payer() {}
};

// Self payment
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }

    string name() const override {
        return "SelfPay";
    }
};

// Insurance payment
class Insurance : public Payer {
    double coverLimit;
    double copayment;

public:
    Insurance(double limit, double co) {
        coverLimit = limit;
        copayment = co;
    }

    double amountCovered(const Bill& b) const override {
        double eligible = b.total();

        if (eligible > coverLimit)
            eligible = coverLimit;

        return eligible * (100 - copayment) / 100;
    }

    string name() const override {
        return "Insurance";
    }
};

// Government scheme
class GovernmentScheme : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        double rate = 0;

        if (b.type() == "OP")
            rate = 1500;
        else if (b.type() == "IP")
            rate = 45000;
        else if (b.type() == "DayCare")
            rate = 12000;
        else if (b.type() == "Emergency")
            rate = 3500;

        if (rate > b.total())
            rate = b.total();

        return rate;
    }

    string name() const override {
        return "Government Scheme";
    }
};

// Additional corporate payer
class CorporatePayer : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        double amount = b.total() * 0.90;

        if (amount > 60000)
            amount = 60000;

        return amount;
    }

    string name() const override {
        return "Corporate Payer";
    }
};

int main() {
    cout << fixed << setprecision(2);

    // Creating different bill objects
    Bill* bills[4];

    bills[0] = new OutPatientBill("Ravi", 101, 500, 1200);
    bills[1] = new InPatientBill("Meena", 102, 3,
                                 2500, 40000, 5000);
    bills[2] = new DayCareBill("Arun", 103, 15000);
    bills[3] = new EmergencyBill("Kumar", 104,
                                 2000, 4, 500);

    // Creating payer objects
    SelfPay self;
    Insurance insurance(50000, 20);
    GovernmentScheme government;
    CorporatePayer corporate;

    Payer* payers[4] = {
        &self, &insurance, &government, &corporate
    };

    double dailyTotal = 0;

    cout << "HOSPITAL BILLING SYSTEM\n\n";

    for (int i = 0; i < 4; i++) {
        bills[i]->print();
        dailyTotal += bills[i]->total();

        cout << "\nPayer Coverage:\n";

        for (int j = 0; j < 4; j++) {
            cout << payers[j]->name()
                 << ": Rs. "
                 << payers[j]->amountCovered(*bills[i])
                 << endl;
        }

        cout << "-------------------------\n";
    }

    cout << "\nDaily Total: Rs. " << dailyTotal << endl;

    // Deleting objects through base pointers
    for (int i = 0; i < 4; i++) {
        delete bills[i];
    }

    return 0;
}

