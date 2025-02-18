#include <iostream>
using namespace std;

int main(){
  int yourNumber;
  int computerNumber;
  char decision = 'y';

  cout << "Computer picked a number" << endl;

  computerNumber = rand() % 100 + 1;

  do
  {
    while(yourNumber != computerNumber){
      cout << "Input your guess number" << endl;
      cin >> yourNumber;
  
      if(yourNumber < computerNumber){
        cout << "Guess too low" << endl;
      } else if(yourNumber > computerNumber){
        cout << "Guess too high" << endl;
      } else if(yourNumber == computerNumber){
        cout << "Your guess is right" << endl;
      } else {
        cout << "Error" << endl;
      }
    }

    cout << "Do you still want to play? (y/n) " << endl;
    cin >> decision;
  } while (decision == 'y');

  cout << "Thank you!" << endl;
  
  return 0;
}