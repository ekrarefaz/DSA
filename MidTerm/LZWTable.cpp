//
// Created by Ekrar Efaz on 26/4/23.
//
#include <cassert>
#include <iostream>

#include "LZWTable.h"

LZWTable::LZWTable( uint16_t aInitialCharacters){
    // task constraint 128 single character prefix strings
    if(aInitialCharacters <= 128){
        fInitialCharacters = aInitialCharacters;
    }
    else{
        fInitialCharacters = 128;
    }
    initialize();
}

void LZWTable::initialize(){
    // loop for the number of initial characters
    for(size_t i = 0; i < fInitialCharacters; i++){
        PrefixString aPrefixString(static_cast<char>(i));

        // set the code to its corresponding entry in ASCII table
        aPrefixString.setCode(i);
        fEntries[i] = aPrefixString;
    }
    // set the index to the number of initial characters added
    fIndex = fInitialCharacters;
}

const PrefixString& LZWTable::lookupStart( char aK ) const noexcept{
    // assertion required to check if out of bounds
    assert(static_cast<uint16_t>(aK) < fInitialCharacters);
    // implicit conversion happens from char to uint_16
    return fEntries[aK];
}

bool LZWTable::contains( PrefixString& aWK ) const noexcept{
    // assert that the prefix string is valid argument
    assert(aWK.w() < fInitialCharacters);
    size_t i = fIndex;
    while(i >= aWK.w()){
        if(aWK.w() == fEntries[i].w()){
            aWK = fEntries[i];
            return true;
        }
        i--;
    }
    return false;
}

void LZWTable::add( PrefixString& aWK ) noexcept{
    assert(aWK.w() < fInitialCharacters);
    aWK.setCode(fIndex);
    fEntries[fIndex++] = aWK;
}
