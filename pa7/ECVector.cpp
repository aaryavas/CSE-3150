#include "ECVector.h"


//implement the ECVector class based off the header file
//providing a definition for each member function


//initializer base class
//will only initialize the base class and non static data members
template <typename T>
//need to intialize the type <T> in the base since templated class
ECVector<T>::ECVector(vector<T> _coordinates)
    :coordinates(_coordinates),dimension(coordinates.size())
    {}

