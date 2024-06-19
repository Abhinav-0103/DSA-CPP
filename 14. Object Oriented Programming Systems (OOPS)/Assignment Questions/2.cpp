#include<iostream>
using namespace std;

class BankAccount {
    int accountNumber;
    int balance;

    public:
        BankAccount(int accNum, int bal) {
            accountNumber = accNum;
            balance = bal;
        }

        void deposit(int amount) {
            balance += amount;
            cout << "Rs." << amount << " deposited" << endl;
        }

        void withdraw(int amount) {
            if(amount > balance) {
                cout << "Only Rs." << balance << " are available" << endl;
                cout << "Rs." << balance << " withdrawn" << endl;
                balance = 0;
            } else {
                balance -= amount;
                cout << "Rs." << amount << " withdrawn" << endl;
            }
        }

        void getBalance() {
            cout << "Your current balance: Rs." << balance << endl;
        }
};

int main() {
    BankAccount b1(1, 5000);

    b1.getBalance();
    b1.withdraw(6000);
    b1.getBalance();
    b1.deposit(2000);
    b1.getBalance();
    return 0;
}