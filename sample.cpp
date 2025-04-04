#include <iostream>
using namespace std;

int main(){
  int number;

  cout << "Enter a number: ";
  cin >> number;

  //FIBONACCI SERIES NA LOGIC
  int first = 0, second = 1, next;
  // cout << first << " ";
  //IF INPUT IS 2 DISPLAY 0 1
  // if(number == 2){
  //   cout << second << " ";
  //   return 0;
  // }

  // for(int i = 1; i < number; i++){
  //   next = first + second;
  //   cout << next << " ";
  //   first = second;
  //   second = next;
    
  // }

  cout << first << " " << second << " ";
  
  if(number == second){
    cout << 0;
  } else{
    for(int i = 2; i < number; i++){
      next = first + second;
      cout << next << " ";
      first = second;
      second = next;
    }
  }
  return 0;
}