//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by The professor on 11/23/23.
//

#include "PassengerOutputTable.h"

//Yes, I am expecting getPercentage to be a value between 0 and 1.  When displayed within the PassengerOutputTable, I am expecting your code to multiply that percentage by 100 when calls to OutputTableRow::display( ) are executed.


namespace cs32 {
PassengerOutputTable::PassengerOutputTable(std::vector< Passenger * > passengers): mPassengerList(passengers),mRows(),  mField(Field::NOVALUE), mDescription(""){
}

void PassengerOutputTable::setOutputField(Field f){
    mField = f;
}
void PassengerOutputTable::setDescription(std::string description){
    mDescription = description;
}
Field PassengerOutputTable::getOutputField(){
    return mField;
}
std::string PassengerOutputTable::getDescription(){
    return mDescription;
}

void PassengerOutputTable::display(){
    // clearing before
    mRows.clear();
    if(mField == Field::NOVALUE){
        return;
    }
    std::cout << mDescription << std::endl;
    std::cout << std::setw(42) << std::right << "Suvived/Total"
              << std::setw(20) << std::right << "%"
              << std::endl;
//
    
    // figuring out how many rows
    int loopLimit = (getOutputField() == Field::BYCLASS || getOutputField() == Field::BYEMBARCATION) ? 4 : 5;
    for (int i = 0; i < loopLimit; i++) {
        OutputTableRow row;
        // Your code to populate 'row', if needed
        mRows.push_back(row);
    }
    
 //switch to switch between different output fields
    switch (getOutputField()) {
            
            // basically initalize in each case, the number of rows with there desicriptions, I then iterate over the list of passengers, to see if there class,fare, etc matches, and set the survive and total.
        case Field::BYCLASS:
            mRows[0].setDescription("First Class  -");
            mRows[1].setDescription("Second Class -");
            mRows[2].setDescription("Third Class  -");
            mRows[3].setDescription("Not Known    -");
            for (auto iter = mPassengerList.begin(); iter != mPassengerList.end(); ++iter) {
                if((*iter)->getClass() == Class::FIRST){
                    mRows[0].setTotal(mRows[0].getTotal() + 1);
                    if((*iter)->getSurvived() == true){
                        mRows[0].setSurvived(mRows[0].getSurvived() + 1);
                    }
                }
                 if((*iter)->getClass() == Class::SECOND){
                     mRows[1].setTotal(mRows[1].getTotal() + 1);
                     if((*iter)->getSurvived() == true){
                         mRows[1].setSurvived(mRows[1].getSurvived() + 1);
                     }
                 }
                 if((*iter)->getClass() == Class::THIRD){
                     mRows[2].setTotal(mRows[2].getTotal() + 1);
                     if((*iter)->getSurvived() == true){
                         mRows[2].setSurvived(mRows[2].getSurvived() + 1);
                     }
                }  if((*iter)-> getClass() == Class::NOTKNOWN){
                    mRows[3].setTotal(mRows[3].getTotal() + 1);
                    if((*iter)->getSurvived() == true){
                        mRows[3].setSurvived(mRows[3].getSurvived() + 1);
                    }
                }
            
            }
            break;
            
            
        case Field::BYEMBARCATION:
            mRows.at(0).setDescription("Cherbourg- ");
            mRows.at(1).setDescription("Queenstown- ");
            mRows.at(2).setDescription("Southhampton- ");
            mRows.at(3).setDescription("Not Known-");
            for (auto iter = mPassengerList.begin(); iter != mPassengerList.end(); ++iter) {
                if((*iter)->getEmbarcation() == Embarcation::CHERBOURG){
                    mRows.at(0).setTotal(mRows.at(0).getTotal() + 1);
                    if((*iter)->getSurvived() == true){
                        mRows.at(0).setSurvived(mRows.at(0).getSurvived() + 1);
                   
                    }
                }
                 if((*iter)->getEmbarcation() == Embarcation::QUEENSTOWN){
                     mRows.at(1).setTotal(mRows.at(1).getTotal() + 1);
                     if((*iter)->getSurvived() == true){
                         mRows.at(1).setSurvived(mRows.at(1).getSurvived() + 1);
                     }
                 }
                 if((*iter)->getEmbarcation() == Embarcation::SOUTHHAMPTON){
                     mRows.at(2).setTotal(mRows.at(2).getTotal() + 1);
                     if((*iter)->getSurvived() == true){
                         mRows.at(2).setSurvived(mRows.at(2).getSurvived() + 1);
                     }
                }  if((*iter) -> getEmbarcation() == Embarcation::NOTKNOWN){
                    mRows.at(3).setTotal(mRows.at(3).getTotal() + 1);
                    if((*iter)->getSurvived() == true){
                        mRows.at(3).setSurvived(mRows.at(3).getSurvived() + 1);
                    }
                }
            
            }
            break;
        case Field::BYFARE:
            mRows[0].setDescription("Not Known-");
            mRows[1].setDescription("$ 1-$10-");
            mRows[2].setDescription("$10-$25-");
            mRows[3].setDescription("$25-$50-");
            mRows[4].setDescription("   >$50-");
            for (auto iter = mPassengerList.begin(); iter != mPassengerList.end(); ++iter) {
                if((*iter) -> getFare() == 0.0){
                    mRows[0].setTotal(mRows[0].getTotal() + 1);
                       if((*iter)->getSurvived() == true){
                           mRows[0].setSurvived(mRows[0].getSurvived() + 1);
                       }
               }
                if((*iter)->getFare() > 0 && (*iter)->getFare() <= 10){
                    mRows[1].setTotal(mRows[1].getTotal() + 1);
                    if((*iter)->getSurvived() == true){
                        mRows[1].setSurvived(mRows[1].getSurvived() + 1);
                    }
                }
                
                 if((*iter)->getFare() > 10 && (*iter)->getFare() <= 25){
                     mRows[2].setTotal(mRows[2].getTotal() + 1);
                     if((*iter)->getSurvived() == true){
                         mRows[2].setSurvived(mRows[2].getSurvived() + 1);
                     }
                 }
                
                
                 if((*iter)->getFare() > 25 && (*iter)->getFare() <= 50){
                     mRows[3].setTotal(mRows[3].getTotal() + 1);
                     if((*iter)->getSurvived() == true){
                         mRows[3].setSurvived(mRows[3].getSurvived() + 1);
                     }
                }
                
                if((*iter)->getFare() > 50){
                    mRows[4].setTotal(mRows[4].getTotal() + 1);
                    if((*iter)->getSurvived() == true){
                        mRows[4].setSurvived(mRows[4].getSurvived() + 1);
                    }
                }
            }
            break;
        default:
            break;
    }
    
    for(int i = 0; i < rowCount(); i++){
        mRows[i].display();
        std::cout << std::endl;
    }



}


size_t PassengerOutputTable::rowCount() {
    return mRows.size();
}


// dont worry about out of bounds!
OutputTableRow PassengerOutputTable::getRow(int index) {
    return mRows.at(index);
}

}
