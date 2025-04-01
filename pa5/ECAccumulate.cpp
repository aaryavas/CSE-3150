#include <iostream>
#include <vector>
#include <cmath>



// we want to create a function ECAccumulate that can perform any arbitrary element-wise operation
// on 2 containers of any kind. Then we want to accumulate the element-wise reuslts into a scalar
// using any arbitrary accumulation function. The functions could be addition, subtraction, 
// multiplication, division, or even something more complex like the squared difference.

// More specifically, the ElementwiseFunc should be applied to every element in both containers
// such that for each i, the ElementwiseFunc is performed on a_i and b_i. The result of this operation
// gets accumulated into a running total according to the AccFunc.  An initial value init is provided
// to start the accumulation.

// Your task is to implement ECAccumulate and then use this function to compute the 
// Euclidean distance and Dot product between two points/vectors. Implementation fo these
// two functions should be very simply once you have ECAccumulate set up properly.


// functions to use in your implementation
double sum(const double &a, const double &b) {
    return a + b;
}

double diff(const double &a, const double &b) {
    return a - b;
}
  
  
double multiply(const double &a, const double &b) {
    return a * b;
}
  
double divide(const double &a, const double &b) {
    return a / b;
}

double squared_diff(const double &a, const double &b) {
    double diff = a - b;
    return diff * diff; 
}


template <typename Container, typename ElementwiseFunc, typename AccFunc>
double ECAccumulate(const Container &c1, const Container &c2, ElementwiseFunc elem_f, AccFunc acc_f, double init){
    // TO DO: create a generic accumulator that works on any container, with any  
    // binary transform fucntion and any accumulator
    for(size_t i = 0; i < c1.size() && i < c2.size(); i++){
        init = acc_f(init, elem_f(c1[i],c2[i]));
    }
    return init;
}

using namespace std;
template <typename Container>
double ECEuclideanDistance(const Container &point1, const Container &point2) {
    // TO DO: use ECAccumulate to calculate the Euclidean distance
    // hint: find the sum of the squared differences and then finally take the square root

    //subtract each with corresponding other index
    //square that calculation
    //sum the squares
    //square root the sum
    if (point1.size() != point2.size()) {
        return -1;
    } 
    double sumSquares = ECAccumulate(point1, point2, squared_diff,sum, 0.0);
    double tot_dist = sqrt(sumSquares);
       
    return tot_dist;

    
}


template <typename Container>
double ECDotProduct(const Container &vec1, const Container &vec2) {
    // TO DO: use ECAccumulate to calculate the dot product
    // hint: find the sum of the elementwise multiplication of vec 1 and vec 2

    //mutiply each value by its corresponding value in the array 
    //then add all multiplied values together

    
    if((vec1.empty() || vec2.empty()) || (vec1.size() != vec2.size())){
        return -1;
    }
    return ECAccumulate(vec1, vec2, multiply, sum, 0.0);

}

