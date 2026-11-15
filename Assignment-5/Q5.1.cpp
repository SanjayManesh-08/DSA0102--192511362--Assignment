
#include <iostream>
using namespace std;

class Guard {
    string name;

public:
    Guard(string n) {
        name = n;
    }

    ~Guard() {
        cout << "~" << name << " ";
    }
};

int main() {
    try {
        Guard m("main");

        {
            Guard g("f");
            throw 42;

            cout << "not printed ";
        }
    }
    catch (int value) {
        cout << "caught " << value;
    }

    cout << endl;
    return 0;
}

