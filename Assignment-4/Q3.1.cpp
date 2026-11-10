
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {
        cout << "Person constructor\n";
    }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p,
            string prog, double c)
        : Person(n, i, p),
          programme(prog), cgpa(c) {
        cout << "Student constructor\n";
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p,
          string dept, double s)
        : Person(n, i, p),
          department(dept), salary(s) {
        cout << "Staff constructor\n";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string prog, double c,
                      string dept, double s)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, s) {
        cout << "TeachingAssistant constructor\n";
    }
};

int main() {
    TeachingAssistant ta(
        "Arun", 101, "9876543210",
        "MCA", 8.5, "Computer Science", 30000
    );

    return 0;
}

