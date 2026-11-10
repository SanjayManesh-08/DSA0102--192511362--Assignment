
#include <iostream>
#include <string>
using namespace std;

// Member class for service information
class ServiceRecord {
    string serviceDate;

public:
    ServiceRecord(string date) {
        serviceDate = date;
    }

    void display() const {
        cout << "Service Due: " << serviceDate << endl;
    }
};

// Abstract base class
class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented;
    int rentalDays;

public:
    Vehicle(string reg, double rate)
        : registration(reg), dailyRate(rate),
          rented(false), rentalDays(0) {
    }

    virtual double calculateCharge(int days) const = 0;

    virtual void displayDetails() const {
        cout << "Registration: " << registration << endl;
        cout << "Daily Rate: Rs. " << dailyRate << endl;
    }

    void rent(int days) {
        if (!rented) {
            rented = true;
            rentalDays = days;
            cout << registration << " rented successfully." << endl;
        } else {
            cout << registration << " is already rented." << endl;
        }
    }

    void returnVehicle(int lateDays) {
        if (rented) {
            double charge = calculateCharge(rentalDays);
            double lateCharge = lateDays * 100;

            cout << "Rental Charge: Rs. " << charge << endl;
            cout << "Late Charge: Rs. " << lateCharge << endl;
            cout << "Total Charge: Rs. "
                 << charge + lateCharge << endl;

            rented = false;
            rentalDays = 0;
        } else {
            cout << registration << " was not rented." << endl;
        }
    }

    virtual ~Vehicle() {
    }
};

// MotorVehicle class
class MotorVehicle : public Vehicle {
protected:
    double energyLevel;
    ServiceRecord service;

public:
    MotorVehicle(string reg, double rate,
                 double energy, string date)
        : Vehicle(reg, rate),
          energyLevel(energy), service(date) {
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Fuel/Charge Level: "
             << energyLevel << endl;
        service.display();
    }
};

// Bicycle class
class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate)
        : Vehicle(reg, rate) {
    }

    double calculateCharge(int days) const override {
        return dailyRate * days;
    }
};

// TwoWheeler class
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string reg, double rate,
               double fuel, string date)
        : MotorVehicle(reg, rate, fuel, date) {
    }

    double calculateCharge(int days) const override {
        return dailyRate * days + 50;
    }
};

// Car class
class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string reg, double rate, double fuel,
        string date, int capacity)
        : MotorVehicle(reg, rate, fuel, date),
          seats(capacity) {
    }

    double calculateCharge(int days) const override {
        return dailyRate * days + seats * 20;
    }

    void displayDetails() const override {
        MotorVehicle::displayDetails();
        cout << "Seating Capacity: " << seats << endl;
    }
};

// ElectricCar class
class ElectricCar : public Car {
protected:
    double batteryCapacity;
    double energyUsed;
    double costPerKwh;

public:
    ElectricCar(string reg, double rate,
                double charge, string date,
                int capacity, double battery,
                double used, double cost)
        : Car(reg, rate, charge, date, capacity),
          batteryCapacity(battery),
          energyUsed(used), costPerKwh(cost) {
    }

    double calculateCharge(int days) const override {
        return dailyRate * days
               + energyUsed * costPerKwh;
    }

    void displayDetails() const override {
        Car::displayDetails();
        cout << "Battery Capacity: "
             << batteryCapacity << " kWh" << endl;
    }
};

// New vehicle type added without modifying old classes
class ElectricBus : public ElectricCar {
public:
    ElectricBus(string reg, double rate,
                double charge, string date,
                int capacity, double battery,
                double used, double cost)
        : ElectricCar(reg, rate, charge, date,
                      capacity, battery, used, cost) {
    }

    double calculateCharge(int days) const override {
        return dailyRate * days
               + energyUsed * costPerKwh
               + seats * 10;
    }
};

int main() {

    // Array of base-class pointers
    Vehicle* fleet[5];

    fleet[0] = new Bicycle("BIKE101", 100);

    fleet[1] = new TwoWheeler(
        "TWO201", 300, 80, "15-12-2026"
    );

    fleet[2] = new Car(
        "CAR301", 1000, 60,
        "20-12-2026", 5
    );

    fleet[3] = new ElectricCar(
        "EV401", 1200, 90,
        "25-12-2026", 5, 60, 15, 8
    );

    fleet[4] = new ElectricBus(
        "BUS501", 3000, 95,
        "30-12-2026", 30, 150, 40, 8
    );

    cout << "VEHICLE RENTAL FLEET" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\n----------------------" << endl;
        fleet[i]->displayDetails();

        fleet[i]->rent(2);

        cout << "Return Details:" << endl;
        fleet[i]->returnVehicle(1);
    }

    // Release dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        delete fleet[i];
    }

    return 0;
}

