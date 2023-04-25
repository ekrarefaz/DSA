#include <iostream>
#include "InsertionSort.h"
#include "SelectionSort.h"

void testInsertionSort()
{
    int lArray[] = {45, 34, 8, 6, 4, 1, 0, -2, -3, -100};
    const size_t lSize = sizeof(lArray)/sizeof(int);
    InsertionSort lSorter( lArray, lSize );
    std::cout << "Test InsertionSorter:" << std::endl;
    lSorter.printStage();
    lSorter();
    lSorter.printStage();
    std::cout << "Completed." << std::endl;
}
void testSelectionSort()
{
    int lArray[] = {45, 34, 8, 6, 4, 1, 0, -2, -3, -100};
    const size_t lSize = sizeof(lArray)/sizeof(int);
    SelectionSort lSorter( lArray, lSize );
    std::cout << "Test SelectionSorter:" << std::endl;
    lSorter.printStage();
    lSorter();
    lSorter.printStage();
    std::cout << "Completed." << std::endl;
}
int main() {
    testSelectionSort();
    return 0;
}
