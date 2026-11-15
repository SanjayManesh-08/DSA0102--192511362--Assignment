
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Bill class
class Bill {
    string billType;
    double amount;

public:
    Bill(string type, double total) {
        billType = type;
        amount = total;
    }

    string type() const {
        return billType;
    }

    double total() const {
        return amount;
    }
};

// Abstract Payer class
class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;

    virtual string name() const = 0;

    virtual ~Payer() {
    }
};

// SelfPay class
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }

    string name() const override {
        return "SelfPay";
    }
};

// Insurance class
class Insurance : public Payer {
    double coverLimit;
    double copayment;

public:
    Insurance(double limit, double co)
        : coverLimit(limit), copayment(co) {
    }

    double amountCovered(const Bill& b) const override {
        double eligible = b.total();

        if (eligible > coverLimit) {
            eligible = coverLimit;
        }

        return eligible * (100 - copayment) / 100;
    }

    string name() const override {
        return "Insurance";
    }
};

// Government Scheme class
class GovernmentScheme : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        double package = 0;

        if (b.type() == "OP")
            package = 1500;
        else if (b.type() == "IP")
            package = 45000;
        else if (b.type() == "DayCare")
            package = 12000;
        else if (b.type() == "Emergency")
            package = 3500;

        if (package > b.total()) {
            package = b.total();
        }

        return package;
    }

    string name() const override {
        return "Government Scheme";
    }
};

// New payer added through inheritance
class CorporatePayer : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        double amount = b.total() * 0.90;

        if (amount > 60000) {
            amount = 60000;
        }

        return amount;
    }

    string name() const override {
        return "Corporate Payer";
    }
};

int main() {

    Bill bills[] = {
        Bill("OP", 1700),
        Bill("IP", 52500),
        Bill("DayCare", 15000),
        Bill("Emergency", 4000)
    };

    SelfPay self;
    Insurance insurance(50000, 20);
    GovernmentScheme government;
    CorporatePayer corporate;

    Payer* payers[] = {
        &self, &insurance, &government, &corporate
    };

    cout << fixed << setprecision(2);

    cout << "HOSPITAL PAYER DETAILS" << endl;

    for (int i = 0; i < 4; i++) {

        cout << "\nBill Type: " << bills[i].type() << endl;
        cout << "Bill Amount: Rs. "
             << bills[i].total() << endl;

        for (int j = 0; j < 4; j++) {
            cout << payers[j]->name()
                 << " Covers: Rs. "
                 << payers[j]->amountCovered(bills[i])
                 << endl;
        }
    }

    return 0;
}

