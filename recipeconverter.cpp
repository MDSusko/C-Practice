/* Program to open a recipe from a .txt file, reformat and convert ingredients as needed, then output to .txt
Written by Markus Susko | plurfxla@gmail.com | May not be redistributed without permission
https://github.com/MDSusko */


#include <iostream>
#include <string>
#include <fstream>

int main() {
    // Declare Variables
    std::string ingredientName;
    int ingredientAmount;
    double convAmt;
    std::ifstream file;
    std::string fileName;
    std::string recipeName;
    std::string chefName;
    std::string dirLine;
    int i;
    char convert;
    char userOut;
    bool isConvert = false;

    // Open File based on user input
    std::cout << "Enter file name: " << std::endl;
    std::cin >> fileName;
    file.open(fileName);

    // Check if file opened correctly
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return 1; // Exit with an error code.
    }

    // Ask if the user wants to convert or not
    std::cout << "Would you like to convert the recipe? (Y/N)";
    std::cin >> convert;

    // Branch to convert
    if (convert == 'Y' || convert == 'y') {
        std::cout << "Enter the amount to convert (e.g., to half type in 0.5, to double type 2.0, etc): ";
        std::cin >> convAmt;
        std::cout << std::endl;
        isConvert = true;

        // Get Recipe Name
        std::getline(file, recipeName);
        std::cout << recipeName << std::endl;
        std::cout << "---------------------------------" << std::endl;

        // Get Chef Name
        std::getline(file, chefName);
        std::cout << std::endl;
        std::cout << "By: " << chefName << std::endl;
        std::cout << std::endl;

        // Get Ingredients
        std::cout << "Ingredients: " << std::endl;
        std::cout << "---------------------------------" << std::endl;

        // Read ingredients
        while (file >> ingredientName >> ingredientAmount) {
            if (!file.fail()) {
                double ingcovAmt = ingredientAmount * convAmt;
                std::cout << ingredientName << "-" << ingcovAmt << "g" << std::endl;
            }
        }

        file.clear();

        // Directions
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Directions: " << std::endl;
        std::cout << std::endl;

        i = 1;

        // Read Directions
        while (std::getline(file, dirLine)) {
            std::cout << i << ". " << dirLine << std::endl;
            i++;
        }
    }

    // Branch to keep the original recipe
    else {
        // Get Recipe Name
        std::getline(file, recipeName);
        std::cout << recipeName << std::endl;
        std::cout << "---------------------------------" << std::endl;

        // Get Chef Name
        std::getline(file, chefName);
        std::cout << std::endl;
        std::cout << "By: " << chefName << std::endl;
        std::cout << std::endl;

        // Get Ingredients
        std::cout << "Ingredients: " << std::endl;
        std::cout << "---------------------------------" << std::endl;

        // Read ingredients
        while (file >> ingredientName >> ingredientAmount) {
            if (!file.fail()) {
                std::cout << ingredientName << "-" << ingredientAmount << "g" << std::endl;
            }
        }

        file.clear();

        // Directions
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Directions: " << std::endl;
        std::cout << std::endl;

        i = 1;

        // Read Directions
        while (std::getline(file, dirLine)) {
            std::cout << i << ". " << dirLine << std::endl;
            i++;
        }
    }

    file.close();

    // Take formatted data and output to .txt file
    std::cout << std::endl;
    std::cout << "Would you like to output data to .txt? (Y/N) " << std::endl;
    std::cin >> userOut;

    if (userOut == 'y' || userOut == 'Y') {
        // Declare Output file variables
        std::ofstream outFile;
        std::string outfileName;
        std::cout << "Enter output file name: " << std::endl;
        std::cin >> outfileName;

        // Open File and Check if it opened
        outFile.open(outfileName);

        if (!outFile.is_open()) {
            std::cout << outfileName << " could not open, program terminated." << std::endl;
            return 1;
        }

        if (isConvert = false) {
            // Write to output file
            outFile << recipeName << std::endl;
            outFile << "---------------------------------" << std::endl;
            outFile << std::endl;
            outFile << "By: " << chefName << std::endl;
            outFile << std::endl;
            outFile << "Ingredients: " << std::endl;
            outFile << "---------------------------------" << std::endl;

            // Re-Read Ingredient list and output to .txt
            file.open(fileName);
            file.clear();

            std::getline(file, recipeName);
            std::getline(file, chefName);

            // Read ingredients and write to the output file
            while (file >> ingredientName >> ingredientAmount) {
                if (!file.fail()) {
                    outFile << ingredientName << "-" << ingredientAmount << "g" << std::endl;
                }
            }

            file.clear();

            // Directions
            outFile << "---------------------------------" << std::endl;
            outFile << "Directions: " << std::endl;
            outFile << std::endl;

            i = 1;

            // Read Directions and write to the output file
            while (std::getline(file, dirLine)) {
                outFile << i << ". " << dirLine << std::endl;
                i++;
            }

            outFile.close();
        }
        else {
            // Write to output file
            outFile << recipeName << std::endl;
            outFile << "---------------------------------" << std::endl;
            outFile << std::endl;
            outFile << "By: " << chefName << std::endl;
            outFile << std::endl;
            outFile << "Ingredients: " << std::endl;
            outFile << "---------------------------------" << std::endl;

            // Re-Read Ingredient list and output to .txt
            file.open(fileName);
            file.clear();

            std::getline(file, recipeName);
            std::getline(file, chefName);

            // Read ingredients and conversion amounts and write to the output file
            while (file >> ingredientName >> ingredientAmount) {
                if (!file.fail()) {
                    double ingcovAmt = convAmt * ingredientAmount;
                    outFile << ingredientName << "-" << ingcovAmt << "g" << std::endl;
                }
            }

            file.clear();

            // Directions
            outFile << "---------------------------------" << std::endl;
            outFile << "Directions: " << std::endl;
            outFile << std::endl;

            i = 1;

            // Read Directions and write to the output file
            while (std::getline(file, dirLine)) {
                outFile << i << ". " << dirLine << std::endl;
                i++;
            }

            outFile.close();    
        }
    }

    file.close();
    return 0;
}
