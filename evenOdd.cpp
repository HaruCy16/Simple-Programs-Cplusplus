#include <iostream>
using namespace std;

int main(){
  int number;

  cout << "Enter a number: ";
  cin >> number;

  int result = number%2;

  if (result == 0){
    cout << "The result is even" << endl;
  } else {
    cout << "The result is odd" << endl;
  }

  return 0;
}