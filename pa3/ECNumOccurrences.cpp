// You are tasked with creating a C++ program that will analyze two arrays of integers,
// referred to as "arrayA" and "arrayB," and determine how many times an integer in  
// "arrayA" occurs in "arrayB"

// The program should output "arrayC" that matches the length of "arrayA"
// the indicies of "arrayC" map to the same indicies of "arrayA" with the values
// representing the number of occurrences

// For example, if "arrayA" contains {1, 3} and "arrayB" contains 
// {2, 1, 6, 1, 10, 3, 7}, the program should output {2, 1}
// indicating that "1" from "arrayA" occurs twice and "3" occurs once

// Tip: don't reinvent the wheel; try to use C++ standard library functions

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to count the number of integers present in both arrays using binary search
std::vector<int> ECNumOccurrences(const std::vector<int>& arrayA, const std::vector<int>& arrayB) {
    std::vector<int> arrayC;
    // Your code goes here...


    //we will use binary search for our apporach here

    //binary search through array b using vectors from array a
    arrayC.resize(arrayA.size());
    cout << endl;
    for(size_t i = 0; i < arrayA.size(); i++){
        int counter = arrayA[i];
        //take lower bound and upper bound and take the value in between
        auto lower = lower_bound(arrayB.begin(), arrayB.end(), counter); 
        auto upper = upper_bound(arrayB.begin(), arrayB.end(), counter);
        //this will see if there is a value in between
        cout << counter << endl;

        //this doesnt work - fixed arrayc size needed to be initialized
        int occurrences = distance(lower, upper);
        arrayC[i] = occurrences;
                
    }

    

    return arrayC;
}


