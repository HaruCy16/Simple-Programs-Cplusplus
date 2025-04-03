#include <iostream>
using namespace std;

int main(){
  int number;
  int multiplier;

  cout << "Enter a number: ";
  cin >> number;

  cout << "Enter a multiplier: ";
  cin >> multiplier;

  for(int i = 1; i <= multiplier; i++){
    cout << number << " x " << i << " = " << number * i << endl;
  }
}