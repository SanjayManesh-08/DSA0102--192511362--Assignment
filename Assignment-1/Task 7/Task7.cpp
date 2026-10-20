#include <iostream>
using namespace std;

const int MIN_BALANCE = 50;
const int INNER_FARE = 10;
const int MIDDLE_FARE = 20;
const int OUTER_FARE = 30;


int getFare(int zone)
{
    switch (zone)
    {
        case 1:
            return INNER_FARE;
        case 2:
            return MIDDLE_FARE;
        case 3:
            return OUTER_FARE;
        default:
            return 0;
    }
}

bool proceduralCanTravel(int balance, int fare)
{
    return fare > 0 && balance - fare >= MIN_BALANCE;
}

void runProcedural()
{
    cout << "PROCEDURAL VERSION\n";

    int balance = 100;
    int zones[] = {1, 3, 2};

    for (int i = 0; i < 3; i++)
    {
        int fare = getFare(zones[i]);

        if (proceduralCanTravel(balance, fare))
        {
            balance -= fare;
            cout << "Journey accepted. Balance: Rs "
                 << balance << '\n';
        }
        else
        {
            cout << "Journey denied. Balance: Rs "
                 << balance << '\n';
        }
    }
}



class SmartCard
{
private:
    int balance;

public:
    SmartCard(int initialBalance)
    {
        balance = initialBalance;
    }

    bool canTravel(int fare) const
    {
        return fare > 0 &&
               balance - fare >= MIN_BALANCE;
    }

    bool deduct(int fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            return true;
        }

        return false;
    }

    int getBalance() const
    {
        return balance;
    }
};

void runObjectOriented()
{
    cout << "\nOBJECT-ORIENTED VERSION\n";

    SmartCard card(100);
    int zones[] = {1, 3, 2};

    for (int i = 0; i < 3; i++)
    {
        int fare = getFare(zones[i]);

        if (card.deduct(fare))
        {
            cout << "Journey accepted. Balance: Rs "
                 << card.getBalance() << '\n';
        }
        else
        {
            cout << "Journey denied. Balance: Rs "
                 << card.getBalance() << '\n';
        }
    }
}

int main()
{
    runProcedural();
    runObjectOriented();

    return 0;
}

