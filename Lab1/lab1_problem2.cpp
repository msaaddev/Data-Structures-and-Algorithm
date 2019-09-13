#include <iostream>
#include <cstring>
using namespace std;

struct Details
{
    string name;
    int accountNumber;
    int balance;
};

void nameOfCustomer(Details customers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (customers[i].balance < 200)
            cout << customers[i].name << endl;
    }
}

void increaseInBalance(Details customers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (customers[i].balance > 1000)
        {
            customers[i].balance += 100;
            cout << "Balance of " << customers[i].name << " has now incremented to: $" << customers[i].balance;
            cout << endl;
        }
    }
}

int main()
{
    Details customers[15];

    //Input block
    for (int i = 0; i < 15; i++)
    {
        cout << "Enter the name of customer " << i + 1 << ": ";
        cin >> customers[i].name;
        cout << endl;

        cout << "Enter the account number of customer " << i + 1 << ": ";
        cin >> customers[i].accountNumber;
        cout << endl;

        cout << "Enter the balance of customer " << i + 1 << ": $";
        cin >> customers[i].balance;
        cout << endl;
    }

    nameOfCustomer(customers, 15);
}