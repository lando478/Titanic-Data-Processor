//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by The professor on 11/12/23.
//

#include "PassengerDatabase.h"

namespace cs32{
PassengerDatabase::PassengerDatabase(): isLoaded(false){
   // isLoaded is false when that count is zero

}


PassengerDatabase::~PassengerDatabase(){
    clearAllPassengers();
}

int PassengerDatabase::load( std::string filePath ){
    CSVFile file(this);
    int recordCount = file.readFile(filePath);
    if(recordCount > 0){
        isLoaded = true;
    }
    return recordCount;
}

void PassengerDatabase::clearAllPassengers() {
    for (Passenger* passenger : passengers) {
          delete passenger;
      }
      passengers.clear();  // Clear the vector
//
    
//    std::vector<Passenger*>::iterator iter = passengers.begin();
//    while(iter != passengers.end()){
//        delete (*iter);
//        iter = passengers.erase(iter);
//    }
}

bool PassengerDatabase::loaded(){
    return (isLoaded);
    
}



Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
 //you can safely assume names will be unique and not duplicated.
// If the getPassenger_byName( ... ) search fails to locate anyone with the matching name, it should return nullptr."
    for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        if ((*it)->getName() == name) {
            return *it; // Found a matching passenger
        }
    }
    return nullptr; // No matching passenger found
}

std::vector<Passenger*> PassengerDatabase::getPassengers() {
    return passengers;
}


std::vector<Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool Survived, double minimumFare) {
    std::vector<Passenger*> classPassengers; // Use a vector of pointers
    for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        // Use (*it) to access the pointer to a Passenger in the vector
        if ((*it)->getClass() == paidClass && (*it)->getSurvived() == Survived && (*it)->getFare() > minimumFare) {
            classPassengers.push_back(*it); // Push the pointer to the matching passenger
        }
    }
    return classPassengers; // Return the vector of matching passengers
}


std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare) {

    std::vector<Passenger*> PassengersByEmbarcation; // Use a vector of pointers
    for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        // Use (*it) to access the pointer to a Passenger in the vector
        if ((*it)->getEmbarcation() == embarked && (*it)->getSurvived() == Survived && (*it)->getFare() > minimumFare) {
            PassengersByEmbarcation.push_back(*it); // Push the pointer to the matching passenger
        }
    }
    return PassengersByEmbarcation; // Return the vector of matching passengers
}



// Implementation of the DataCollectorCallback interface
void PassengerDatabase::csvData(std::map<std::string, std::string> row) {
    Passenger* newPassenger = new Passenger();
    newPassenger -> setName(row["name"]);
    newPassenger -> setClass(row["pclass"]);
    newPassenger -> setEmbarcation(row["embarked"]);
    newPassenger -> setSurvived(row["survived"]);
    newPassenger -> setFare(row["fare"]);
    passengers.push_back(newPassenger);
}




}
