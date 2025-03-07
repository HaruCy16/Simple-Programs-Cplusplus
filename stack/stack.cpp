#include <iostream>
#include <stack>
using namespace std;

int main(){
  stack<int> numbers;

  // VARIABLES
  int firstNumber;
  int secondNumber;
  int thirdNumber;
  int fourthNumber;

  cout << "Enter your first number: " << endl;
  cin >> firstNumber;

  numbers.push(firstNumber);

  cout << "Enter your second number: " << endl;
  cin >> secondNumber;

  numbers.push(secondNumber);

  cout << "Enter your third number: " << endl;
  cin >> thirdNumber;

  numbers.push(thirdNumber);

  cout << "Enter your fourth number: " << endl;
  cin >> fourthNumber;

  numbers.push(fourthNumber);

  cout << "The numbers you entered are: " << endl;
  while(!numbers.empty()){
    cout << numbers.top() << " ";
    numbers.pop();
  }

  return 0;

}