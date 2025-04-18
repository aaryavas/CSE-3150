#ifndef ECVECTOR_H
#define ECVECTOR_H

#include <vector>
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

template <typename T>
class ECVector {
private:
    vector<T> coordinates; //coords is a vector of x, y, z, (etc) coordinates
	int dimension;

public:
    //default constructor that accepts coordinates and updates dimension
    ECVector(vector<T> _coordinates);

    //destructor
    virtual ~ECVector();
	
	//copy constructor
    ECVector(const ECVector& other);
	//move constructor
    ECVector(ECVector&& other);
	//copy assignment operator
    ECVector operator=(const ECVector& other);
	//move assignment operator
    ECVector operator=(ECVector&& other);
	
    //access individual elements (need both to read and modify from index)
	//read from index
    T operator[](const int& index) const; //declared like const T& operator i think?
	//modify index
    T operator[](const int& index);

    //utility functions
    const int &getDimension() const {return dimension;}
	//returns magnitude of vector - square root of the sum of squares
	T getMagnitude() const;
	//return normalized vector (vector with same direction, but magnitude = 1)
	ECVector normalized();

    //vector-vector operations: +, -, * (dot product)
	ECVector operator+(const ECVector &other) const;
	ECVector operator-(const ECVector &other) const;
	T operator*(const ECVector &other) const; //dot product- takes two vectors multiplies and gives us a single value
	
    //scalar operations: *, /
	ECVector operator*(const T &scalar) const; //scalar just increasing by multiplying the vector by the scalar value
	ECVector operator/(const T &scalar) const; //same function as mutliplication just 1/x * v instead of x * v

    //print vector
    void display() const{
		cout<<"{"<<coordinates[0];
		for(int i=1;i<dimension;i++){
			cout<<",";
			cout<<coordinates[i];
		}
		cout<<"}"<<endl;
	}
};

#endif //ECVECTOR_H - complete should work
