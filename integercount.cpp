#include <iostream>
using namespace std;

//OUTPUT:
// Enter a number: 5
// 5 4 3 2 1
int main(){
  int num;

  cout << "Enter a number: ";
  cin >> num;

  for(int i = num; i >= 1; i--){
    cout << i << " ";
  }
}