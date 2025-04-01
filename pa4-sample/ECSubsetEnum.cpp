// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
// return the number of subsets (without duplicates) of the vector of chars
#include <vector>
#include <map>
using namespace std;

#include <algorithm>
// (1): counting the number of subsets
int ECSubsetEnumCount( const vector<char> &vecChars ) {
  // return the number of subsets (without duplicates) of the vector of chars
  // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b) 
  // Approach: first store in a map to count the number of occurance of each char
  // The number of subsets is equal to the product of (1+occur number of each char)
  map<char, int> charCount;

  for (char c : vecChars){
    charCount[c]++;
  }
  int subsets = 1;
  for (auto& entry : charCount) {
        subsets *= (entry.second + 1); //(n + 1) for each character
    }
  
  return subsets;
}

// (2): enumerating the subsets, and store the found subsets in setSubsets
// Note: the found subsets can be of any order (but cannot contain duplicates)
// Also note: you should try to make your code as efficient as you can (avoid excessive data copying)
void backtrack(const std::vector<char>& vecChars, int start, std::vector<char>& currentSubset, std::vector<std::vector<char>>& listSubsets) {
    // add current subset to the list
    listSubsets.push_back(currentSubset);
    
    //iterate through the vector
    for (int i = start; i < vecChars.size(); ++i) {
        // skips duplicates
        if (i > start && vecChars[i] == vecChars[i - 1]) {
            continue;
        }
        
        // include vecChars[i] in the current subset
        currentSubset.push_back(vecChars[i]);
        
        // recursive
        backtrack(vecChars, i + 1, currentSubset, listSubsets);
        
        currentSubset.pop_back();
    }
}

void ECSubsetEnum( const vector<char> &vecChars, vector<vector<char> > &listSubsets ) {
    vector<char> sortedVec = vecChars;
    std::sort(sortedVec.begin(), sortedVec.end());

    // Temporary vector to store the current subset
    std::vector<char> currentSubset;

    // Start backtracking from index 0
    backtrack(sortedVec, 0, currentSubset, listSubsets);
}
