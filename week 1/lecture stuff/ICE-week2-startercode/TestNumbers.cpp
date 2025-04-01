#include <iostream>
#include "ECCalculator.h"
#include "ECNumbers.h"

using namespace ECNumbers;



int main()
{
  // read in an integer n
  int x;
  std::cin >> x;
  std::cout << EC_twotimes(x) << std::endl;


  // your code here

  // print out the square of it
  // your code here
  std::cout << EC_Square(x) <<  std::endl;

  // print out 2n  
  // your code here

  // print out 4 times of n by invoking ECCalculator's function
  // your code here

  return 0;
}
