//Program to take user gender, age, weight, body fat and activity level as well as fitness goal to out put macro intake/calories 

#include <iostream>
#include <iomanip>
#include <cmath>

int main (){

    //Define variables
    int userGender;
    int userAge;
    double userWeight;
    double userbodyFat;
    double userHeight;
    double weightKg;
    double lbm;
    double fatMass;
    double heightCm;
    double bodyFat;
    double rmr;
    double bmr;
    int useractLevel;
    double actModify;
    int userfitGoal;
    int proteinPercent;
    int carbPercent;
    int fatPercent;
    double convproteinPercent;
    double convcarbPercent;
    double convfatPercent;
    int protein;
    int carb;
    int fat;
    int totalCals;
    int meals;
    double totalMeals;

    //Ask user input 
    std::cout << "Input user gender, for male type '1', for female type '2': ";
    std::cin >> userGender;
    std::cout << "User age: ";
    std::cin >> userAge;
    std::cout << "User weight: ";
    std::cin >> userWeight;
    std::cout << "User height (in inches): ";
    std::cin >> userHeight;
    std::cout << "User body fat % (Enter as whole number): ";
    std::cin >> userbodyFat;
    std::cout << "User activity level, for Sedentary enter 1, for mild activity enter 2, for moderate activity enter 3,";
    std::cout << "for heavy activity enter 4, for very heavy-extreme activity enter 5.: ";
    std::cin >> useractLevel;

    //Convert user data
    heightCm = userHeight * 2.54;
    bodyFat = (userbodyFat / 100.00);
    weightKg = userWeight / 2.20;
    fatMass = userWeight * bodyFat;
    lbm = userWeight - fatMass;


    //Formulate Activity Level Modifier 

    if (useractLevel == 1){
        actModify = 1.2;
    }
     if (useractLevel == 2){
        actModify = 1.375;
    }
     if (useractLevel == 3){
        actModify = 1.55;
    }
     if (useractLevel == 4){
        actModify = 1.7;
    }
     if (useractLevel == 5){
        actModify = 1.9;
    }

    //Formulate RMR & BMR

    if (userGender == 1){
        rmr = 9.99 * weightKg + 6.25 * heightCm - 4.92 * userAge +5;
        bmr = rmr * actModify;
    }
    else if (userGender == 2){
        rmr = 9.99 * weightKg + 6.25 * heightCm - 4.92 * userAge -161;
        bmr = rmr * actModify;
    }
    else {
        std::cout << "INVALID INPUT";
    }

    //Output RMR and BMR to screen and LBM/FM
    std::cout << std::endl;
    std::cout << "Users RMR is: " << rmr << " kcals/day." << std::endl;
    std::cout << "Users BMR is: " << bmr << " kcals/day." << std::endl;
    std::cout << "Users Lean Body Mass (LBM) in pounds is: " << lbm << std::endl;
    std::cout << "Users Fat Mass (FM) in pounds is: " << fatMass << std::endl;
    std::cout << std::endl;

    //Get user fitness goals.
    std::cout << "Enter fitness goal. For maintence enter 1, for cut/fat loss enter 2, for bulk/LBM gain enter 3: ";
    std::cin >> userfitGoal;
    std::cout << "Enter meals per day: ";
    std::cin >> totalMeals;
    std::cout << "Enter percentage of macros for protein: ";
    std::cin >> proteinPercent;
    std::cout << "Enter percentage of macros for carbs: ";
    std::cin >> carbPercent;
    std::cout << "Enter percentage of macros for fats: ";
    std::cin >> fatPercent;

    //Error check macro % == 100
    if (proteinPercent + carbPercent + fatPercent == 100){
        //Calc grams of macros + caloric data
        convproteinPercent = proteinPercent / 100.00;
        protein = (bmr * convproteinPercent);
        convcarbPercent = carbPercent / 100.00;
        carb = (bmr * convcarbPercent);
        convfatPercent = fatPercent / 100.00;
        fat = (bmr * convfatPercent);

        //Output pre goal ratios
        protein = protein / 4;
        carb = carb / 4;
        fat = fat / 9;
        
        std::cout << std::endl;
        std::cout << "Based on user inputted ratios, macro intake per day is:" <<std::endl;
        std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
        std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
        std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
        std::cout << std::endl;
    
        //Output goal ratios
        if (userfitGoal == 1){
            protein = (bmr * .30) / 4;
            carb = (bmr * .40) / 4;
            fat = (bmr * .30) / 9;
            totalCals = bmr;
            meals = totalCals / totalMeals;

            std::cout << "For maintence user should consume: " << std::endl;
            std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
            std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
            std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
            std::cout << std::endl;
            std::cout << "As well as keep caloric intake to: " << totalCals << " k/cals a day.";
            std::cout << "You will eat " << totalMeals << "meals per day, and each meal will have " << meals << " k/cals per meal aprox.";
        }
        if (userfitGoal == 2){
            protein = ((bmr - 500) * .50) / 4;
            carb = ((bmr - 500) * .15) / 4;
            fat = ((bmr - 500) * .35) / 9;
            totalCals = bmr - 500.00;
            meals = totalCals / totalMeals;

            std::cout << "For fat loss/cutting user should consume: " << std::endl;
            std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
            std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
            std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
            std::cout << std::endl;
            std::cout << "As well as decrease caloric intake to: " << totalCals << " k/cals a day.";
            std::cout << "You will eat " << totalMeals << "meals per day, and each meal will have " << meals << " k/cals per meal aprox.";
        }
        if (userfitGoal == 3){
            protein = ((bmr + 500) * .30) / 4;
            carb = ((bmr + 500) * .50) / 4;
            fat = ((bmr + 500) * .20) / 9;
            totalCals = bmr + 500.00;
            meals = totalCals / totalMeals;

            std::cout << "For bulking/ LBM gain user should consume: " << std::endl;
            std::cout << "Protein per day is: " << protein << " g/day." << std::endl;
            std::cout << "Carbs per day is: " << carb << " g/day." << std::endl;
            std::cout << "Fat per day is: " << fat << " g/day." << std::endl;
            std::cout << std::endl;
            std::cout << "As well as increase caloric intake to: " << totalCals << " k/cals a day." << std::endl;
            std::cout << "You will eat " << totalMeals << " meals per day, and each meal will have " << meals << " k/cals per meal aprox.";
        }
    }
    else {
        std::cout << "INVALID INPUT - Program Terminated";
    }
    
    


    return 0;
}