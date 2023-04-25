
// COS30008, Tutorial 7, 2023

#pragma once

#include "BaseSorter.h"
#include <random>
#include <cstdlib>
#include <ctime>

template<typename T>
class FisherAndYatesSorter : public BaseSorter<T>
{
private:
    
    void shuffle() noexcept{
        size_t n = this->size();
        while (n > 1){
            int aRandNum = std::rand() % n;
            n--;
            this->swap(n,aRandNum);
        }
    }
    
//    template<typename C = std::greater<T>>
//    bool isSorted( C aIsOutOfOrder ) const noexcept{
//        size_t aSize = this->size();
//        while(aSize > 0){
//            size_t BOUND = aSize;
//            aSize = 0;
//
//            for ( int j = 0; j < BOUND; j++ )
//            {
//                if ( aIsOutOfOrder( this->operator[](j), this->operator[](j+1) ) ){
//                    return false;
//                }
//                aSize = j;
//            }
//        }
//        return true;
//    }
    
    template<typename C = std::greater<T>>
    bool isSorted( C aIsOutOfOrder ) const noexcept{
        size_t aSize = this->size();
        for(size_t i = 1; i < aSize; i++)
        {
            if(aIsOutOfOrder((this->operator[](i-1)),this->operator[](i))){
                return false;
            }
        }
        return true;
    }
    
public:
    
    FisherAndYatesSorter( T* aCollection = nullptr, size_t aSize = 0 ):BaseSorter<T>(aCollection,aSize)
    {
        std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
    }

    template<typename C = std::greater<T>>
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept
    {
        bool isSorted = false;
        
        do{
            isSorted = this->isSorted(aIsOutOfOrder);
            
            if( aPrintStage )
            {
                this->printStage(2);
            }
            
            if(!isSorted){
                this->shuffle();
            }
            
        }while(!isSorted);
    }
};
