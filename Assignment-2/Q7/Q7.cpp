
#include <iostream>
using namespace std;

class SavingsAccount {
private:
    long long accountNumber;
    double balance;
    double transactions[10];
    int count;
    int nextIndex;

public:
    SavingsAccount(long long accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
        nextIndex = 0;
    }

    void addTransaction(double amount) {
        transactions[nextIndex] = amount;

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10) {
            count++;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction(amount);
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction(-amount);
        } else {
            cout << "Insufficient balance or invalid amount" << endl;
        }
    }

    void miniStatement() const {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
        cout << "Latest Transactions:" << endl;

        int start;

        if (count == 10)
            start = nextIndex;
        else
            start = 0;

        for (int i = 0; i < count; i++) {
            int index = (start + i) % 10;

            if (transactions[index] > 0)
                cout << "Deposit: Rs. " << transactions[index] << endl;
            else
                cout << "Withdrawal: Rs. "
                     << -transactions[index] << endl;
        }
    }
};

int main() {
    SavingsAccount account(123456, 5000);

    for (int i = 1; i <= 12; i++) {
        account.deposit(i * 100);
    }

    account.miniStatement();

    return 0;
}

