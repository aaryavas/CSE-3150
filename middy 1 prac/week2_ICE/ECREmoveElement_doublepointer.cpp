#include <iostream>
using namespace std;

void ECRemoveSpace(int nums[], int len, int val)
{
    int count = 0;
    for(int i = 0; i != len; i++){
        if(nums[i] != val){
            nums[count] = nums[i];
            count++;
        }
    }
}


