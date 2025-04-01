#include <vector>
#include <iostream>
using namespace std;

// return the sum of the numbers
int ECSumList(const vector<int> &listNums)
{
  // your code goes here ...

  //ok so first we need to use the indexing loops
  //indexing

  // this is the indexing method


  /*
  int sum =0;
  for(int i = 0; i < listNums.size(); i++){
    // sum += i; this was the wrong line
    sum += listNums[i]; //had to change this because it was not adding the actual values but the index instead 
    
  }
  return sum;
  */


  


  //the range loop method
  int sum = 0;

  //as you can see here a range loop is handled differently
  //the value index we are at returns the value that we are in the array
  //why is that?
  
  for(int j: listNums){
    cout << "sum start of loop is" << sum << endl;
    cout << "value of listnums we at " << j << endl;
    sum += j;
    cout << "sum so far is " << sum << endl;
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
  cout << "sum: " << sum << endl;
}
