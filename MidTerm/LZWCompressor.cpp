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
    // set index to number of initial characters
    if(readK()){
        fW = fTable.lookupStart(fK); // set the prefix omega(fW)
        fCurrentCode = nextCode();
    }
}
uint16_t LZWCompressor::nextCode(){
    // Read the first character of the input
    if(fK == -1){
        return -1;
    }
        while (readK() && fK != -1) {
            PrefixString aWK = fW + fK;
            if (fTable.contains(aWK)) { // if wk is in table
                fW = aWK; // update prefix string to wk
            }
            else { // wk not in table
                uint16_t code = fW.getCode(); // get code for current prefix string
                std::cout << "CODE" << code << std::endl;
                fTable.add(aWK); // add wk to table
                fW = aWK; // set prefix string to omega(k)
                return code; // signal to output code for previous prefix string
            }
        // return code for last prefix string
        return fW.getCode();
    }
}
LZWCompressor::LZWCompressor(const std::string& aInput) : fInput(aInput), fIndex(0), fK(-1), fCurrentCode(0){
    start();
}
const uint16_t& LZWCompressor::operator*() const noexcept{
    return fCurrentCode;
}

LZWCompressor& LZWCompressor::operator++() noexcept{
    fCurrentCode = nextCode();
    return *this;
}
LZWCompressor LZWCompressor::operator++(int) noexcept{
    LZWCompressor temp = (*this);
    fCurrentCode = nextCode();
    return temp;
}
bool LZWCompressor::operator==( const LZWCompressor& aOther ) const noexcept{
    return (this->fInput == aOther.fInput &&
            this->fIndex == aOther.fIndex &&
            this->fCurrentCode == aOther.fCurrentCode &&
            this->fK == aOther.fK);
}
bool LZWCompressor::operator!=( const LZWCompressor& aOther ) const noexcept{
    return !((this->fInput == aOther.fInput &&
              this->fIndex == aOther.fIndex &&
              this->fCurrentCode == aOther.fCurrentCode &&
              this->fK == aOther.fK));
}
LZWCompressor LZWCompressor::begin() const noexcept {
    LZWCompressor iter(*this); // make a copy of the current object
    iter.fIndex = 0; // reset the index to the beginning of the input string
    return iter;
}
LZWCompressor LZWCompressor::end() const noexcept {
    LZWCompressor end(fInput);
    end.fCurrentCode = -1;
    return end;
}







