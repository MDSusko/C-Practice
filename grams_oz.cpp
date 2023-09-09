// Program is to find the ingredient weight in grams and convert to ounces.

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    
    //Declare Variables
    double weightGrams;
    double weightOunces;
    std::string ingredientName;

    //Get user data via input 
    std::cout << "Input ingredient: " << std::endl;
    std:: cin >> ingredientName;
    std::cout << "Input weight of " << ingredientName << " in Grams." << std::endl;
    std::cin >> weightGrams;
    
    //Formulas 
    weightOunces = weightGrams / 28.3;

    //Output to screen
    std::cout << std::fixed << std::setprecision(2);
    std::cout << weightGrams << "g of " << ingredientName << " is " << weightOunces << "oz." << std::endl;
    return 0;
}