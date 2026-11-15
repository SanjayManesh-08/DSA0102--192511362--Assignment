
#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Abstract Bill class
class Bill {
protected:
    string patient;

public:
    Bill(string p) {
        patient = p;
    }

    virtual double total() const = 0;
    virtual string type() const = 0;

    string getPatient() const {
        return patient;
    }

    virtual ~Bill() {}
};

// Existing outpatient bill
class OutPatientBill : public Bill {
    double consultation;
    double tests;

public:
    OutPatientBill(string p, double c, double t)
        : Bill(p) {
        consultation = c;
        tests = t;
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "Outpatient";
    }
};

// Existing inpatient bill
class InPatientBill : public Bill {
    int days;
    double roomCharge;
    double procedures;

public:
    InPatientBill(string p, int d,
                  double r, double proc)
        : Bill(p) {
        days = d;
        roomCharge = r;
        procedures = proc;
    }

    double total() const override {
        return days * roomCharge + procedures;
    }

    string type() const override {
        return "Inpatient";
    }
};

// NEW BILL TYPE: Diagnostic Bill
class DiagnosticBill : public Bill {
    double scanCharge;
    double labCharge;

public:
    DiagnosticBill(string p, double scan, double lab)
        : Bill(p) {
        scanCharge = scan;
        labCharge = lab;
    }

    double total() const override {
        return scanCharge + labCharge;
    }

    string type() const override {
        return "Diagnostic";
    }
};

// Abstract Payer class
class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual string name() const = 0;

    virtual ~Payer() {}
};

// Existing self payer
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }

    string name() const override {
        return "Self Pay";
    }
};

// Existing insurance payer
class Insurance : public Payer {
    double limit;

public:
    Insurance(double l) {
        limit = l;
    }

    double amountCovered(const Bill& b) const override {
        double amount = b.total();

        if (amount > limit)
            amount = limit;

        return amount;
    }

    string name() const override {
        return "Insurance";
    }
};

// NEW PAYER TYPE: Senior Citizen Scheme
class SeniorCitizenScheme : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        double amount = b.total() * 0.80;

        if (amount > 30000)
            amount = 30000;

        return amount;
    }

    string name() const override {
        return "Senior Citizen Scheme";
    }
};

int main() {
    cout << fixed << setprecision(2);

    // Creating bill objects using smart pointers
    unique_ptr<Bill> bills[3];

    bills[0] = unique_ptr<Bill>(
        new OutPatientBill("Ravi", 500, 1200));

    bills[1] = unique_ptr<Bill>(
        new InPatientBill("Meena", 3, 2500, 40000));

    // New bill type
    bills[2] = unique_ptr<Bill>(
        new DiagnosticBill("Arun", 5000, 3000));

    // Creating payer objects
    SelfPay self;
    Insurance insurance(50000);
    SeniorCitizenScheme senior;

    Payer* payers[3] = {
        &self, &insurance, &senior
    };

    cout << "HOSPITAL BILLING SYSTEM\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "Patient: "
             << bills[i]->getPatient() << endl;

        cout << "Bill Type: "
             << bills[i]->type() << endl;

        cout << "Total Bill: Rs. "
             << bills[i]->total() << endl;

        for (int j = 0; j < 3; j++) {
            cout << payers[j]->name()
                 << " Covers: Rs. "
                 << payers[j]->amountCovered(*bills[i])
                 << endl;
        }

        cout << "--------------------------\n";
    }

    return 0;
}

