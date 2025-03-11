#include <iostream>
using namespace std;

int main() {
    double hourlyRate;
    int hoursWorked;

    cout << "Enter hourly rate: ";
    cin >> hourlyRate;
    cout << "Enter total hours worked: ";
    cin >> hoursWorked;

    
    double regularSalary;
    if (hoursWorked > 40) {
        regularSalary = hourlyRate * 40;
    } else {
        regularSalary = hourlyRate * hoursWorked;
    }

    double overtimeSalary;
    if (hoursWorked > 40) {
        overtimeSalary = (hoursWorked - 40) * (hourlyRate * 1.5);
    } else {
        overtimeSalary = 0;
    }

    double grossSalary = regularSalary + overtimeSalary;
    double taxDeduction = grossSalary * 0.10;
    double netSalary = grossSalary - taxDeduction;
    
    cout << "\nRegular Salary: " << regularSalary << endl;
    cout << "Overtime Salary: " << overtimeSalary << endl;
    cout << "Gross Salary: " << grossSalary << endl;
    cout << "Tax Deduction (10%): " << taxDeduction << endl;
    cout << "Net Salary: " << netSalary << endl;

    return 0;
}   