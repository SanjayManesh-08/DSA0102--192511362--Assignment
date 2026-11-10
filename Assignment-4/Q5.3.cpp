#include <iostream>
using namespace std;

class Cart {
    double total;

public:
    Cart(double t) {
        total = t;
    }

    double getTotal() const {
        return total;
    }

    void display() const {
        cout << "Cart Total: Rs. " << total << endl;
    }
};

int main() {
    Cart c1(500);
    Cart c2(1200);
    Cart c3(800);

    Cart* carts[3] = {&c1, &c2, &c3};

    int highest = 0;

    cout << "Customer Cart Details" << endl;

    for (int i = 0; i < 3; i++) {
        carts[i]->display();

        if (carts[i]->getTotal() >
            carts[highest]->getTotal()) {
            highest = i;
        }
    }

    cout << "\nHighest Cart Total: Rs. "
         << carts[highest]->getTotal() << endl;

    cout << "Cart Number: " << highest + 1 << endl;

    return 0;
}
