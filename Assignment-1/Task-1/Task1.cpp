#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
    int passengerId;
    string passengerType;
};

class Journey {
public:
    int zone;
    int hour;
};

class FareTable {
public:
    int getFare(int zone) {
        switch (zone) {
            case 1:
                return 10;  // Inner zone
            case 2:
                return 20;  // Middle zone
            case 3:
                return 30;  // Outer zone
            default:
                return 0;   // Invalid zone
        }
    }

    bool isPeakHour(int hour) {
        if ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20)) {
            return true;
        }

        return false;
    }

    int calculateFare(int zone, int hour) {
        int fare = getFare(zone);

        if (fare == 0) {
            return 0;
        }

        if (isPeakHour(hour)) {
            fare = fare + (fare * 20 / 100);
        }

        return fare;
    }
};

class SmartCard {
private:
    int cardId;
    int balance;

public:
    SmartCard(int id, int initialBalance) {
        cardId = id;
        balance = initialBalance;
    }

    int getBalance() {
        return balance;
    }

    bool canTravel(int fare) {
        if (fare <= 0) {
            return false;
        }

        if (balance - fare >= 50) {
            return true;
        }

        return false;
    }

    bool deductFare(int fare) {
        if (canTravel(fare)) {
            balance = balance - fare;
            return true;
        }

        return false;
    }
};

int main() {
    Passenger passenger;
    passenger.passengerId = 101;
    passenger.passengerType = "Regular";

    Journey journey;
    journey.zone = 3;  // 1 = Inner, 2 = Middle, 3 = Outer
    journey.hour = 9;  // 9 AM

    SmartCard card(501, 100);  // Initial balance = Rs 100

    FareTable fareTable;

    cout << "Passenger ID: " << passenger.passengerId << endl;
    cout << "Passenger Type: " << passenger.passengerType << endl;

    int fare = fareTable.calculateFare(journey.zone, journey.hour);

    if (journey.hour < 0 || journey.hour > 23 ||
        fare == 0) {
        cout << "Invalid journey details" << endl;
    } else {
        cout << "Fare: Rs " << fare << endl;

        if (card.deductFare(fare)) {
            cout << "Journey approved" << endl;
        } else {
            cout << "Journey denied: Minimum balance rule" << endl;
        }

        cout << "Remaining balance: Rs "
             << card.getBalance() << endl;
    }

    return 0;
}

