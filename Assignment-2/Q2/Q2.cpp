#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

int highestMarkCopy(int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

const int& highestMarkConst(const int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

int main() {
    int marks[5] = {75, 88, 92, 81, 85};

    cout << "Original marks: ";

    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }

    cout << "\nHighest mark: " << highestMark(marks, 5);

   
    highestMark(marks, 5) += 2;

    cout << "\nAfter adding 2 marks: ";

    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }

    cout << "\nHighest mark as copy: "
         << highestMarkCopy(marks, 5);

    cout << "\nHighest mark as const reference: "
         << highestMarkConst(marks, 5) << endl;

    return 0;
}

