//
// Created by Ekrar Efaz on 26/4/23.
//
#include <iostream>

#include "LZWCompressor.h"

bool LZWCompressor::readK() noexcept{
    if(fIndex < fInput.length()){
        fK = fInput[fIndex++];
        return true;
    }
    else{
        return false;
    }
}
void LZWCompressor::start(){
    fTable.initialize(); // call initialize
    if(readK()){
        fW = PrefixString(fK); // set the prefix omega(fW)
        fCurrentCode = nextCode();
    }
}
uint16_t LZWCompressor::nextCode(){
    // Read the first character of the input
    if(!readK()){
        // If there is no input left, set the current code to the prefix string in fW and return -1
        fCurrentCode = fW.getCode();
        return -1;
    }
}


