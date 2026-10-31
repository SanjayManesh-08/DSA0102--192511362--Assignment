
#include <iostream>
using namespace std;

class SavingsAccount {
private:
    long long accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(long long accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
    }

    void addTransaction(double amount) {
        if (count == 10) {
            // Remove the oldest transaction
            for (int i = 0; i < 9; i++) {
                transactions[i] = transactions[i + 1];
            }
            count = 9;
        }

        transactions[count] = amount;
        count++;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

// Member function defined outside the class
void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction(amount);
        cout << "Deposited: Rs. " << amount << endl;
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction(-amount);
        cout << "Withdrawn: Rs. " << amount << endl;
    } else {
        cout << "Insufficient balance or invalid amount" << endl;
    }
}

void SavingsAccount::miniStatement() const {
    cout << "\nAccount Number: " << accountNumber << endl;
    cout << "Current Balance: Rs. " << balance << endl;
    cout << "Recent Transactions:" << endl;

    for (int i = 0; i < count; i++) {
        if (transactions[i] > 0)
            cout << "Deposit: Rs. " << transactions[i] << endl;
        else
            cout << "Withdrawal: Rs. " << -transactions[i] << endl;
    }
}

int main() {
    SavingsAccount account(123456, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}

