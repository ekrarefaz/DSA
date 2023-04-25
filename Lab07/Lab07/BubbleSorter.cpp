////
////  BubbleSorter.cpp
////  Lab07
////
////  Created by Ekrar Efaz on 18/4/23.
////
//
//#include "BubbleSorter.h"
//
//template<typename T>
//
//BubbleSorter<T>::BubbleSorter( T* aCollection, size_t aSize ):BaseSorter<T>(aCollection, aSize){}
//template<typename T>
//template<typename C>
//void BubbleSorter<T>::operator()( bool aPrintStage , C aIsOutOfOrder ) noexcept{
//    size_t aSize = this->size() - 1;
//    while(aSize > 0){
//        size_t BOUND = aSize;
//        aSize = 0;
//        
//        for ( size_t j = 0; j < BOUND; j++ )
//        {
//            if ( aIsOutOfOrder( this->operator[](j), this->operator[](j-1) ) )
//            {
//                this->swap(this->operator[](j), this->operator[](j-1));
//                aSize = j;
//            }
//        }
//    }
//}
