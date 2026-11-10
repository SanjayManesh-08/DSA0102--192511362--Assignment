#include <iostream>
using namespace std;

class Account {
public:
    Account() {
        cout << "Account constructor" << endl;
    }

    virtual ~Account() {
        cout << "Account destructor" << endl;
    }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() {
        history = new double[100];
        cout << "SeniorAccount constructor" << endl;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destructor" << endl;
    }
};

int main() {
    Account* p = new SeniorAccount();

    delete p;

    return 0;
}
