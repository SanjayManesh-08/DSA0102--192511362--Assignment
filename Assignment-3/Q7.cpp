
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Real-only constructor
    Complex(double r) {
        real = r;
        imag = 0;
    }

    // Parameterized constructor
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Addition operator
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction operator
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication operator
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division operator
    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw runtime_error("Division by zero complex number");
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality operator
    bool operator==(const Complex& c) const {
        const double epsilon = 1e-9;

        return fabs(real - c.real) < epsilon &&
               fabs(imag - c.imag) < epsilon;
    }

    // Magnitude calculation
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0) {
            out << " + " << c.imag << "i";
        }
        else {
            out << " - " << -c.imag << "i";
        }

        return out;
    }
};

int main() {
    try {
        // Complex number operations
        Complex a(5, 3);
        Complex b(2, 4);

        cout << "COMPLEX NUMBER OPERATIONS" << endl;

        cout << "First Number: " << a << endl;
        cout << "Second Number: " << b << endl;

        cout << "Addition: " << a + b << endl;
        cout << "Subtraction: " << a - b << endl;
        cout << "Multiplication: " << a * b << endl;
        cout << "Division: " << a / b << endl;

        cout << "Magnitude: " << a.magnitude() << endl;

        cout << boolalpha;
        cout << "Equality: " << (a == b) << endl;

        // RLC circuit parameters
        double R = 10.0;
        double L = 0.1;
        double C = 0.001;
        double f = 50.0;

        const double PI = acos(-1.0);
        double omega = 2 * PI * f;

        // Individual impedances
        Complex ZR(R, 0);
        Complex ZL(0, omega * L);
        Complex ZC(0, -1.0 / (omega * C));

        cout << "\nRLC CIRCUIT ANALYSIS" << endl;

        cout << "Resistance Impedance: " << ZR << endl;
        cout << "Inductor Impedance: " << ZL << endl;
        cout << "Capacitor Impedance: " << ZC << endl;

        // Series impedance
        Complex Zseries = ZR + ZL + ZC;

        cout << "\nSeries Impedance: "
             << Zseries << endl;

        cout << "Series Impedance Magnitude: "
             << Zseries.magnitude() << " Ohms" << endl;

        // Parallel impedance
        Complex one(1, 0);

        Complex Zparallel = one /
            (one / ZR + one / ZL + one / ZC);

        cout << "\nParallel Impedance: "
             << Zparallel << endl;

        cout << "Parallel Impedance Magnitude: "
             << Zparallel.magnitude() << " Ohms" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

