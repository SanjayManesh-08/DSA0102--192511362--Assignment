#include <iostream>
using namespace std;

class Account {
public:
    double rate() const {
        return 3.5;
    }

    virtual double vrate() const {
        return 3.5;
    }

    virtual ~Account() {}
};

class SeniorAccount : public Account {
public:
    double rate() const {
        return 4.0;
    }

    double vrate() const override {
        return 4.0;
    }
};

int main() {
    SeniorAccount s;
    Account* p = &s;

    Account copy = s;

    cout << p->rate() << " ";
    cout << p->vrate() << " ";
    cout << copy.vrate() << endl;

    return 0;
}
