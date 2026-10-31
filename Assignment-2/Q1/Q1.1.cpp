#include <iostream>
using namespace std;

void concessionByValue(long long fee, int percent) {
    fee = fee - (fee * percent / 100);
    cout << "Fee inside call by value: Rs " << fee << endl;
}

void concessionByReference(long long &fee, int percent) {
    fee = fee - (fee * percent / 100);
}

void concessionByPointer(long long *fee, int percent) {
    if (fee != nullptr) {
        *fee = *fee - (*fee * percent / 100);
    }
}

int main() {
    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    cout << "HOSTEL FEE CONCESSION SYSTEM" << endl;
    cout << "Initial Hostel Fee: Rs 45000" << endl;

    cout << "\n1. CALL BY VALUE" << endl;
    concessionByValue(fee1, 10);
    cout << "Fee after function call: Rs " << fee1 << endl;

    cout << "\n2. CALL BY REFERENCE" << endl;
    concessionByReference(fee2, 10);
    cout << "Fee after function call: Rs " << fee2 << endl;

    cout << "\n3. CALL BY POINTER" << endl;
    concessionByPointer(&fee3, 10);
    cout << "Fee after function call: Rs " << fee3 << endl;

    return 0;
}

