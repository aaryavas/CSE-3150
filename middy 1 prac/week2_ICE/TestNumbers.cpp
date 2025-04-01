#include <iostream>
#include "ECCalculator.hpp"
#include "ECNumbers.hpp"

using namespace ECNumbers;

int main()
{
  int x;
  std::cin >> x;
  std::cout << ECDoubleN(x)  << std::endl; 
  // your code here

  // print out the square of it
  // your code here
  std::cout << ECSquareN(x) << std::endl;

  // print out 2n  
  // your code here
  std::cout << ECFourTimesN(x)<< std::endl;
  // print out 4 times of n by invoking ECCalculator's function
  // your code here

  return 0;
}
