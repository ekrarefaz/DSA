
// COS30008, Final Exam, 2023

#include "DSPStringIterator.h"

DSPStringIterator::DSPStringIterator( const DSPString& aCollection ) :
	fCollection( std::make_shared<DSPString>( aCollection ) ),
	fIndex( 0 )
{}

char DSPStringIterator::operator*() const noexcept // 4A
{
    assert(fIndex < fCollection->size());
    return (*fCollection)[fIndex];
}

DSPStringIterator& DSPStringIterator::operator++() noexcept // 4B
{
    assert(fIndex < fCollection->size());
    fIndex++;
    return *this;
}

DSPStringIterator DSPStringIterator::operator++( int ) noexcept
{
	DSPStringIterator old = *this;

	++(*this);

	return old;
}

DSPStringIterator& DSPStringIterator::operator--() noexcept // 4C
{
    assert( ! (fIndex < 0));
    fIndex--;
    return *this;
}

DSPStringIterator DSPStringIterator::operator--( int ) noexcept
{
	DSPStringIterator old = *this;

	--(*this);

	return old;
}

bool DSPStringIterator::operator==( const DSPStringIterator& aOther ) const noexcept // 4D
{
	return fIndex == aOther.fIndex && fCollection == aOther.fCollection;
}

bool DSPStringIterator::operator!=( const DSPStringIterator& aOther ) const noexcept
{
	return !(*this == aOther);
}

DSPStringIterator  DSPStringIterator::begin() const noexcept // 4E
{
	DSPStringIterator copyIterator = *this;
    copyIterator.fIndex = 0;

    return copyIterator;
}

DSPStringIterator DSPStringIterator::end() const noexcept // 4F
{
    DSPStringIterator copyIterator = *this;
    copyIterator.fIndex = fCollection->size();

    return copyIterator;
}

DSPStringIterator DSPStringIterator::rbegin() const noexcept // 4G
{
    DSPStringIterator copyIterator = *this;
    copyIterator.fIndex = fCollection->size() - 1;

    return copyIterator;
}

DSPStringIterator DSPStringIterator::rend() const noexcept // 4H
{
    DSPStringIterator copyIterator = *this;
    copyIterator.fIndex = -1;

    return copyIterator;
}
