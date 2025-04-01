#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

bool ECFind(const vector<int> &listVecs, int x)
{
  // your code here
  // ok we have to implement some sort of find function
  //lets look at the week 5 review notes
  //not there look week 4
  //cant seem to find much in either looks like we need to think about this
  
  //implement a searchign algo
  //binary search
  //assume that it is sorted

  int high = listVecs[listVecs.size() - 1];
  int low = listVecs[0];
  
  while(low <= high){
    int mid = low + (high-low)/2;
    if(listVecs[mid] == x){
      return 1;
    }
    if(mid < low){
      low = mid + 1;
    }
    else{
      high = mid -1;
    }
    
  
  }
  return -1;


  //looks like we got control reaches end of non-void function
  //what is a void and what is a non-void function
  //void function means it does not return anything
  //this means we are not returning anything at the end of the function 
  //this needs to happen since the function is not void
}

// Test your code with this main function

int main()
{
  // create a list of certain size
  const int NUM_INTS = 10000;
  vector<int> vec;
  for(int i=0; i<NUM_INTS; ++i)
  {
    vec.push_back(i);
  }
  const int NUM_FIND = 100000;

  auto start = clock();
  for(int i=0; i<NUM_FIND; ++i)
  {
    ECFind(vec,i);
  } 
  auto end = clock();
  double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  cout << "Time taken: " << duration << " seconds" << endl;
}

