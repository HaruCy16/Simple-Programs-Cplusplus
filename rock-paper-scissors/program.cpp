#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
  srand(time(0)); //seed random number generator

  //initialization of variables, computer move, user move, and play again
  string rock = "rock";
  string paper = "paper";
  string scissors = "scissors";
  string computerMove;
  string userMove;

  char playAgain = 'y';

  //GAME LOGIC, do while loop for user to play again
  do
  {
    cout << "Choose, rock, paper, or scissors?" << endl;
    cin >> userMove;
  
      int randomMove = rand() % 3 + 1;
      if (randomMove == 1) {
          computerMove = rock;
          }
      else if (randomMove == 2) {
          computerMove = paper;
          }
      else {
          computerMove = scissors;
          }
      
      //user move vs computer move
      if (userMove == computerMove) {
          cout << "It's a tie! You both chose " << userMove << endl;
      } else if (userMove == computerMove) {
          cout << "You chose " << userMove << " and the computer chose " << computerMove << ". It's a tie!" << endl;
      } else if (userMove == rock) {
          if (computerMove == paper) {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Paper wins!" << endl;
          } else {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Rock wins!" << endl;
          }
      } else if (userMove == paper) {
          if (computerMove == rock) {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Paper wins!" << endl;
          } else {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Scissors wins!" << endl;
          }
      } else if (userMove == scissors) {
          if (computerMove == rock) {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Rock wins!" << endl;
          } else {
              cout << "You chose " << userMove << " and the computer chose " << computerMove << ". Scissors wins!" << endl;
          }
      } else {
          cout << "Invalid move. Please enter rock, paper, or scissors." << endl;
      }

      cout << "Do you want to play again? (y/n): ";
      cin >> playAgain;

      //Prompt if user didn't type rock, paper, or scissors
      while(userMove != rock && userMove != paper && userMove != scissors){
          cout << "Enter your move (rock, paper, or scissors): ";
          cin >> userMove;
      }

      //Prompt if user didn't type y and n
      while(playAgain != 'y' && playAgain != 'n'){
          cout << "Do you want to play again? (y/n): ";
          cin >> playAgain;
      }
  } while (playAgain == 'y');
  

  //EXIT NA
  cout << "================================================================" << endl;
  cout << "Thanks for playing!" << endl;
  return 0;
}