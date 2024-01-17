//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by The professor on 11/25/23.
//

#include "OutputTableRow.h"
namespace cs32 {
OutputTableRow::OutputTableRow(): mDescription(""), mSurvived(0.0), mTotal(0.0){
    
}
void OutputTableRow::setDescription(std::string description){
    mDescription = description;
}
void OutputTableRow::setSurvived(int survived){
    mSurvived = survived;
}
void OutputTableRow::setTotal(int total){
    mTotal = total;
}
std::string OutputTableRow::getDescription(){
    return  mDescription;
}
int OutputTableRow::getSurvived(){
    return mSurvived;
}
int OutputTableRow::getTotal(){
    return mTotal;;
}
double OutputTableRow::getPercentage() {
    if(mTotal == 0){
        return 0.0;
    }else{
        double result = double(mSurvived) / mTotal;
        return result;
    }
}


void OutputTableRow::display(){
    // formating to look good. 
    std::cout << std::setw(20) << std::left << getDescription()
                 << std::setw(10) << std::right << getSurvived()
                 << "     |      "
                 << std::setw(10) << std::left << getTotal()
                 << std::setw(10) << std::right << getPercentage()*100;
}

std::string OutputTableRow::padToThreeCharacters(int value){
    return ("   ");
    
}
}
