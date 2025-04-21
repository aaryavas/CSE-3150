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

//destructor
template <typename T>
ECVector<T>::~ECVector(){
    //leave empty do defaults
    //might need to add code later on
}

//copy constructor - may be issue at runtime here revist when complete
template <typename T>
ECVector<T>::ECVector(const ECVector& other)
    :coordinates(other.coordinates), dimension(other.dimension){
        //include code here maybe
    }


//move constructor
using namespace std;
template <typename T>
ECVector<T>::ECVector(ECVector &&other)
    :coordinates(move(other.coordinates)), dimension(move(other.dimension)){
        //include code here maybe
    }

//copy assignment operator
template <typename T>
ECVector<T> ECVector<T>::operator=(const ECVector& other){
    //some code here
    //this is for the copy assignment
}

//move assignment operator
template <typename T>
ECVector<T> ECVector<T>::operator=(ECVector&& other){
    //some code here
    //this is for the move assignment
}

//read from index operator
template <typename T>
T ECVector<T>::operator[](const int& index) const {
    //code here
}

//modify index operator
template <typename T>
T ECVector<T>::operator[](const int& index) {
    //code here
}

//getDimension function - returns the dimension of the vector - already made in header

//getMagnitude function - returns the magnitude of the vector
template <typename T>
T ECVector<T>::getMagnitude() const {
    //code here
}

//normalized function - returns the normalized vector
template <typename T>
ECVector<T> ECVector<T>::normalized() {
    //code here
}

/*
now we will implement the vector-vector operations
*/

//vector addition operator
template <typename T>
ECVector<T> ECVector<T>::operator+(const ECVector &other) const {
    //code here
}

//vector subtraction operator
template <typename T>
ECVector<T> ECVector<T>::operator-(const ECVector &other) const {
    //code here
}

//dot product operator
template <typename T>
T ECVector<T>::operator*(const ECVector &other) const {
    //code here
}

/*
Now we will implement the scalar operations
*/

//scalar multiplication operator
template <typename T>
ECVector<T> ECVector<T>::operator*(const T &scalar) const {
    //code here
}

//scalar division operator
template <typename T>
ECVector<T> ECVector<T>::operator/(const T &scalar) const {
    //code here
}

