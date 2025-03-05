#include <iostream>
#include <string>
using namespace std;

//PROTECTED VARIABLE GRADES
class Grades
{
  protected:
    double RPH;
    double comProg;
    double DSA;
    double PE;
    double linearAlgebra;
    double fili;
    double STS;
    double NSTP;

    double grade;
};

class Main : public Grades
{
  private:
    string studentName;
    int studentID;
    string course;
    double totalGrade;
    int average;

  public:
    void checkInformation(){
      cout << "Enter your name: ";
      cin >> studentName;
      cout << "Enter your student ID: ";
      cin >> studentID;
      cout << "Enter your course: ";
      cin >> course;
      cout << "======================================================" << endl;
    }
  public: //ADDED SPACE SA CIN SO THE CIN WILL BUFFER THE INPUT
    void gradeChecker(){
      cout << "Enter your grade for RPH: " << endl;
      cin >> RPH;

      cout << "Enter your grade for Computer Programming: " << endl;
      cin >> comProg;

      cout << "Enter your grade for DSA: " << endl;
      cin >> DSA;

      cout << "Enter your grade for PE: " << endl;
      cin >> PE;

      cout << "Enter your grade for Linear Algebra: " << endl;
      cin >> linearAlgebra;

      cout << "Enter your grade for FILI: " << endl;
      cin >> fili;

      cout << "Enter your grade for STS: " << endl;
      cin >> STS;

      cout << "Enter your grade for NSTP: " << endl;
      cin >> NSTP;
      
      cout << "======================================================" << endl;

      totalGrade = RPH + comProg + DSA + PE + linearAlgebra + fili + STS + NSTP / 8;
      average = (int)totalGrade;

      if (average >= 75){
        cout << "Congratulations!" << studentName << "You passed the semester with an average grade of " << average << endl;
      } else {
        cout << "Sorry, you failed the semester with an average grade of " << average << endl;
      }
    }
};

int main(){
  Main main;

  cout << "Welcome to the Grade Calculator!" << endl;
  cout << "======================================================" << endl;

  main.checkInformation();
  main.gradeChecker();

  return 0;
}