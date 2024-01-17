//
//  PassengerOutputTable.hpp
//  Titanic
//
//  Created by The professor on 11/23/23.
//

#ifndef PassengerOutputTable_h
#define PassengerOutputTable_h
#include<iostream>
#include "Passenger.h"
#include "OutputTableRow.h"
namespace cs32{
class PassengerOutputTable{
public:
    PassengerOutputTable(std::vector< Passenger * > passengers);
    void setOutputField(Field f);
    void setDescription(std::string description);
    Field getOutputField();
    std::string getDescription();
    void display();
    
    size_t rowCount();
    OutputTableRow getRow(int index);
private:
    std::vector<Passenger* > mPassengerList;
    std::vector<OutputTableRow> mRows;
    Field mField;
    std::string mDescription;
};

}
#endif /* PassengerOutputTable_hpp */
