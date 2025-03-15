#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    int balance; 

public:
    BankAccount(int initialBalance = 0) {
        balance = initialBalance;
    }

    void balanceCheck(int newBalance) {
        balance = newBalance; 
    }

    void deposit(int amount) {
        balance += amount;
        cout << "Deposit successful" << endl;
    }

    void withdraw(int amount) {
        if (amount > balance) {  
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful" << endl;
        }
    }

    void display() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    int amount, initialBalance;
    
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(initialBalance);  

    cout << "Enter amount to deposit: ";
    cin >> amount;
    account.deposit(amount);

    cout << "Enter amount to withdraw: ";
    cin >> amount; 
    account.withdraw(amount);

    account.display();  //Display final balance

    return 0;
}
