
#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <new>
using namespace std;

class ClaimError : public runtime_error {
public:
    ClaimError(string message) : runtime_error(message) {}
};

class UnknownPackageError : public runtime_error {
public:
    UnknownPackageError(string message) : runtime_error(message) {}
};

class Guard {
public:
    ~Guard() noexcept {
        cout << "Destructor called" << endl;
    }
};

void validateAmount(double amount) {
    if (amount < 0)
        throw invalid_argument("negative amount");
}

double approve(double billed, double cover) {
    validateAmount(billed);
    validateAmount(cover);

    if (billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double getPackageRate(string package) {
    if (package == "OP")
        return 1500;
    else if (package == "IP")
        return 45000;
    else
        throw UnknownPackageError("unknown package");
}

void settle(double billed, double cover) {
    try {
        double approved = approve(billed, cover);
        cout << "approved " << approved << endl;
    }
    catch (const ClaimError& e) {
        cout << "audit: " << e.what() << endl;
        throw;
    }
}

int main() {
    Guard g;

    // Valid claim
    try {
        settle(40000, 50000);
    }
    catch (const ClaimError& e) {
        cout << "claim rejected: " << e.what() << endl;
    }

    // Claim exceeds insurance cover
    try {
        settle(60000, 50000);
    }
    catch (const ClaimError& e) {
        cout << "claim rejected: " << e.what() << endl;
    }

    // Negative amount
    try {
        settle(-1, 50000);
    }
    catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    // Unknown package
    try {
        cout << "Package rate: "
             << getPackageRate("XYZ") << endl;
    }
    catch (const UnknownPackageError& e) {
        cout << "Package error: " << e.what() << endl;
    }

    // Text instead of a number
    try {
        double amount = stod("abc");
        cout << amount << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Input error: invalid number" << endl;
    }

    // Demonstrating allocation failure
    try {
        int* data = new int[numeric_limits<size_t>::max()];
        delete[] data;
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed" << endl;
    }

    return 0;
}

