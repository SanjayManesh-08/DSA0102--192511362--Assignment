
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    // Constructor
    Money(long long rupees = 0, int p = 0) {
        paise = rupees * 100 + p;
    }

    // Addition operator
    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }

    // Subtraction operator
    Money operator-(const Money& other) const {
        Money result;
        result.paise = paise - other.paise;
        return result;
    }

    // Compound addition operator
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    // Equality operator
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    // Less-than operator
    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long rupees = m.paise / 100;
        long long remainingPaise = m.paise % 100;

        if (remainingPaise < 0) {
            remainingPaise = -remainingPaise;
        }

        out << "Rs " << rupees << "."
            << setw(2) << setfill('0') << remainingPaise
            << setfill(' ');

        return out;
    }

    // Stream extraction operator
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;

        cout << "Enter rupees: ";
        in >> rupees;

        cout << "Enter paise: ";
        in >> p;

        if (in && (p < 0 || p >= 100)) {
            in.setstate(ios::failbit);
            return in;
        }

        m.paise = rupees * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << "First Amount: " << a << endl;
    cout << "Second Amount: " << b << endl;

    cout << "\nAddition: " << c << endl;
    cout << "Subtraction: " << a - b << endl;

    a += b;
    cout << "After += operation: " << a << endl;

    cout << boolalpha;
    cout << "Equality: " << (a == c) << endl;
    cout << "Less Than: " << (b < c) << endl;

    Money d;
    cout << "\nEnter another amount:\n";
    if (cin >> d) {
        cout << "Entered Amount: " << d << endl;
    }
    else {
        cout << "Invalid monetary input." << endl;
    }

    return 0;
}

