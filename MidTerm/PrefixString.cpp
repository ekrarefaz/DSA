//
// Created by Ekrar Efaz on 25/4/23.
//
#include <cassert>

#include "PrefixString.h"


PrefixString::PrefixString( char aExtension ) noexcept:
        // static cast necessary because uintt16_t representation of -1 required
        fCode{ static_cast<uint16_t>(-1) }, fPrefix{ static_cast<uint16_t>(-1) }, fExtension{ aExtension }
{}
PrefixString::PrefixString( uint16_t aPrefix, char aExtension ) noexcept:
        fCode{ static_cast<uint16_t>(-1) }, fPrefix{ aPrefix }, fExtension{ aExtension }
{}

uint16_t PrefixString::getCode() const noexcept{
    return fCode;
}
void PrefixString::setCode( uint16_t aCode ) noexcept{
    fCode = aCode;
}

uint16_t PrefixString::w() const noexcept{
    return fPrefix;
}

char PrefixString::K() const noexcept{
    return fExtension;
}

PrefixString PrefixString::operator+( char aExtension ) const noexcept{
    assert(fCode != static_cast<uint16_t>(-1)); // ensuring operation allowed on present strings in table
    return PrefixString(fCode,aExtension);
}

bool PrefixString::operator==( const PrefixString& aOther ) const noexcept{
    return (this->fPrefix == aOther.fPrefix && this->fExtension == aOther.fExtension);
}

std::ostream& operator<<( std::ostream& aOStream, const PrefixString& aObject ){
    return aOStream << "(" << aObject.fCode << "," << aObject.fPrefix << "," << aObject.fExtension << ")";
}

