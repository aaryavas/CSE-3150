// Usage: ./CountWords  <filename>
// Read a file as given as the first parameter, count the number of spaces in the file and output it
// If no file or bad file is provided, just quit
// Only submit Countwords.cpp
#include <iostream>
#include <fstream>
#include "CountWords.cpp"
using namespace std;


int CountWords(char const *);

int main(int argc, char const *argv[]){
    // Your code goes here
    //will need to take file input open file execute the other codes function, then close then prompt for next 
    

    //currently error opening this file must be due to the CountWords input handling 
    int spaceCount = CountWords(argv[1]);
    cout << "Number of words in file: " << spaceCount << endl;



    return 0;
}