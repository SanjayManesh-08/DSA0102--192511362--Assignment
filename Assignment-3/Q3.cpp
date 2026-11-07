
#include <iostream>
using namespace std;

class Auditorium {
    int rows, seats;
    char** seatMap;

public:
    // Constructor
    Auditorium(int r, int s) {
        rows = r;
        seats = s;

        seatMap = new char*[rows];

        for (int i = 0; i < rows; i++) {
            seatMap[i] = new char[seats];

            for (int j = 0; j < seats; j++) {
                seatMap[i][j] = 'O';
            }
        }

        cout << "Auditorium created with "
             << rows << " rows and "
             << seats << " seats." << endl;
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat position." << endl;
        }
        else if (seatMap[r][s] == 'X') {
            cout << "Seat already booked." << endl;
        }
        else {
            seatMap[r][s] = 'X';
            cout << "Seat booked successfully." << endl;
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat position." << endl;
        }
        else if (seatMap[r][s] == 'O') {
            cout << "Seat is not booked." << endl;
        }
        else {
            seatMap[r][s] = 'O';
            cout << "Booking cancelled successfully." << endl;
        }
    }

    // Display seats
    void display() const {
        cout << "\nSeat Arrangement (O = Available, X = Booked):\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                cout << seatMap[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Auditorium() {
        for (int i = 0; i < rows; i++) {
            delete[] seatMap[i];
        }

        delete[] seatMap;

        cout << "Auditorium memory released." << endl;
    }
};

int main() {
    // Stack object
    Auditorium a(3, 4);

    a.bookSeat(0, 1);
    a.bookSeat(1, 2);
    a.display();

    a.cancelSeat(0, 1);
    a.display();

    // Dynamically created object
    Auditorium* b = new Auditorium(2, 3);

    b->bookSeat(0, 0);
    b->display();

    delete b;

    // Block scope example
    {
        Auditorium c(1, 2);
        c.bookSeat(0, 1);
    }

    cout << "\nEnd of program." << endl;

    return 0;
}

