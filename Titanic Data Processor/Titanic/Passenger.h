//
//  Passenger.hpp
//  Titanic
//
//  Created by The professor on 11/12/23.
//
#include <iostream>
#include <string>
#include "Enums.h"
#include <algorithm>
#ifndef Passenger_h
#define Passenger_h

namespace cs32 {
class Passenger{
public:
    Passenger();
    // setters
    void setName(std::string name);
    void setEmbarcation(std::string embarked);
    void setClass(std::string classofFare);
    void setSurvived(std::string survived);
    void setFare(std::string fare);
    
    // getters
    std::string getName();
    Embarcation getEmbarcation();
    Class getClass();
    bool getSurvived();
    double getFare();
    
    
    
private:
    Class mClass;
    Embarcation mEmbarked;
    std::string mName;
    bool mSurvived;
    double mFare;
    
};
}

#endif 
