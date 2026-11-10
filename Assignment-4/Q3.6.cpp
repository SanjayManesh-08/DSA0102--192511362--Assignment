
#include <iostream>
using namespace std;

class Test {
    int first;
    int second;

public:
    Test() : second(20), first(10) {
        cout << first << " " << second << '\n';
    }
};

int main() {
    Test t;
    return 0;
}

