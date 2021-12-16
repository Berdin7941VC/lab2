#include "AEROFLOT.h"

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

std::string AEROFLOT::getPlaneType() {
    return this->planeType;
}

void AEROFLOT::setPlaneType(std::string value) {
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

void AEROFLOT::dataProcessing(int value) {
    switch (value) {
        case 1:
            this->addFlight();
            break;
        case 2:
            this->printAircraft();
            break;
        case 3:
            this->printAllData();
            break;
        default:
            std::cerr << "Error: Wrong number. Number should be from 1 to 4!";
    }
}
