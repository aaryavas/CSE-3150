#include <iostream>
using namespace std;

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size)
{
  // your code here
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < (size - 1 - i); j++){
      if(listNumbers[j] > listNumbers[j]+1){
          int temp = listNumbers[j];
          listNumbers[j] = listNumbers[j+1];
          listNumbers[j+1] = temp;
      }
    }
  }
  
}

int main()
{
  int arr[] = {1,3,2,4};
  ECSortFP(arr, 4);

  // print it out
  for(int i=0; i<4; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

