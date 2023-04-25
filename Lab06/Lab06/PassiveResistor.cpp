//
//  PassiveResistor.cpp
//  Lab06
//
//  Created by Ekrar Efaz on 17/4/23.
//

#include "PassiveResistor.h"

// auxiliary methods
// aValue >= 1000.0
bool PassiveResistor::mustScale( double aValue ) const noexcept{
    return aValue >= 1000;
}
// 1.0/1000.0
const double PassiveResistor::getMultiplier() const noexcept{
    return 1.0/1000.0;
}
// "Ohm"
const std::string PassiveResistor::getMajorUnit() const noexcept{
    return "Ohm";
}
// "OkM", the first letter means "no minor unit"
const std::string PassiveResistor::getMinorUnits() const noexcept{
    return "OkM";
}

// constructor with a default value
PassiveResistor::PassiveResistor( double aBaseValue ) noexcept{
    setBaseValue(aBaseValue);
}

// returns (frequency-independent) passive resistance value
double PassiveResistor::getReactance( double aFrequency ) const noexcept{
    return 0.0;
}
