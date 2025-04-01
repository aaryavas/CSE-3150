// Find the longest common prefix string amongst the list of strings and return the string
// If there is no common prefix return an empty string ""

#include <vector>
#include <string>
using namespace std;

std::string ECLongestPrefix(const std::vector<std::string> &words) 
{
  // Implement the ECContainsPermutation function here...

  //psuedocode:
  //so if we sort the array in alphabetical order everything we could get away wiht only comparing hte first and the last words
  //this is because lets say the highest prefix is gree that means the first word would set the max prefix and if true that means the last word would match this too
  //but if the last word only matches up until gre it would not be the longest prefix

  //start with code here
  if(words.empty()){
    return "";
  }

  //create copy of vector 
  vector<string> sorted = words;

  //bubble sort for the strings
  size_t n = sorted.size();
  for (size_t i =0; i < n-1; i++){
    bool swapped = false;
    for(size_t j = 0; j < n- i -1; j++){
      if(sorted[j] > sorted[j+1]){
        string temp = sorted[j];
        sorted[j] = sorted[j+1];
        sorted[j+1] = temp; 
        swapped = true;
      }
    }
      //if already sorted
    if(!swapped){
    break;
    }
    }
    
    //now vector sorted

    //compare first and last strings char by char
    string first =  sorted.front();
    string last = sorted.back();\
    
    //for finding the string with the shortest length to only iterate that much 
    size_t shortest = 0;
    if (first.length() < last.length()){
      shortest = first.length();
    }
    else {
      shortest = last.length();
    }
    string result = "";
    for(size_t i =0; i <= shortest; i++){
      if (first[i] == last[i]){
        result.push_back(first[i]);
      }
      else {
        break;
      }
    }
    return result;
}

