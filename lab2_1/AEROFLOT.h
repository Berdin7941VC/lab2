#ifndef LAB2_1_AEROFLOT_H
#define LAB2_1_AEROFLOT_H

#include <iostream>
#include <string>

class AEROFLOT {
public:
    std::string getDestination();
    void setDestination(std::string value);
    int getFlightNumber();
    void setFlightNumber(int value);
    std::string getPlaneType();
    void setPlaneType(std::string value);
    friend std::ostream& operator<<(std::ostream& ostream, const AEROFLOT& aeroflot);
    friend std::istream& operator>>(std::istream& istream, AEROFLOT& aeroflot);
    void dataProcessing(int value);
    void addFlight();
    void printAircraft();
    void printAllData();
private:
    std::string destination;
    int flightNumber;
    std::string planeType;
};


#endif //LAB2_1_AEROFLOT_H
