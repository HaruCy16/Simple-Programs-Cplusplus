#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    int balance; 

public:
    // ✅ Constructor to initialize balance
    BankAccount(int initialBalance = 0) {
        balance = initialBalance;
    }

    // ✅ Correct balanceCheck function
    void balanceCheck(int newBalance) {
        balance = newBalance; // Correctly assign the value
    }

    void deposit(int amount) {
        balance += amount;
        cout << "Deposit successful" << endl;
    }

    void withdraw(int amount) {
        if (amount > balance) {  // ✅ Corrected condition
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

    BankAccount account(initialBalance);  // ✅ Use constructor

    cout << "Enter amount to deposit: ";
    cin >> amount;
    account.deposit(amount);

    cout << "Enter amount to withdraw: ";
    cin >> amount;
    account.withdraw(amount);

    account.display();  // ✅ Display final balance

    return 0;
}
