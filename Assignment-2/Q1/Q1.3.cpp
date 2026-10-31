
#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyConcession(long long &fee, int percent) {
    // TODO 1: Update the original fee using call by reference
    fee -= fee * percent / 100;
}

int main() {
    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);

    cout << "after call by value : "
         << hostelFee << '\n';

    applyConcession(hostelFee, 10);

    cout << "after call by reference: "
         << hostelFee << '\n';

    return 0;
}

