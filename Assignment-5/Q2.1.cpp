
#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;

    void show() const {
        cout << total() << " ";
    }

    virtual ~Bill() {
        cout << "~Bill ";
    }
};

class OPBill : public Bill {
public:
    double total() const override {
        return 500;
    }

    ~OPBill() override {
        cout << "~OPBill ";
    }
};

int main() {
    Bill* b = new OPBill;

    b->show();

    delete b;

    cout << endl;

    return 0;
}

