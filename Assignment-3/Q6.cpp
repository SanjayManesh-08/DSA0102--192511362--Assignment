
#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Deep-copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* newData = new char[strlen(other.data) + 1];
            strcpy(newData, other.data);

            delete[] data;
            data = newData;
        }

        return *this;
    }

    // Addition operator
    Text operator+(const Text& other) const {
        int length = strlen(data) + strlen(other.data);

        char* temp = new char[length + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);

        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Inequality operator
    bool operator!=(const Text& other) const {
        return strcmp(data, other.data) != 0;
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }
};

int main() {
    Text a("Hello ");
    Text b("World");

    // Concatenation
    Text c = a + b;

    cout << "First Text: " << a << endl;
    cout << "Second Text: " << b << endl;
    cout << "Combined Text: " << c << endl;

    // Equality comparison
    Text d("Hello ");

    cout << boolalpha;
    cout << "a == d: " << (a == d) << endl;
    cout << "a != b: " << (a != b) << endl;

    // Copy constructor test
    Text e = c;
    cout << "Copied Text: " << e << endl;

    // Assignment operator test
    Text f("Temporary");
    f = c;

    cout << "Assigned Text: " << f << endl;

    // Self-assignment test
    f = f;

    cout << "After Self Assignment: " << f << endl;

    return 0;
}

