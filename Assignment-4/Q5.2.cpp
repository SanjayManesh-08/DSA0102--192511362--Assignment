#include <iostream>
using namespace std;

class Cart {
public:
    int total;

    Cart(int t) {
        total = t;
    }

    void display() {
        cout << "Total: " << total << endl;
    }
};

int main() {
    Cart c1(500);

    // Direct object access
    c1.display();

    // Pointer access
    Cart* p = &c1;
    p->display();

    // Reference access
    Cart& r = c1;
    r.display();

    // Dynamic object creation
    Cart* p2 = new Cart(1000);
    p2->display();

    delete p2;

    return 0;
}
