//this will give us the io library for displaying output in the terminal
#include <iostream>



int main()
{
    // the double << is telling us to take the string and to send it to cout 
    // the second << is telling us that after we print this send this "endl" to the standard output
    // std means standard output which is a namespace/package


    //in c++ we can add any class to any namespace
    //     ex. main is in a namespace but not implied so it would be part of the global namespace

    std::cout << "Hello World!" << std::endl;
    
    //if no error return zero  that means we are all good 
    //if we did void main we wouldn't be 100% certain
    return 0;

}


//to compile:
//-o will tell us where the output will go
//std will tell us what version of the standard we go to
//c++ will be whatever type of compiler being used

// c++ hello1.cpp -o hello1 -std=c++14
// -c will only compile

// to execute: ./hello1
// -g "add Debug info"


//instead of doing it all the time 
/** 
using namespace std;

namespace CSE3150
{
    using namespace CSE3150;
    int foo(int n )
    {
        return n+1;
    }
    int main()
    {
        // when we remove the std namespace/package what happens?
        //error, an indentifier is undeclared aka our missing "std" value
        cout << "Hello World!" << foo(10) endl;
        return 0;
    }

}
*/


