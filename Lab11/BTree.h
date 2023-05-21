
// COS30008, Tutorial 11, 2023

#pragma once

#include <memory>
#include <cassert>
#include <iostream>

template<typename T>
class BTree
{
public:
	using Node = std::unique_ptr<BTree>;

	BTree( const T& aKey = T{} ) noexcept:
    fKey(aKey)
    {

    }

	BTree( T&& aKey ) noexcept:
    fKey(std::move(aKey))
    {

    }
    
	~BTree()
	{
		std::cout << "Delete " << fKey << std::endl;
	}
	
	template<typename... Args>
	static Node makeNode( Args&&... args ) noexcept
    {
        return std::make_unique<BTree>( std::forward<Args>( args )... );
    }

	// copy semantics
	BTree( const BTree& aOther ):
    fKey(aOther.fKey)
    {
        if ( aOther.fLeft )
        {
            fLeft = makeNode( *aOther.fLeft );
        }
        if ( aOther.fRight )
        {
            fRight = makeNode( *aOther.fRight );
        }
    }

	BTree& operator=( const BTree& aOther ){
        if ( this != &aOther )
        {
            BTree temp( aOther );
            swap( temp );
        }
        return *this;
    }

	// move semantics
	BTree( BTree&& aOther ) noexcept:
    fKey(std::move(aOther.fKey))
    {
        fLeft = std::move( aOther.fLeft );
        fRight = std::move( aOther.fRight );
    }

	BTree& operator=( BTree&& aOther ) noexcept{
        if ( this != &aOther )
        {
            swap( aOther );
        }
        return *this;
    }

	void swap( BTree& aOther ) noexcept{
        std::swap( fKey, aOther.fKey );
        std::swap( fLeft, aOther.fLeft );
        std::swap( fRight, aOther.fRight );
    }

	const T& operator*() const noexcept{
        return fKey;
    }
	bool hasLeft() const noexcept{
        assert( fLeft );
        return fLeft;
    }
	BTree& left() const{
        return *fLeft;
    }
	bool hasRight() const noexcept{
        assert( fRight );
        return fRight;
    }
	BTree& right() const{
        return *fRight;
    }
	void attachLeft( Node& aNode ){
        assert(!fLeft);
        fLeft = std::move(aNode);
    }
	void attachRight( Node& aNode ){
        assert(!fRight);
        fRight = std::move(aNode);
    }
	Node detachLeft(){
        assert( fLeft );
        return std::move( fLeft );
    }
	Node detachRight(){
        assert( fRight );
        return std::move( fRight );
    }
    
	bool leaf() const noexcept{
        return !fLeft && !fRight;
    }
	size_t height() const noexcept{
        if(!leaf()){
            size_t leftHeight = 0;
            size_t rightHeight = 0;
            if(fLeft){
                leftHeight = fLeft->height();
            }
            if(fRight){
                rightHeight = fRight->height();
            }
            return 1 + std::max(leftHeight, rightHeight);
        }
        return 0;
    }

	const T& findMax() const noexcept{
        if(!leaf()){
            if(fRight){
                return fRight->findMax();
            }
        }
        return fKey;
    }
	const T& findMin() const noexcept{
        if(!leaf()){
            if(fLeft){
                return fLeft->findMin();
            }
        }
        return fKey;
    }

private:
	T fKey;
	Node fLeft;
	Node fRight;
};
