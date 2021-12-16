#include <algorithm>
#include "AeroflotKeeper.h"

AeroflotKeeper::AeroflotKeeper() {
    std::cout << "Object AeroflotKeeper. Call a simple constructor\n\n";
    this->aeroflotKeeper = new AEROFLOT[10];
    this->arraySize = 10;
    this->tempKeep = 0;
}

AeroflotKeeper::~AeroflotKeeper() {
    std::cout << "Object AeroflotKeeper. Call destructor\n";
    delete [] this->aeroflotKeeper;
}

int comparator(AEROFLOT a, AEROFLOT b){
    return a.getDestination()[0] < b.getDestination()[0];
}

void AeroflotKeeper::dataProcessing(int value) {
    switch (value) {
        case 1: {
            AEROFLOT aeroflot;
            if(!aeroflot.addFlight()){
                addAeroflot(aeroflot);
                std::sort(aeroflotKeeper, aeroflotKeeper+tempKeep, comparator);
            }
            else {
                throw std::invalid_argument(
                        "Wrong plane data. Data should have the following form: \"destination, aircraft number, aircraft type\"\n");
            }
            break;
        }
        case 2: {
            if(!tempKeep){
                std::cout << "You have not aircraft\n";
                return;
            }
            std::cin.ignore(32676, '\n');
            std::cout << "Your aircraft types:\n";
            std::string aircrafts;
            for(int i=0;i<tempKeep;i++) {
                if(aircrafts.find(aeroflotKeeper[i].getAircraftType()) == std::string::npos) {
                    std::cout << "\t" << aeroflotKeeper[i].getAircraftType() << "\n";
                    aircrafts.append(aeroflotKeeper[i].getAircraftType());
                }
            }
            int number = 1;
            std::cout << "Enter an aircraft type:\n";
            std::string aircraft;
            std::getline(std::cin, aircraft);
            for(int i=0;i<tempKeep;i++){
                if(aeroflotKeeper[i].getAircraftType() == aircraft) {
                    std::cout << "This aircraft \"" << aeroflotKeeper[i].getAircraftType() << "\" serves:\n";
                    std::cout << "\t" << number << ": Flight number " << aeroflotKeeper[i].getFlightNumber()
                              << ", destination " << aeroflotKeeper[i].getDestination() << "\n";
                    number++;
                }
            }
            if(number == 1){
                std::cout << "The aircraft \"" << aircraft << "\" does not serve any flights\n";
            }
            break;
        }
        default:
            throw std::invalid_argument("Wrong number. Number should be from 1 to 3");
    }
}

void AeroflotKeeper::addAeroflot(AEROFLOT aeroflot) {
    if(this->tempKeep == this->arraySize-1){
        this->aeroflotKeeper[this->tempKeep] = aeroflot;
        AEROFLOT* newArray = new AEROFLOT[this->arraySize+10];
        for(int i=0;i<this->arraySize;i++)
            newArray[i] = this->aeroflotKeeper[i];
        delete[] this->aeroflotKeeper;
        this->aeroflotKeeper = newArray;
        this->arraySize += 10;
        this->tempKeep++;
    }
    else{
        this->aeroflotKeeper[this->tempKeep] = aeroflot;
        this->tempKeep++;
    }
}