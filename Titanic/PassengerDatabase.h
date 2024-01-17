//
//  PassengerDatabase.hpp
//  Titanic
//
//  Created by The professor on 11/12/23.
//

#ifndef PassengerDatabase_h
#define PassengerDatabase_h
#include<iostream>
#include <map>
#include "Passenger.h"
#include "CSVFile.h"
#include "DataCollectorCallback.h"

namespace cs32{

class PassengerDatabase: public DataCollectorCallback{
public:
    // Resource management
    PassengerDatabase();
    ~PassengerDatabase();
    int load( std::string filePath );
    void clearAllPassengers();
    bool loaded();
    Passenger* getPassenger_byName( std::string name );
    std::vector< Passenger * > getPassengers();
    std::vector< Passenger * > getPassengers_byClass(Class paidClass, bool Survived, double minimumFare);
    std::vector< Passenger * > getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare);
    // part of the DataCollectorCallback Interface
    virtual void csvData( std::map< std::string, std::string> row );
private:
    std::vector< Passenger * > passengers;
    bool isLoaded;
    
};
}

#endif /* PassengerDatabase_hpp */
