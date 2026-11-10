
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
        : name(n), id(i), phone(p) {}
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p,
            string prog, double c)
        : Person(n, i, p),
          programme(prog), cgpa(c) {}
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p,
          string dept, double s)
        : Person(n, i, p),
          department(dept), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string prog, double c,
                      string dept, double s)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, s) {}

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string prog, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          fellowship(f) {}

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Fellowship: Rs " << fellowship << endl;
    }
};

int main() {
    TeachingAssistant ta(
        "Arun", 101, "9876543210",
        "MCA", 8.5, "Computer Science", 30000
    );

    ResearchScholar rs(
        "Kavya", 102, "9876501234",
        "PhD", 9.2, 25000
    );

    cout << "TEACHING ASSISTANT DETAILS" << endl;
    ta.display();

    cout << "\nRESEARCH SCHOLAR DETAILS" << endl;
    rs.display();

    return 0;
}

