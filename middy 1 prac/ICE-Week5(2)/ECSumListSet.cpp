#include <set>
#include <vector>
#include <iostream>
using namespace std;

int ECSumList(const set<int> &listNums)
{
  // your code goes here ...

  //ok this time we want to use a set

  //what is a set and what does it look like 
  //set automatically sort and automatically stores elements
  int sum = 0; 
  for(int a: listNums){
    sum += a;
  }
  return sum;
  

}

// Test your code with this main function

int main()
{
  set<int> ss;
  ss.insert(5);
  ss.insert(3);
  ss.insert(3);
  ss.insert(0);
  ss.insert(1);
  int sum = ECSumList(ss);
  cout << "sum: " << sum << endl;
}
