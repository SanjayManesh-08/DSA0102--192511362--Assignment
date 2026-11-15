
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BillingError : public runtime_error {
public:
    BillingError(string message) : runtime_error(message) {}
};

class InvalidChargeError : public BillingError {
public:
    InvalidChargeError(string message) : BillingError(message) {}
};

class ClaimError : public BillingError {
public:
    ClaimError(string message) : BillingError(message) {}
};

class UnknownPackageError : public BillingError {
public:
    UnknownPackageError(string message) : BillingError(message) {}
};

class PatientNotFoundError : public BillingError {
public:
    PatientNotFoundError(string message) : BillingError(message) {}
};

void validateCharge(double amount) {
    if (amount < 0)
        throw InvalidChargeError("Negative billing amount");
    cout << "Charge is valid" << endl;
}

void approveClaim(double bill, double cover) {
    if (bill < 0 || cover < 0)
        throw InvalidChargeError("Invalid amount");

    if (bill > cover)
        throw ClaimError("Claim exceeds insurance cover");

    cout << "Claim approved" << endl;
}

double packageRate(string package) {
    if (package == "OP")
        return 1500;
    else if (package == "IP")
        return 45000;
    else
        throw UnknownPackageError("Unknown package");
}

void findPatient(int id) {
    if (id != 101)
        throw PatientNotFoundError("Patient record not found");

    cout << "Patient record found" << endl;
}

int main() {
    try {
        validateCharge(500);
        approveClaim(40000, 50000);
        cout << "Package rate: Rs. "
             << packageRate("OP") << endl;
        findPatient(101);
    }
    catch (const InvalidChargeError& e) {
        cout << "Invalid Charge: " << e.what() << endl;
    }
    catch (const ClaimError& e) {
        cout << "Claim Error: " << e.what() << endl;
    }
    catch (const UnknownPackageError& e) {
        cout << "Package Error: " << e.what() << endl;
    }
    catch (const PatientNotFoundError& e) {
        cout << "Patient Error: " << e.what() << endl;
    }
    catch (const bad_alloc& e) {
        cout << "Memory Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "General Error: " << e.what() << endl;
    }

    return 0;
}

