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
    //FIXME add more variables for conversion 

    //Open File 
    file.open("basicbread.txt");

    bool found = false;         //Check if file opened correctly 

    //Open and check file 
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return 1; //Exit with error code.
    }
    
    //Get Recipe Name and Chef Name 
    getline(file, recipeName);
    std::cout << recipeName << std::endl;
    std::cout << "---------------------------------" << std::endl;
    getline(file, chefName);
    std::cout << "By: " << chefName << std::endl;
    std::cout << std::endl; 

    //Format all ingredients in file
    while (file >> ingredientName >> ingredientAmount) {
        //Loop to read all ingredients 
        while (!file.eof()) {
            file >> ingredientName;
            file >> ingredientAmount;

            //FIXME Program not pulling first ingredient 

            if (!file.fail()) {
                //Get ingredients and format 
                std::cout << ingredientName << "-" << ingredientAmount << "g" << std::endl;
            }
        }
    }

    file.close();
    
    return 0;
}