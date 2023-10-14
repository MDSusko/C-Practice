/* Program to open a recipe from a .txt file, reformat and convert ingredients as needed, then output to .txt
Written by Markus Susko | plurfxla@gmail.com | May not be redistributed without permission
https://github.com/MDSusko */


#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <fstream>

int main (){

    //Declare Variables 
    std::string ingredientLookup;
    std::string ingredientName;
    int ingredientAmount;
    std::ifstream file;
    std::string recipeName;
    std::string chefName;
    std::string dirLine;
    int i;
    char convert;
    double convAmt;
    bool conCond = false;

    //Open File 
    file.open("basicbread.txt");

    bool found = false;         //Check if file opened correctly 

    //Open and check file 
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return 1; //Exit with error code.
    }
    
    //Ask if user wants to convert or not
    std::cout << "Would you like to convert the recipe? (Y/N)";
    std::cin >> convert;

    //Branch to convert

    if (convert == 'Y' || convert == 'y') {
        conCond = true;
        std::cout << "Enter the amount to convert, to half type in .5, to quarter type in .25, to double type 2.0, etc: ";
        std::cin >> convAmt;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Here is the converted recipe!" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        //Get Recipe Name
        getline(file, recipeName);
        std::cout << recipeName << std::endl;
        std::cout << "---------------------------------" << std::endl;

        //Get Chef Name
        getline(file, chefName);
        std::cout << std::endl; 
        std::cout << "By: " << chefName << std::endl;
        std::cout << std::endl; 

        //Get Ingredients
        std::cout << "Ingredients: " << std::endl;
        std::cout << "---------------------------------" << std::endl;

        //Read ingredients
        while (file >> ingredientName >> ingredientAmount) {
            if (!file.fail()) {
                std::cout << ingredientName << "-" << (ingredientAmount * convAmt) << "g" << std::endl;
            }
        }        
    
        file.clear();  //FIXME Need a workaround to read first line without "Directions:" in .txt file 

        //Directions
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Directions: " << std::endl;
        std::cout << std::endl;

        i = 1;
        //Read Directions
        while (getline(file,dirLine)) {
            std::cout << i << "." << " " << dirLine << std::endl;
            i++;
        }

        std::cout << "---------------------------------" << std::endl;

    }

    //Branch to keep original recipe
    else {

        //Get Recipe Name
        getline(file, recipeName);
        std::cout << recipeName << std::endl;
        std::cout << "---------------------------------" << std::endl;

        //Get Chef Name
        getline(file, chefName);
        std::cout << std::endl; 
        std::cout << "By: " << chefName << std::endl;
        std::cout << std::endl; 

        //Get Ingredients
        std::cout << "Ingredients: " << std::endl;
        std::cout << "---------------------------------" << std::endl;

        //Read ingredients
        while (file >> ingredientName >> ingredientAmount) {
            if (!file.fail()) {
                std::cout << ingredientName << "-" << ingredientAmount << "g" << std::endl;
            }
        }        
    
        file.clear(); //FIXME Need a workaround to read first line without "Directions:" in .txt file 

        //Directions
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Directions: " << std::endl;
        std::cout << std::endl;

        i = 1;
        //Read Directions
        while (getline(file,dirLine)) {
            std::cout << i << "." << " " << dirLine << std::endl;
            i++;
        }

        std::cout << "---------------------------------" << std::endl;
    }
    
    file.close();

    return 0;
}
