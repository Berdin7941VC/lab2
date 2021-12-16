#include <iostream>

#include "AEROFLOT.h"

void printFirstInformation(){
    std::cout << "\nWant you want to do?";
    std::cout << "1. Add flight\n";
    std::cout << "2. Display destinations and flight numbers of the aircraft\n";
    std::cout << "3. Display all entries\n";
    std::cout << "4. Exit\n";
}

int main() {
    AEROFLOT aeroflot;

    int choiser;
    std::cout << "Hello!\n\n";

    while(true) {
        printFirstInformation();
        std::cout << "Write a number: ";
        std::cin >> choiser;
        std::cout << "\n";
        if(choiser == 3){
            std::cout << "Bye\n";
            break;
        }

    }

    return 0;
}