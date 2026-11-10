
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

// Base class
class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) {
        name = n;
        id = i;
    }

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Pay: Rs " << fixed << setprecision(2)
             << pay() << endl;
        cout << "----------------------" << endl;
    }

    virtual ~Staff() {}
};

// Derived class: Professor
class Professor : public Staff {
private:
    double basic;
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i) {
        basic = b;
        research = r;
    }

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

// Derived class: Lab Assistant
class LabAssistant : public Staff {
private:
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i) {
        basic = b;
    }

    double pay() const override {
        return basic + basic * 0.42;
    }
};

// Derived class: Guest Faculty
class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i) {
        hours = h;
        rate = r;
    }

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    vector<unique_ptr<Staff>> staff;

    // Creating objects without make_unique()
    staff.push_back(
        unique_ptr<Staff>(new Professor("Arun", 101, 50000, 10000))
    );

    staff.push_back(
        unique_ptr<Staff>(new LabAssistant("Kumar", 102, 30000))
    );

    staff.push_back(
        unique_ptr<Staff>(new GuestFaculty("Meena", 103, 40, 500))
    );

    cout << "COLLEGE PAYROLL DETAILS" << endl;
    cout << endl;

    for (const auto& s : staff) {
        s->display();
    }

    return 0;
}

