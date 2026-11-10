
#include <iostream>
using namespace std;

class Address {
public:
    Address() {
        cout << "Address ";
    }

    ~Address() {
        cout << "~Address ";
    }
};

class Course {
public:
    Course() {
        cout << "Course ";
    }

    ~Course() {
        cout << "~Course ";
    }
};

class Person {
protected:
    Address home;

public:
    Person() {
        cout << "Person ";
    }

    virtual ~Person() {
        cout << "~Person ";
    }
};

class Student : virtual public Person {
    Course course;

public:
    Student() {
        cout << "Student ";
    }

    ~Student() {
        cout << "~Student ";
    }
};

class Staff : virtual public Person {
public:
    Staff() {
        cout << "Staff ";
    }

    ~Staff() {
        cout << "~Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant() {
        cout << "TA ";
    }

    ~TeachingAssistant() {
        cout << "~TA ";
    }
};

int main() {
    cout << "Student object: ";
    {
        Student s;
    }

    cout << "\nStaff object: ";
    {
        Staff s;
    }

    cout << "\nTeachingAssistant object: ";
    {
        TeachingAssistant ta;
    }

    cout << '\n';

    return 0;
}

