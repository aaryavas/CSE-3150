// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
// return the number of subsets (without duplicates) of the vector of chars
#include <vector>
#include <map>
using namespace std;
#include <algorithm>
//remove this when done
#include <iostream>


// (1): counting the number of subsets
int ECSubsetEnumCount( const vector<char> &vecChars ) {
  // return the number of subsets (without duplicates) of the vector of chars
  // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b) 
  // Approach: first store in a map to count the number of occurance of each char
  // The number of subsets is equal to the product of (1+occur number of each char)
  map<char, int> map;
  for(char c: vecChars){
    if (map.find(c) == map.end()) {
      map[c] = 1;
    } else {
      map[c] = map[c] + 1; 
    }
  }
  int product =1;
  for(auto const &x: map){
    //for x.second +1 =* product
    product *= (x.second +1);
  }

  return product;
  //code works! 

}

// (2): enumerating the subsets, and store the found subsets in setSubsets
// Note: the found subsets can be of any order (but cannot contain duplicates)
// Also note: you should try to make your code as efficient as you can (avoid excessive data copying)
void recursBack(const vector<char>& vecChars, int begin, vector<char> &currSubSet, vector<vector<char>> & listSubsets){
  listSubsets.push_back(currSubSet);

  //iter
  for (int i = begin; i <vecChars.size(); i++){
    //skip dups
    if (i > begin && vecChars[i] == vecChars[i-1]){
      continue;
    }
    currSubSet.push_back(vecChars[i]);
    
    //backtrack
    recursBack(vecChars, i+1, currSubSet, listSubsets);
    currSubSet.pop_back();
  }
  //this should work
}


void ECSubsetEnum( const vector<char> &vecChars, vector<vector<char> > &listSubsets ) {

  //gotta change this can't ge the integrated recurs to work make a seperate func
  vector<char> currentSub;

  //issues since const
  vector<char> sorted = vecChars;
  //not passing test 5 maybe sort
  sort(sorted.begin(), sorted.end());
  
  //recurs call
  recursBack(sorted, 0, currentSub, listSubsets);
}
