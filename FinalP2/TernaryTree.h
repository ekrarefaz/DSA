
// COS30008, Final Exam, 2023

#pragma once

#include <memory>
#include <cassert>
#include <algorithm>

template<typename T>
class TernaryTree
{
public:
    
    using Node = std::unique_ptr<TernaryTree>;

public:

    TernaryTree( const T& aKey = T{} ) noexcept:
    fKey (aKey),
    fNodes{nullptr, nullptr, nullptr}
    {}

    TernaryTree( T&& aKey ) noexcept:
    fKey (std::move(aKey)),
    fNodes{nullptr, nullptr, nullptr}
    {}

    template<typename... Args>
    static Node makeNode( Args&&... args ){
        return std::make_unique<TernaryTree>(std::forward<Args>(args)...); // making a unique pointer
    }

    const T& operator*() const noexcept{
        return fKey;
    }

    TernaryTree& operator[]( size_t aIndex ) const{
        assert( aIndex < 3 );
        return *fNodes[aIndex];
    }

    void add( size_t aIndex, Node& aNode ){
        assert( aIndex < 3 && aNode); // check if valid index and node
        fNodes[aIndex] = std::move(aNode);
    }
    Node remove( size_t aIndex ){
        assert( aIndex < 3 );
        return std::move(fNodes[aIndex]);
    }

    bool leaf() const noexcept{
        return !fNodes[0] && !fNodes[1] && !fNodes[2];
    }
    size_t height() const noexcept{
        size_t lHeight = 0;
        for ( size_t i = 0; i < 3; i++ ) // check every node
        {
            if ( fNodes[i] ) // check if valid node
            {
                if( !fNodes[i]->leaf() ){ // check if leaf node or not
                    lHeight = std::max( lHeight, fNodes[i]->height() );
                }
            }
        }
        return lHeight + 1;
    }

private:

    T fKey;
    Node fNodes[3];
};

