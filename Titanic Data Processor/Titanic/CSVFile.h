//
//  CSVFile.hpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//

#ifndef CSVFILE_H
#define CSVFILE_H

#include <map>
#include <string>
#include "DataCollectorCallback.h"

namespace cs32
{

/*
 A class provided to CS32 students to read a CSV file
 If hasHeaders, the first line of the file must be a line of field headers
 If combineQuotedFields, commas when found inside quotes are not treated as separators
 If no header is supplied, the data fields will be named field0, field1, field2, ...
 */
class CSVFile
{
public:
    CSVFile( DataCollectorCallback * callback, bool hasHeaders = true, bool combineQuotedFields = true );
    
    /* reads stated file, returns number of rows read */
    /* for each row found, it will invoke the DataCollecorCallback::csvData( ... ) */
    int readFile( std::string filePath );
    
private:
    DataCollectorCallback * mCollector;
    bool mHasHeaders;
    bool mCombineQuotedFields;
    bool debug;
    
    // does s start with the prefix value?
    bool startsWith( std::string s, std::string value );
    // does s end with suffix value?
    bool endsWith( std::string s, std::string value );

};

}

#endif
