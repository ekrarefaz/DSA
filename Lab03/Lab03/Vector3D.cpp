//
//  Vector3D.cpp
//  Lab03
//
//  Created by Ekrar Efaz on 16/3/23.
//

#include "Vector3D.h"

#include <cassert>

Vector3D::Vector3D( float aX, float aY, float aW) noexcept :
    fBaseVector(aX,aY),
    fW(aW)
{}

Vector3D::Vector3D( const Vector2D aVector ) noexcept:
    fBaseVector(aVector),
    fW(1.0f)
{}

/*
 The operator[] function in the Vector3D class allows you to access the x, y, and z components of the vector using array syntax. For example, if you have a Vector3D object named v, you can access the x component using v[0], the y component using v[1], and the z component using v[2].

 The implementation of the operator[] function is based on the fact that the Vector3D class has three float member variables (fX, fY, and fZ) that are laid out consecutively in memory. This means that if we can treat the this pointer (which points to the current Vector3D object) as a pointer to a float array, we can access the individual components of the vector using array syntax.

 To achieve this, the reinterpret_cast operator is used to cast the this pointer to a const float* pointer. The reinterpret_cast operator allows us to reinterpret the bits of one type as another type. In this case, we're interpreting the bits of the this pointer (which points to a Vector3D object) as a pointer to a const float array.

 Next, we add the aIndex parameter to this pointer to get a pointer to the appropriate float element in the array. This is done using pointer arithmetic. Since we're treating the this pointer as a const float*, we need to add aIndex to this pointer using pointer arithmetic to get a pointer to the aIndex-th element of the float array. The assert statement is used to ensure that aIndex is less than 3 to avoid accessing memory outside the bounds of the array.
 */
float Vector3D::operator[]( size_t aIndex ) const // aIndex is used to iterate over memory
{
    assert( aIndex < 3 ); // to ensure memory overflow is obstructed
    return *(reinterpret_cast<const float*>(this) + aIndex); // bitwise cast reinterpretation
}

Vector3D::operator Vector2D() const noexcept{
    return Vector2D(fBaseVector.x()/fW,fBaseVector.y()/fW);
}
Vector3D Vector3D::operator*( const float aScalar ) const noexcept{
    return Vector3D( x() * aScalar, y() * aScalar, w() * aScalar);
}
Vector3D Vector3D::operator+( const Vector3D& aOther ) const noexcept{
    return Vector3D( x() + aOther.x(), y() + aOther.y(), w() + aOther.w());
}
float Vector3D::dot( const Vector3D& aOther ) const noexcept{
    return x() * aOther.x() + y() * aOther.y() + w() * aOther.w();
}

/*
 The output operator has to send the Vector3D object to the output stream. To do
 so, we cast the object aVector, passed as parameter, to Vector2D using a
 static_cast and send to result to the output stream. They type cast invokes the
 type conversion operator Vector2D() defined in Vector3D.
*/
std::ostream& operator<<( std::ostream& aOStream, const Vector3D& aVector ){
    aOStream << static_cast<Vector2D>(aVector);
    return aOStream;
}
    
    
