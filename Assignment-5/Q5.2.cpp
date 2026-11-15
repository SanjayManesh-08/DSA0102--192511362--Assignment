
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Guard {
    string name;

public:
    Guard(string n) {
        name = n;
    }

    ~Guard() noexcept {
        cout << "~" << name << " ";
    }
};

void lowLevel() {
    Guard file("file");
    throw runtime_error("Billing failed");
}

void service() {
    try {
        lowLevel();
    }
    catch (const exception& e) {
        cout << "Logged: " << e.what() << " ";
        throw;
    }
}

int main() {
    try {
        Guard mainGuard("main");
        service();
    }
    catch (const exception& e) {
        cout << "Reported: " << e.what();
    }

    cout << endl;
    return 0;
}

