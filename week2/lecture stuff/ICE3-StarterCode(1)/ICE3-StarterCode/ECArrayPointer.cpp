//
#include <iostream>
using namespace std;

int main()
{
  // allocate an array of char in heap 
  char *px = new char[10];
  // set this array to 'a', 'b' and so on
  // your code here...

  //take the ascii approach 
  //a = 97 
  //b = 98 
  //so we are basically adding one to it at each iteration

  char z = 'a';
  for (int i  = 0: i <10; ++i);
  cout  << "The value of the "
  //so basically we want to set each value to  
  // print out
  for(int i=0; i<10; ++i)
  {
    //setting pointer to the next ascii value
    *(px+i)  = z++;
    cout << *(px+i);
  }
  cout << endl;

  delete [] px;

  return 0;
} 
 
