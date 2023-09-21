#include <iostream>

int main () {
    int red, green, blue, minVal;

    //Input RGB Values

    std::cout << "Input red value (0-255):";
    std::cin >> red;
    std::cout << "Input green value (0-255):";
    std::cin >> green;
    std::cout << "Input blue value (0-255):";
    std::cin >> blue;

    //Error Check 

    if ((red < 0 || red >= 256) || (green < 0 || green >= 256) || (blue < 0 || blue >= 256)){
        std::cout << "INPUT ERROR - Program Stopped";
    }

    else {

    //Find smallest value amoung R,G,B

        if (red <= green && red <= blue) {
            minVal = red;
        }
        else if (green <= red && green <= blue){
            minVal = green;
        }
        else {
            minVal = blue;
        }

    //Subtract minVal from all three colors
        red -= minVal;
        green -= minVal;
        blue -= minVal;

    //Output to screen
        std::cout << red << " " << green << " " << blue << std::endl;
    }
    return 0; 
}