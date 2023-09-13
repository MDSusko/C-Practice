//Simple program to speed of a 100m dash

#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    
    //Declare Variables
    double time;
    double distance;
    double speedMps;
    double speedKph;
    double speedMph;

    //Get user input
    std::cout << "Enter time in seconds for the 100m dash: ";
    std::cin >> time;
    
    //Formulas 
    distance = 100;                             //Distance in meters 
    speedMps = distance / time;                 //Get rate of m/s
    speedKph = (speedMps / 1000) * 3600;        //Convert to km/h
    speedMph = speedKph / 1.61;                 //Convert to mph


    //Output to screen
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Speed in MPH is aproximately: " << speedMph << " mph." << std::endl;

    return 0;
}