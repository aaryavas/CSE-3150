#include "ECVector.h"


//implement the ECVector class based off the header file
//providing a definition for each member function


//initializer base class
//will only initialize the base class and non static data members
template <typename T>
//need to intialize the type <T> in the base since templated class
ECVector<T>::ECVector(vector<T> _coordinates){
    dimension = 0;
    for(auto k: _coordinates){
        coordinates.push_back(k);
        dimension++;
    }
}

//destructor
template <typename T>
ECVector<T>::~ECVector(){}

//copy constructor - may be issue at runtime here revist when complete
template <typename T>
ECVector<T>::ECVector(const ECVector& other){
        //include code here maybe
        coordinates = other.coordinates;
        dimension = other.dimension;
}


//move constructor
using namespace std;
template <typename T>
ECVector<T>::ECVector(ECVector&& other){
    coordinates = move(other.coordinates);
    dimension = other.dimension;
    other.dimension = 0;
}

//copy assignment operator
template <typename T>
ECVector<T> ECVector<T>::operator=(const ECVector& other){
    //some code here
    //this is for the copy assignment
    if(this != &other){
        coordinates = other.coordinates;
        dimension = other.dimension;
    }
    return *this;
}

//move assignment operator
using namespace std;
template <typename T>
ECVector<T> ECVector<T>::operator=(ECVector&& other){
    //some code here
    //this is for the move assignment
    if(this != &other){
        coordinates = move(other.coordinates);
        dimension = other.dimension;
        other.dimension = 0;
    }
    return *this;
}

//read from index operator
template <typename T>
T ECVector<T>::operator[](const int& index) const {
    //code here
    return coordinates.at(index);
}

//modify index operator
template <typename T>
T& ECVector<T>::operator[](const int& index) {
    //code here
    return coordinates.at(index);
}

//getDimension function - returns the dimension of the vector - already made in header

//getMagnitude function - returns the magnitude of the vector
template <typename T>
T ECVector<T>::getMagnitude() const {
    //code here
    T sum = 0;
    for(const auto& k: coordinates){
        sum += (k*k);
    }
    return sqrt(sum);
}

//normalized function - returns the normalized vector
template <typename T>
ECVector<T> ECVector<T>::normalized() {
    //code here
    T mag = getMagnitude();
    vector<T> normalized_coords;
    for(auto& k: coordinates){
        normalized_coords.push_back(k/mag);
    }
    ECVector<T> unit_vec(normalized_coords);
    return unit_vec;
}


template <typename T>
vector<T> resizeVector(const vector<T>& vec, int newSize) {
    vector<T> newvec = vec;
    newvec.resize(newSize, 0); 
    return newvec;
}
/*
now we will implement the vector-vector operations
*/

//vector addition operator
template <typename T>
ECVector<T> ECVector<T>::operator+(const ECVector &other){
    //code here
    int op_dim = max(dimension, other.dimension);

    vector<T> coordinates_copy = resizeVector(coordinates, op_dim);
    vector<T> other_copy = resizeVector(other.coordinates, op_dim);
    
    vector<T> result;
    for(int i=0; i<op_dim; i++){
        result.push_back(coordinates_copy[i] + other_copy[i]);
    }
    return ECVector<T>(result);
    
}

//vector subtraction operator
template <typename T>
ECVector<T> ECVector<T>::operator-(const ECVector &other){
    //code here
    int op_dim = max(dimension, other.dimension);

    vector<T> coordinates_copy = resizeVector(coordinates, op_dim);
    vector<T> other_copy = resizeVector(other.coordinates, op_dim);
    
    vector<T> result;
    for(int i=0; i<op_dim; i++){
        result.push_back(coordinates_copy[i] - other_copy[i]);
    }
    return ECVector<T>(result);
}

//dot product operator
template <typename T>
T ECVector<T>::operator*(const ECVector &other){
    //code here
    if(dimension != other.dimension){
        throw std::invalid_argument("vector dimensions must be equal for dot product");
    }

    T result = 0;
    for(int i=0; i<dimension; i++){
        result += coordinates[i] * other.coordinates[i];
    }

    return result;

}

/*
Now we will implement the scalar operations
*/

//scalar multiplication operator
template <typename T>
ECVector<T> ECVector<T>::operator*(const T &scalar){
    //code here
    vector<T> result;
    for(int i=0; i<dimension; i++){
        result.push_back(coordinates[i] * scalar);
    }
    return ECVector<T>(result);
}

//scalar division operator
template <typename T>
ECVector<T> ECVector<T>::operator/(const T &scalar){
    //code here
    vector<T> result;
    for(int i=0; i<dimension; i++){
        result.push_back(coordinates[i] / scalar);
    }
    return ECVector<T>(result);
}


//throw these in not sure if needed
template class ECVector<int>;
template class ECVector<float>;
template class ECVector<double>;

