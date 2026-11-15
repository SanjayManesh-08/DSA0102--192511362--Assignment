
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

// Abstract Bill class
class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() {}
};

class OutPatient : public Bill {
public:
    double total() const override {
        return 500 + 1200;
    }
};

class InPatient : public Bill {
public:
    double total() const override {
        return 3 * 2500 + 40000 + 5000;
    }
};

class DayCare : public Bill {
public:
    double total() const override {
        return 15000;
    }
};

class Emergency : public Bill {
public:
    double total() const override {
        return 2000 + 4 * 500;
    }
};

// Data for switch implementation
struct BillData {
    int type;
    double a, b, c;
};

double switchTotal(const BillData& bill) {
    switch (bill.type) {
        case 0:
            return bill.a + bill.b;

        case 1:
            return bill.a * bill.b + bill.c + 5000;

        case 2:
            return bill.a;

        case 3:
            return bill.a + bill.b * bill.c;

        default:
            return 0;
    }
}

volatile double result = 0;

// Benchmark function
void benchmark(int n, Bill* bills[],
               BillData data[]) {
    double sum1 = 0, sum2 = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        sum1 += bills[i % 4]->total();
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        sum2 += switchTotal(data[i % 4]);
    }

    auto end2 = high_resolution_clock::now();

    result = sum1 + sum2;

    double virtualTime =
        duration<double, milli>(end1 - start1).count();

    double switchTime =
        duration<double, milli>(end2 - start2).count();

    cout << n << " bills\n";
    cout << "Virtual function: " << virtualTime << " ms\n";
    cout << "Switch statement: " << switchTime << " ms\n";
    cout << "Totals match: "
         << (sum1 == sum2 ? "Yes" : "No") << "\n\n";
}

int main() {
    cout << fixed << setprecision(3);

    OutPatient op;
    InPatient ip;
    DayCare dc;
    Emergency em;

    Bill* bills[4] = {&op, &ip, &dc, &em};

    BillData data[4] = {
        {0, 500, 1200, 0},
        {1, 3, 2500, 40000},
        {2, 15000, 0, 0},
        {3, 2000, 4, 500}
    };

    cout << "VIRTUAL VS SWITCH COMPARISON\n\n";

    benchmark(1000, bills, data);
    benchmark(1000000, bills, data);
    benchmark(10000000, bills, data);

    return 0;
}

