#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

//PROTECTED VARIABLES
class Main
{
  protected:
    string rock = "rock";
    string paper = "paper";
    string scissors = "scissors";
    string computerMove;
    string userMove;
    char playAgain = 'y';
};

//GAME CLASS INHERITING MAIN CLASS TO RENDER GAME LOGIC
class Game : public Main
{
  private:
  void aiMove(){
    srand(time(0));

    int randomMove = rand() % 3 + 1;
    if (randomMove == 1) {
        computerMove = rock;
    } else if (randomMove == 2) {
        computerMove = paper;
    } else {
        computerMove = scissors;
    }
  }

  //GAME LOGIC 
  public:
    void gameLogic(){
      cout << "Welcome to Rock, Paper, Scissors!" << endl;
      cout << "==============================================" << endl;
      cout << "You will be playing against the computer." << endl;
      cout << "==============================================" << endl;

      do
      {
        cout << "Enter your move (rock, paper, or scissors): " << endl;
        cin >> userMove;
        aiMove();

       if (userMove == computerMove) {
          cout << "You chose " << userMove << " and the computer chose " << computerMove << ". It's a tie!" << endl;
          cout << "==============================================" << endl;
        } else if (userMove == rock) {
          if (computerMove == paper) {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Paper wins!" << endl;
              cout << "==============================================" << endl;
          } else {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Rock wins!" << endl;
              cout << "==============================================" << endl;
          }
        } else if (userMove == paper) {
          if (computerMove == rock) {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Paper wins!" << endl;
              cout << "==============================================" << endl;
          } else {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Scissors wins!" << endl;
              cout << "==============================================" << endl;
          }
        } else if (userMove == scissors) {
          if (computerMove == rock) {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Rock wins!" << endl;
              cout << "==============================================" << endl;
          } else {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Scissors wins!" << endl;
              cout << "==============================================" << endl;
          }
        } else {
          cout << "Invalid move. Please enter rock, paper, or scissors." << endl;
          cout << "==============================================" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if(playAgain == 'n'){
          break;
        } else{
          cout << "Get ready to play again" << endl;
          cout << "==============================================" << endl;
        }
      } while (playAgain == 'y');
    }
};

//MAIN FUNCTION
int main(){
  Game game;
  game.gameLogic();
  cout << "================================================================" << endl;
  cout << "Thanks for playing!" << endl;
  return 0;
}