//
//  CharacterCounter.cpp
//  Assignment2
//
//  Created by Ekrar Efaz on 4/4/23.
//

#include "CharacterCounter.h"

CharacterCounter::CharacterCounter() noexcept : fTotalNumberOfCharacters(0)
{
    for (int i = 0; i < 256; ++i)
    {
        fCharacterCounts[i] = CharacterMap(i,0);
    }
}

// Increment the frequency of the given character
void CharacterCounter::count(unsigned char aCharacter) noexcept
{
    fCharacterCounts[aCharacter].setCharacter(aCharacter);
    fCharacterCounts[aCharacter].increment();
    ++fTotalNumberOfCharacters;
}

// Return the CharacterMap object corresponding to the given character
const CharacterMap& CharacterCounter::operator[](unsigned char aCharacter) const noexcept
{
    return fCharacterCounts[aCharacter];
}


