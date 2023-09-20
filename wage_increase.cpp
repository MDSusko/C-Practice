//This program takes employee tenor, current wage and education to out put a wage increase amount.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main(){

//Declare Variables 
std::string employeeName;
double yearsWorked;
int months;
double currentWage;
double startWage;
int edLevel;
double updatedWage;
std::string edlevelDescription;
double diffWage;
double yearWage;

//User Input 
std::cout << "Input employee name: ";
std:: cin >> employeeName;
std::cout << "Enter months in position: ";
std:: cin >> months;
std::cout << "Enter employee's current wage: ";
std::cin >> currentWage;
std::cout << "Enter employee's education level, for no college '0', for some college '1', finished college '2', and" << std::endl;
std::cout << "for graudate school '3': ";
std::cin >> edLevel;

//Error Checking 
if (edLevel >= 0 && edLevel <= 3) {

//Set starting Wage based upon Education Level
    if (edLevel == 0) {
        startWage = 15.00;
        edlevelDescription = "No college experience.";
    }

    if (edLevel == 1) {
        startWage = 19.00;
        edlevelDescription = "Some college experience.";
    }

    if (edLevel == 2) {
        startWage = 27.00;
        edlevelDescription = "Has finished undergraduate college.";
    }

    if (edLevel == 3) {
        startWage = 35.00;
        edlevelDescription = "Has finished or is currently enrolled in Graduate school.";
    }
}
else {
    std::cout << "Invalid educational level inputted." << std::endl;
}

//Current Wage Error Calculation
if (currentWage < startWage){
    currentWage = startWage;
}
else if ((currentWage == startWage) || (currentWage >= startWage)){
    currentWage = currentWage;
}

//Set updated wage per tenor 
yearsWorked = months / 12.00;

if (yearsWorked <= 1.00) {
    updatedWage = currentWage * 1.25;
}
else if (yearsWorked > 1.00 && yearsWorked <= 3.00){
    updatedWage = currentWage * 1.50;
}
else if (yearsWorked > 3.00 && yearsWorked <= 5.50){
    updatedWage = currentWage * 1.80;
}
else if (yearsWorked > 5.50 && yearsWorked <= 8.50){
    updatedWage = currentWage * 2.25;
}
else if (yearsWorked > 8.50){
    updatedWage = currentWage * 3;
}

diffWage = updatedWage - currentWage;
yearWage = (updatedWage * 40) * 52;

//Output
std::cout << std::fixed << std::setprecision(2);
std::cout << std::endl;
std::cout << employeeName << " has worked with the company for " << yearsWorked << " years. Their education level is: " << edlevelDescription << std::endl;
std::cout << "Their current wage is: $" << currentWage << " per hour and based off their time with the company have been given a wage increase to: $" << updatedWage << " per hour." << std::endl;
std::cout << "This is an increase of: $" << diffWage << " per hour, for a yearly income of: $" << yearWage << " before tax." << std::endl;
std::cout << "Congrats on your raise!";

return 0;
}