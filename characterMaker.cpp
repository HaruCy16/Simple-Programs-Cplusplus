#include <iostream>
using namespace std;

class Character
{
  private:
    string characterName;
    string characterWeapon;
    string characterType;
  
  public:
    Character(string name, string weapon, string type){
      characterName = name;
      characterWeapon = weapon;
      characterType = type;
    }

    void addCharacter(string name, string weapon, string type){
      name = name;
      weapon = weapon;
      type = type;
      cout << "Character added successfully." << endl;
    }

    string getName(){
      return characterName;
    }
    string getWeapon(){
      return characterWeapon;
    }
    string getType(){
      return characterType;
    }

    void displayCharacter(){
      cout << "Character name: " << characterName << endl;
      cout << "Weapon: " << characterWeapon << endl;
      cout << "Type: " << characterType << endl;
    }
};

// class saveCharacter : public Character
// {
//   public:
//     void 
// }  

int main(){
  string name;
  string weapon;
  string type;

  cout << "Enter character name: ";
  cin >> name;
  cout << "Enter weapon: ";
  cin >> weapon;
  cout << "Enter type: ";
  cin >> type;

  Character character = Character(name, weapon, type);
  character.addCharacter(name, weapon, type);
  character.displayCharacter();

  return 0;
}