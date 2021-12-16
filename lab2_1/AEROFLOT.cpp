#include "AEROFLOT.h"

AEROFLOT::AEROFLOT(){
    this->flightNumber = 0;
    std::cout << "Object AEROFLOT. Call simple constructor\n";
}

AEROFLOT::AEROFLOT(std::string _destination, int _flightNumber, std::string _planeType) : destination(_destination),
                                                                                          flightNumber(_flightNumber),
                                                                                          planeType(_planeType) {
    std::cout << "Object AEROFLOT. Call constructor with parameters\n";
}

AEROFLOT::AEROFLOT(const AEROFLOT &aeroflot) : destination(aeroflot.destination), flightNumber(aeroflot.flightNumber),
                                               planeType(aeroflot.planeType) {
    std::cout << "Object AEROFLOT. Call copy constructor\n";
}

AEROFLOT::~AEROFLOT() {
    std::cout << "Object AEROFLOT. Call destructor\n";
}

std::string AEROFLOT::getDestination() {
    return this->destination;
}

void AEROFLOT::setDestination(std::string value) {
    this->destination = value;
}

int AEROFLOT::getFlightNumber() {
    return this->flightNumber;
}

void AEROFLOT::setFlightNumber(int value) {
    this->flightNumber = value;
}

std::string AEROFLOT::getAircraftType() {
    return this->planeType;
}

void AEROFLOT::setAircraftType(std::string value) {
    this->planeType = value;
}

std::ostream& operator<<(std::ostream& ostream, const AEROFLOT& aeroflot) {
    ostream << "Destination: " << aeroflot.destination << "\nPlane number: " << aeroflot.flightNumber
            << "\nPlane type: " << aeroflot.planeType << "\n";

    return ostream;
}

std::istream& operator>>(std::istream& istream, AEROFLOT& aeroflot){
    istream >> aeroflot.destination;
    istream >> aeroflot.flightNumber;
    istream >> aeroflot.planeType;

    return istream;
}

int AEROFLOT::addFlight() {
    std::cin.ignore(32767, '\n');
    std::cout << "Print next data separated by commas: destination, plane number and plane type\n";

    std::string input;
    std::getline(std::cin, input);
    int wordCount = 0;
    std::string tempValue;

    for(char i : input){
        if(i == ' '){
            continue;
        }
        if(i == ','){
            if(wordCount == 0){
                this->destination = tempValue;
                wordCount++;
                tempValue.clear();
            }
            else if(wordCount == 1){
                this->flightNumber = std::stoi(tempValue);
                wordCount++;
                tempValue.clear();
            }
        }
        else{
            tempValue.push_back(i);
        }
    }
    if(wordCount == 2) {
        this->planeType = tempValue;
        return 0;
    }
    else return 1;
}