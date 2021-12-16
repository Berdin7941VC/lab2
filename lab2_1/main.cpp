#include <iostream>

#include "AEROFLOT.h"
#include "AeroflotKeeper.h"

void printFirstInformation(){
    std::cout << "\nWant you want to do?\n";
    std::cout << "1. Add flight\n";
    std::cout << "2. Display destinations and flight numbers of the aircraft\n";
    std::cout << "3. Exit\n";
}



int main() {
    AeroflotKeeper aeroflotKeeper;

    int choiser;
    std::cout << "Hello!\n";

    while(true) {
        printFirstInformation();
        std::cout << "Write a number: ";
        std::cin >> choiser;
        std::cout << "\n";
        if(choiser == 3){
            std::cout << "Bye\n";
            break;
        }
        try {
            aeroflotKeeper.dataProcessing(choiser);
        }
        catch(std::invalid_argument error) {
            std::cerr << error.what();
        }
    }

    return 0;
}