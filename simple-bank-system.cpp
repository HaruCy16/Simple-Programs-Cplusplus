#include <iostream>
using namespace std;

class BankAccount
{
  private:
    int accountNumber;
    int balance;

  public:
    BankAccount(int initialBalance = 0){
      balance = initialBalance;
    }

    void balanceCheck(int newBalance){
      balance = newBalance;
    }

    void deposit(int amount){
      balance += amount;
      cout << "Deposit successful" << endl;
    }

    void withdraw(int amount){
      if (amount > balance){
        cout << "Insufficient funds" << endl;
      } else {
        balance -= amount;
        cout << "Withdrawal successful" << endl;
      }
    }

    void display(){
      cout << "Current Balance: " << balance << endl;
    }

    int getAccountNumber(){
      return accountNumber;
    }
};

int main(){
  BankAccount account;
  int initialBalance;
  string accountName;

  int choice;

  while (choice != 5){
    cout << "\nEnter Mode:" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1){
      cout << "Enter Account Name: ";
      cin >> accountName;
      cout << "Enter initial balance: ";
      cin >> initialBalance;
      account = BankAccount(initialBalance);
      cout << "Account created successfully." << endl;
      account.display();
    } else if (choice == 2){
      int amount;
      cout << "Enter amount to deposit: ";
      cin >> amount;
      account.deposit(amount);
    } else if (choice == 3){
      int amount;
      cout << "Enter amount to withdraw: ";
      cin >> amount;
      account.withdraw(amount);
    } else if (choice == 4){
      account.display();
    }
  }
}