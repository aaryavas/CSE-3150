#include <vector>
#include <set>
#include <iostream>
using namespace std;

// I want to have a generic function that can work with any types of numbers 
// AND any type of container. Is this possible?

//template function
/*
how it will look like 

template <typename T>

it will allow us to give a function any type for example:


template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

here we are giving the swap function to take any type T as input

*/


//container in c++
/*

A container is basically just any data structure in c++ that holds some elements:

ex.:

Sequence
stf::vector
std::list
sd:deque

associative
std::set
std:map

*/

//tempelate cannot be inside of the function
template <typename T1, typename container>  


T1 ECSumList(const container &listNums) //instead of defining a vector we could have any container type hense container here
{
  // your code goes here ...

  //we need to make this code typeless 

  T1 sum = T1(); //this is how initialization works in templeate types
  T1 sum = 0; //this is bad because it means it must be int 
  for(auto i: listNums){
    sum += i; 
  }
  return sum; 
}

// Test your code with this main function

int main()
{
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(3);
  vec.push_back(0);
  vec.push_back(1);
  int sum = ECSumList(vec);
  cout << "sum1: " << sum << endl;

  set<double> ss;
  ss.insert(5.0);
  ss.insert(3.0);
  ss.insert(3.0);
  ss.insert(0.0);
  ss.insert(1.0);
  double sum2 = ECSumList(ss);
  cout << "sum2: " << sum2 << endl;
}
