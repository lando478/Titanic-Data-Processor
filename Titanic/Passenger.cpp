#include "Passenger.h"

namespace cs32{
// default constructor
Passenger::Passenger():mClass(Class::NOTKNOWN), mEmbarked(Embarcation::NOTKNOWN), mName(""), mSurvived(false), mFare(0.0) {}


// Setter for passenger name
void Passenger::setName( std::string name ){
    if(name != ""){
        mName = name;
    } else{
        return;
    }
}


void Passenger::setEmbarcation( std::string embarked ){
    switch (embarked[0]) {
        case 'C':
            mEmbarked = Embarcation::CHERBOURG;
            break;
            
        case 'Q':
            mEmbarked = Embarcation::QUEENSTOWN;
            break;
            
        case 'S':
            mEmbarked = Embarcation::SOUTHHAMPTON;
            break;
            
        default:
            mEmbarked = Embarcation::NOTKNOWN;
            break;
    }
}

void Passenger::setClass( std::string classofFare ){
    switch (classofFare[0]) {
        case '1':
            mClass = Class::FIRST;
            break;
            
        case '2':
            mClass = Class::SECOND;
            break;
            
        case '3':
            mClass = Class::THIRD;
            break;
            
        default:
            mClass = Class::NOTKNOWN;
            break;
    }
}

void Passenger::setSurvived( std::string survived ){
    switch (survived[0]) {
        case '1':
            mSurvived = true;
            break;
            
        case '0':
            mSurvived = false;
            break;
        
        default:
            mSurvived = false;
            break;
    }
 
    
}

void Passenger::setFare( std::string fare ){
    if(fare.empty()){
        mFare = 0.0;
    }
    if (!fare.empty()){
        mFare = std::stof( fare );
    }

    
}

// getters
// getters
std::string Passenger::getName(){
    return mName;
}
Embarcation Passenger::getEmbarcation(){
    return mEmbarked;
}
Class  Passenger::getClass(){
    return mClass;
}
bool  Passenger::getSurvived(){
    return mSurvived;
}
double  Passenger::getFare(){
    return mFare;
}

}
