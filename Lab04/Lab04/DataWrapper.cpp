//
//  DataWrapper.cpp
//  Lab04
//
//  Created by Ekrar Efaz on 17/3/23.
//

#include <fstream>
#include "DataWrapper.h"

DataWrapper::DataWrapper():fSize(0), fData(nullptr){}

DataWrapper::~DataWrapper(){
    delete fData;
}
bool DataWrapper::load(const std::string& aFileName)
{
    // Open the file input stream
    std::ifstream inFile(aFileName);

    if (!inFile.is_open()) {
        return false;
    }

    inFile >> fSize;

    // Allocate memory for the data map
    fData = new DataMap[fSize];

    // Fetch all value pairs
    for (size_t i = 0; i < fSize; ++i) {
        // Read a Map object from the input stream
        if (!(inFile >> fData[i])) {
            return false;
        }
    }

    // Close the file input stream
    inFile.close();
    return true;
}

size_t DataWrapper::size() const noexcept{
    return fSize;
}

const DataMap& DataWrapper::operator[](size_t aIndex) const
{
    // Check if index is within range
    if (aIndex >= fSize) {
        throw std::out_of_range("Index out of range");
    }
    
    // Return reference to DataMap object at given index
    return *(fData + aIndex);
}

