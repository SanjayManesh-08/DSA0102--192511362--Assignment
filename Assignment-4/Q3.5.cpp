
#include <iostream>
using namespace std;

class Person {
protected:
    int id;
    double phone;
};

class Student : virtual public Person {
    double cgpa;
};

class Staff : virtual public Person {
    double salary;
};

class TeachingAssistant : public Student, public Staff {
    double allowance;
};

class Student2 : public Person {
    double cgpa;
};

class Staff2 : public Person {
    double salary;
};

class TeachingAssistant2 : public Student2, public Staff2 {
    double allowance;
};

int main() {
    cout << "With virtual inheritance: "
         << sizeof(TeachingAssistant) << " bytes\n";

    cout << "Without virtual inheritance: "
         << sizeof(TeachingAssistant2) << " bytes\n";

    return 0;
}

