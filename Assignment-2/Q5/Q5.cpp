
#include <iostream>
#include <string>
using namespace std;

class BusTicket {
private:
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    BusTicket(string passengerName) {
        name = passengerName;

        if (issued < CAPACITY) {
            issued++;
            seat = issued;
        } else {
            seat = 0;
        }
    }

    void display() const {
        cout << name << " : ";

        if (seat == 0)
            cout << "Waiting List" << endl;
        else
            cout << "Seat " << seat << endl;
    }

    static int count() {
        return issued;
    }
};

// Definition of static data member
int BusTicket::issued = 0;

int main() {
    BusTicket passengers[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++) {
        passengers[i].display();
    }

    cout << "Total Tickets Issued: "
         << BusTicket::count() << endl;

    return 0;
}

