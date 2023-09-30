#include <iostream>
#include <stdlib.h>
#include <ctime>

int main(){

    //Declare Variables

    int lotNum, lotTicket, lotDigit1, lotDigit2, tixDigit1, tixDigit2, award;

    //Generate random seed
    srand(time(nullptr));

    //Generate 2 digit lottery number
    lotNum = std::rand() % 100;

    //Generate 2 digit lottery ticket
    lotTicket = std::rand() % 100;

    //Get individual digits from lotNum and lotTicket
    lotDigit1 = lotNum / 10;
    lotDigit2 = lotNum % 10;
    tixDigit1 = lotTicket / 10;
    tixDigit2 = lotTicket % 10;

    
    

    //Output Lottery Number and Ticket Number
    std::cout << "Lottery Number: " << (lotDigit1 < 0 ? "0" : "") << lotDigit1
              << lotDigit2 << std::endl;
    std::cout << "Lotto Ticket: " << (tixDigit1 < 0 ? "0" : "") << tixDigit1
              << tixDigit2 << std::endl;


    //Check reward amount
    award = 0;
    if (lotNum == lotTicket){
        award = 10000;
    }
    else if ((lotDigit1 == tixDigit1) || (lotDigit1 == tixDigit2) && (lotDigit2 == tixDigit1 || lotDigit2 == tixDigit2)){
        award = 3000;
    }
    else if (lotDigit1 == tixDigit1 || lotDigit1 == tixDigit2 || lotDigit2 == tixDigit1 || lotDigit2 == tixDigit2){
        award = 1000;
    }

    //Output award value

    switch (award) {
        case 10000:
        std::cout << "You win: $10,000!!!" << std::endl;
        break;

        case 3000:
        std::cout << "You win: $3,000!! " << std::endl;
        break;
        
        case 1000:
        std::cout << "You win: $1,000.... " << std::endl;
        break;

        default:
        std::cout << "You win: $0, try again!" << std::endl;
    }

    return 0;
}