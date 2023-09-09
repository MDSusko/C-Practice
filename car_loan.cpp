//Simple program to determine an auto loan

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main(){
    
    //Declare Variables
    double vehicleCost;
    int term;
    int termYears;
    double interestRate;
    double monthlyInterest;
    double loanBalance;
    double downPayment;
    double tradeinValue;
    double totalPayment;
    double x;
    double y;
    double z;
    double pow(double base, double exp);


    //Get user input
    std::cout << "Enter vehicle cost: " << std::endl;
    std::cin >> vehicleCost;
    std::cout << "Enter down payment: " << std::endl;
    std::cin >> downPayment;
    std::cout << "Enter trade-in value: " << std::endl;
    std::cin >> tradeinValue;
    std::cout << "Enter term (months): " << std::endl;
    std::cin >> term;
    std::cout << "Enter interest rate: " << std::endl;
    std::cin >> interestRate;

    //Formulas 
    interestRate = interestRate / 100;                          //Convert integer to a decimal 
    loanBalance = vehicleCost - downPayment - tradeinValue;    // Formula to find out loan balance 
    monthlyInterest = (interestRate / 12) * loanBalance;       // Formula to find monthly interest 
    termYears = term / 12;

    //Break down car payment formula in steps 
    x = loanBalance * (interestRate / 12);                     // Calculate Step 1
    y = 1 + (interestRate / 12);                               // Calculate Step 2
    z = (1 - (pow(y,-term)));                                  // Calculate Step 3
    totalPayment = x / z;                                      // Calculate Step 4

    //Output to screen
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The total monthly loan payment for a car loan valued at: $" << loanBalance << " is $" << totalPayment << "/month." << std::endl;

    return 0;
}