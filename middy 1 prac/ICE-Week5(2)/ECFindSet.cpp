#include <vector>
#include <set>
#include <iostream>
#include <ctime>
using namespace std;

bool ECFind(const set<int> &listNums, int x)
{
  // your code

  // ok here we have a set means that shi is already sorted and no dups
  //would we just do binary search again?
  //I dont see why not lets try it
  //standard approach will not work as a set cannot taker operator [] stuff needs to be analyzed differently

  /*
  int high = listNums[listNums.size() -1];
  int low = listNums[0];

  while (low <= high){
    int mid = low + (high - low ) /2;
    if(listNums[mid] == x){
      return 1;
    }
    if()
  }
  */

  //seems like for a set we can handle it with .begin and .end()
  //according to the documentation this works

  //this raises error tho 
  //what is conversion function 
  

  //changed type to auto because for some reason int isn't working
  auto finder = listNums.find(x);
  return 1;



}

// Test your code with this main function

int main()
{
  // create a list of certain size
  const int NUM_INTS = 10000;
  set<int> ss;
  for(int i=0; i<NUM_INTS; ++i)
  {
    ss.insert(i);
  }
  const int NUM_FIND = 100000;
  auto start = clock();
  for(int i=0; i<NUM_FIND; ++i)
  {
    ECFind(ss,i);
  } 
  auto end = clock();
  double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  cout << "Time taken: " << duration << " seconds" << endl;
}

