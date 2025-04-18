#ifndef ECVECTOR_H
#define ECVECTOR_H

#include <vector>
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

template ...?
class ECVector {
private:
    vector<...> coordinates; //coords is a vector of x, y, z, (etc) coordinates
	int dimension;

public:
    //default constructor that accepts coordinates and updates dimension
    ECVector(vector<...> _coordinates);

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
    ... operator[](const int& index) const;
	//modify index
    ... operator[](const int& index);

    //utility functions
    const int &getDimension() const {return dimension;}
	//returns magnitude of vector
	... getMagnitude() const;
	//return normalized vector (vector with same direction, but magnitude = 1)
	ECVector normalized();

    //vector-vector operations: +, -, * (dot product)
	.
	.
	.
	
    //scalar operations: *, /
	.
	.
	.

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

#endif //ECVECTOR_H
