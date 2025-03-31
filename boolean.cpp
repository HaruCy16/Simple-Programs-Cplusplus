#include <iostream>
using namespace std;

int main(){
  int number;
  bool isLessThan50 = false;
  bool isGreaterThan50 = true;

  cout << "Enter a number: ";
  cin >> number;

  if(number > 50){
    cout << isGreaterThan50 << endl;
  } else {
    cout << isLessThan50 << endl;
  }

  return 0;
}