
// COS30008, Tutorial 10, 2023

#pragma once

#include <cassert>
#include <stdexcept>

#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator
{
public:
    using Iterator = DoublyLinkedListIterator<T>;
    using Node = typename DoublyLinkedList<T>::Node;

    enum class States
    {
        BEFORE,
        DATA,
        AFTER
    };
    
    DoublyLinkedListIterator( const Node& aHead, const Node& aTail ) noexcept:
        fHead( aHead ),
        fTail( aTail ),
        fCurrent( aHead ),
        fState( States::BEFORE )
    {
        assert(!fHead == !fTail);
        if(!fHead){
            fState = States::AFTER;
        }
    }
    const T& operator*() const noexcept{
        assert( fState == States::DATA );
        return fCurrent->fData;
    }

    Iterator& operator++() noexcept // prefix
    {
        switch ( fState )
        {
            case States::BEFORE:
                fCurrent = fHead;
                if ( fCurrent )
                {
                    fState = States::DATA;
                }
                else
                {
                    fState = States::AFTER;
                }
                break;
            case States::DATA:
                fCurrent = fCurrent->fNext;
                if ( !fCurrent )
                {
                    fState = States::AFTER;
                }
                break;
            case States::AFTER:
                break;
        }
        return *this;
    }
    Iterator operator++(int) noexcept{
        Iterator lTemp = *this;
        ++(*this);
        return lTemp;
    }
    
    Iterator& operator--() noexcept {
        switch(fState){
            case States::AFTER:
                fCurrent = fTail;
                if(fCurrent){
                    fState = States::DATA;
                }
                else{
                    fState = States::AFTER;
                }
                break;
            case States::DATA:
                fCurrent = fCurrent->fNext;
                if(!fCurrent){
                    fState = States::AFTER;
                }
                break;
            case States::BEFORE:
                break;
        }
        return *this;
    }
    Iterator operator--(int) noexcept{
        Iterator ltemp = *this;
        ++(*this);
        return ltemp;
    }

    bool operator==( const Iterator& aOther ) const noexcept{
        return (
                this->fCurrent == aOther.fCurrent &&
                this->fState == aOther.fState &&
                this->fHead == aOther.fHead &&
                this->fTail == aOther.fTail
        );
    }
    bool operator!=( const Iterator& aOther ) const noexcept{
        return !(*this == aOther);
    }
    
    Iterator begin() const noexcept{
        ++(rend());
    }
    Iterator end() const noexcept{
        Iterator ltemp = *this;
        ltemp.fState = States::AFTER;
        ltemp.fCurrent = nullptr;

        return ltemp;
    }
    Iterator rbegin() const noexcept{
        return --(end());
    }
    Iterator rend() const noexcept{
        Iterator ltemp = *this;
        ltemp.fState = States::BEFORE;
        ltemp.fCurrent = nullptr;

        return ltemp;
    }

private:
    Node fHead;
    Node fTail;
    Node fCurrent;
    States fState;
};
