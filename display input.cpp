#include <iostream>
using namespace std;

class Person
{
  private:
    string name;
    int age;
    string address;
  
  public:
    void setPerson(string pName, int pAge, string pAddress) {
        name = pName;
        age = pAge;
        address = pAddress;
    }

    string getName() { return name; }
    int getAge() { return age; }
    string getAddress() { return address; }

    void displayPerson() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Address: " << getAddress() << endl;
    }
};

int main(){
  string name;
  int age;
  string address;

  Person person;

  cout << "Enter your name: "; cin >> name;
  cout << "Enter your age: "; cin >> age;
  cout << "Enter your address: "; cin >> address;
  person.setPerson(name, age, address);
  cout << "---------------------------\n";
  cout << "Person Details:\n";
  person.displayPerson();
}