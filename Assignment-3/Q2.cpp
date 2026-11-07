
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class Prescription {
    int n;
    string* medicines;

    static int copiesMade;

public:
    // Parameterized constructor
    explicit Prescription(int count) {
        n = count;
        medicines = new string[n];
    }

    // Deep-copy constructor
    Prescription(const Prescription& other) {
        n = other.n;
        medicines = new string[n];

        for (int i = 0; i < n; i++) {
            medicines[i] = other.medicines[i];
        }

        copiesMade++;
        cout << "Copy constructor called" << endl;
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* newMedicines = new string[other.n];

            for (int i = 0; i < other.n; i++) {
                newMedicines[i] = other.medicines[i];
            }

            delete[] medicines;

            medicines = newMedicines;
            n = other.n;
        }

        return *this;
    }

    // Destructor
    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const string& medicine) {
        if (i >= 0 && i < n) {
            medicines[i] = medicine;
        }
    }

    string get(int i) const {
        if (i >= 0 && i < n) {
            return medicines[i];
        }
        return "";
    }

    static void resetCopies() {
        copiesMade = 0;
    }

    static int getCopies() {
        return copiesMade;
    }
};

int Prescription::copiesMade = 0;

// Function receiving object by value
void displayByValue(Prescription p) {
    cout << "Function received object by value." << endl;
}

// Function receiving object by constant reference
void displayByReference(const Prescription& p) {
    cout << "Function received object by reference." << endl;
}

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    // Deep copy using copy constructor
    Prescription q = p;

    q.set(1, "Cetirizine");

    // Deep copy using assignment operator
    Prescription r(1);
    r = p;

    p.set(0, "Ibuprofen");

    cout << "\nPrescription details:" << endl;

    cout << "P: " << p.get(0) << " " << p.get(1) << endl;
    cout << "Q: " << q.get(0) << " " << q.get(1) << endl;
    cout << "R: " << r.get(0) << " " << r.get(1) << endl;

    // Self-assignment test
    p = p;
    cout << "\nSelf-assignment test: " << p.get(0) << endl;

    // Copy count experiment
    Prescription::resetCopies();

    displayByValue(p);
    cout << "Copies after pass by value: "
         << Prescription::getCopies() << endl;

    Prescription::resetCopies();

    displayByReference(p);
    cout << "Copies after pass by reference: "
         << Prescription::getCopies() << endl;

    return 0;
}

