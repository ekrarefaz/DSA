//
// Created by Ekrar Efaz on 26/4/23.
//

#include <iostream>
#include "LZWCompressor.h"

bool LZWCompressor::readK() noexcept{
    //Code to read input character from fInput
    if (fIndex >= fInput.length()) {
        fK = -1;
        return false;
    }
    fK = fInput[fIndex];
    return true;
}
void LZWCompressor::start(){
    //Code to read the first character from fInput
    if(readK()){
        fTable.initialize();
        //Code to initialize fW
        fW = fTable.lookupStart(fK);
        fCurrentCode = nextCode();
    }
}
uint16_t LZWCompressor::nextCode() {
    if (fK == -1) {
        return -1;
    }
    while (readK() && fK != -1) {
        // Code to check if fW + fK is in the table
        PrefixString aWK = fW + fK;
        if (fTable.contains(aWK)) {
            // Code to set fW to fW + fK
            fW = aWK;
        }
        else {
            // Code to add fW + fK to the table
            fTable.add(aWK);
            // Code to output the code for fW
            fW = fTable.lookupStart(fK);
            return fW.getCode();
        }
    }
    return fW.getCode();
}

LZWCompressor::LZWCompressor(const std::string& aInput) : fInput(aInput), fIndex(0), fK(-1), fCurrentCode(0){
    start();
}
const uint16_t& LZWCompressor::operator*() const noexcept{
    return fCurrentCode;
}
LZWCompressor& LZWCompressor::operator++() noexcept {
    if (fIndex >= fInput.length()) {
        return *this; // already at the end
    }
    fCurrentCode = nextCode();
    fIndex++;
    return *this;
}
LZWCompressor LZWCompressor::operator++(int) noexcept {
    LZWCompressor temp = *this;
    ++(*this);
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
    iter.start();
    iter.fIndex = 0;
    return iter;
}
LZWCompressor LZWCompressor::end() const noexcept {
    LZWCompressor iter(fInput);
    iter.fIndex = fInput.length();
    return iter;
}








