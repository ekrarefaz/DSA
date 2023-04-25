//
// Created by Ekrar Efaz on 20/4/23.
//

#pragma once

#include <cstddef>
#include <cassert>
#include <functional>
#include <algorithm>

template <typename T>
class InsertionSort{

private:
    T* aArray;
    size_t aSize;

public:
    InsertionSort(T* fArray = nullptr, size_t fSize = 0):aArray(new T[fSize]),aSize(fSize){
        for (size_t i = 0; i < aSize; i++){
            aArray[i] = fArray[i];
        }
    }
    virtual ~InsertionSort(){
        assert(aArray != nullptr);
        delete[] aArray;
    }

    size_t getSize() const noexcept{
        return aSize;
    }

    const T& operator[](size_t aIndex) const{
        assert(aIndex<aSize);
        return aArray[aIndex];
    }

    void swap( size_t aLeftIndex, size_t aRightIndex ){
        assert(aLeftIndex < aSize);
        assert(aRightIndex < aSize);
        std::swap(aLeftIndex,aRightIndex);
    }

    void operator()(bool aPrintStage = true) noexcept
    {
        std::cout << "In Sorting Process" << std::endl;
        for(size_t i = 1; i < aSize; i++){
            T temp = aArray[i];
            size_t j = i;
            while(j>0 && temp < aArray[j-1] ){
                aArray[j] = aArray[j-1];
                j--;
            }
            aArray[j] = temp;
            this->printStage();
        }
    }

    void printStage() const noexcept{
        std::cout << '[';
        for(size_t i = 0 ; i < this->getSize(); i++){
            std::cout << aArray[i] << ' ';
        }
        std::cout << ']' << std::endl;
    }
};
