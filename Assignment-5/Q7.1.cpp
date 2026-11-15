
#include <iostream>
#include <stdexcept>
using namespace std;

void validate(double amount) {
    if (amount < 0)
        throw invalid_argument("negative");

    if (amount > 1000000)
        throw out_of_range("too large");

    cout << "ok ";
}

void process(double amount) {
    try {
        validate(amount);
    }
    catch (const out_of_range& e) {
        cout << "[log " << e.what() << "] ";
        throw;
    }
}

int main() {
    double amounts[] = {100, -5, 2000000};

    for (int i = 0; i < 3; i++) {
        try {
            process(amounts[i]);
            cout << "done ";
        }
        catch (const exception& e) {
            cout << "caught " << e.what() << " ";
        }
    }

    cout << endl;
    return 0;
}

