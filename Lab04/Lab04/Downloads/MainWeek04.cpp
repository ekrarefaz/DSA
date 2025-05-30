
// COS30008, Tutorial 4, 2023

#include <iostream>

#include "Map.h"

void testMap()
{
    using DataMap = Map<int,int>;
    
    DataMap lArray1[] = {{1,32}, {2,68}, {3,83}, {4,80}, {5,87}, {6,69}, {7,75}, {8, 52}};
    const size_t lSize1 = sizeof(lArray1)/sizeof(DataMap);
    int lArray2[] { 1, 2, 3, 0, 4, 5, 5, 6, 0, 7};
    const size_t lSize2 = sizeof(lArray2)/sizeof(int);

    for ( size_t i = 0; i < lSize1; i++ )
    {
        std::cout << "Key-value pair " << i << ": " << lArray1[i] << std::endl;
    }

    std::cout << "Test type conversion: ";
    
    for ( size_t i = 0; i < lSize2; i++ )
    {
        std::cout << static_cast<char>(lArray1[lArray2[i]]);
    }

    std::cout << std::endl;
}

#include "DataWrapper.h"

bool testDataWrapper1( DataWrapper& aWrapper, const std::string& aFileName )
{
    if ( !aWrapper.load( aFileName ) )
    {
        std::cerr << "Cannot load data file " << aFileName << std::endl;
        
        return false;
    }
    
    std::cout << "Data loaded." << std::endl;
    
    return true;
}

void basicIndexer( const DataWrapper& aWrapper )
{
    std::cout << "Using basic indexer: " << std::endl;
    
    for ( size_t i = 0; i < aWrapper.size(); i++ )
    {
        std::cout << static_cast<char>(aWrapper[i]);
    }

    std::cout << std::endl;
}

void lambdaIndexer( const DataWrapper& aWrapper )
{
    std::cout << "Using lambda with ordered mapping logic: " << std::endl;
    
    auto lOrderedMapper = [&aWrapper] (size_t aIndex) -> char
    {
		
		// Problem 3
		
    };
    
    for ( size_t i = 0; i < aWrapper.size(); i++ )
    {
        std::cout << lOrderedMapper( i );;
    }

    std::cout << std::endl;
}

int main( int argc, char* argv[] )
{
    testMap();

    if ( argc != 2 )
    {
        std::cerr << "Arguments missing." << std::endl;
        std::cerr << "Usage: Lab04 <filename>" << std::endl;
        
        return 1;
    }
    
    DataWrapper lWrapper;
    
    if ( testDataWrapper1( lWrapper, argv[1] ) )
    {
        basicIndexer( lWrapper );        
        lambdaIndexer( lWrapper );
        
        return 0;
    }

    return 2;
}
