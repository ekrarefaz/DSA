
// COS30008, Tutorial 7, 2023

#pragma once

#include "BaseSorter.h"

template<typename T>
class BubbleSorter : public BaseSorter<T>
{
public:
    
    BubbleSorter( T* aCollection = nullptr, size_t aSize = 0 );
        
    template<typename C = std::greater<T>>
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept;
};

template<typename T>
BubbleSorter<T>::BubbleSorter( T* aCollection, size_t aSize ):BaseSorter<T>(aCollection, aSize){}

template<typename T>
template<typename C>
void BubbleSorter<T>::operator()( bool aPrintStage , C aIsOutOfOrder ) noexcept{
    size_t aSize = this->size() - 1;
    while(aSize > 0){
        size_t BOUND = aSize;
        aSize = 0;
        
        for ( int j = 0; j < BOUND; j++ )
        {
            if ( aIsOutOfOrder( this->operator[](j), this->operator[](j+1) ) )
            {
                this->swap(j, j+1);
                aSize = j;
            }
            if(aPrintStage){
                this->printStage(2);
            }
        }
    }
}
