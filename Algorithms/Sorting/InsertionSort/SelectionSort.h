//
// Created by Ekrar Efaz on 20/4/23.
//

#pragma once

#include <iostream>
#include <cstddef>
#include <cassert>
#include <functional>
#include <algorithm>

template <typename T>
class SelectionSort{
private:
    T* fArray;
    size_t fSize;
public:
    SelectionSort(T* aArray = nullptr, size_t aSize = 0):fArray(new T[aSize]),fSize(aSize){
            for (size_t i = 0; i < fSize; i++){
                fArray[i] = aArray[i];
            }
    }
    virtual ~SelectionSort(){
        assert(fArray != nullptr);
        delete[] fArray;
    }

    size_t getSize() const noexcept{
        return fSize;
    }

    const T& operator[](size_t aIndex) const{
        assert(aIndex<fSize);
        return fArray[aIndex];
    }

    void swap( size_t aLeftIndex, size_t aRightIndex ){
        assert(aLeftIndex < fSize);
        assert(aRightIndex < fSize);
        std::swap(aLeftIndex,aRightIndex);
    }

    void operator()(bool aPrintStage = true) noexcept {
        for (size_t i = 0; i < fSize - 1; i++) {
            for (size_t j = i + 1; j < fSize; j++) {
                T leastIndex = i;
                if(fArray[j] < fArray[leastIndex]){
                    leastIndex = j;
                }
                this->swap(leastIndex,i);
            }
            this->printStage();
        }
    }

    void printStage() const noexcept{
        std::cout << '[';
        for(size_t i = 0 ; i < this->getSize(); i++){
            std::cout << fArray[i] << ' ';
        }
        std::cout << ']' << std::endl;
    }
};
