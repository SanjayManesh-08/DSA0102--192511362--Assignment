
#include <iostream>
using namespace std;

class Bill {
public:
    void display() const {
        cout << "Base Bill" << endl;
    }

    virtual void print() const {
        cout << "Base Print" << endl;
    }

    virtual ~Bill() {
    }
};

class OPBill : public Bill {
public:
    void display() const {
        cout << "OutPatient Bill" << endl;
    }

    void print() const override {
        cout << "OutPatient Print" << endl;
    }
};

int main() {
    OPBill obj;
    Bill* b = &obj;

    b->display();
    b->print();

    return 0;
}

