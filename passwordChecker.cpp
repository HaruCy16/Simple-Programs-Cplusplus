#include <iostream>
using namespace std;

const int MAX_ATTEMPTS = 3;
const string CORRECT_USERNAME = "admin";
const string CORRECT_PASSWORD = "admin123";

int main(){
  int attempts = 0;
  string username, password;

  do{
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if(username == CORRECT_USERNAME && password == CORRECT_PASSWORD){
      cout << "Access granted!" << endl;
      break;
    } else {
      attempts++;
      cout << "Incorrect username or password. Attempts left: " << (MAX_ATTEMPTS - attempts) << endl;
      if(attempts == MAX_ATTEMPTS){
        cout << "Maximum attempts reached. Access denied." << endl;
      }
    }
  }while(attempts < MAX_ATTEMPTS);

  return 0;
}