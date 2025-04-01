// Usage: ./CountWords  <filename>
// Read a file as given as the first parameter, count the number of spaces in the file and output it
// If no file or bad file is provided, just quit

#include <iostream>
#include <fstream>
using namespace std;

int CountWords(char const *fileInput){
    // Your code goes here	

    // open file
    ifstream f(fileInput);
    int space = 0;

    //for edge case so not return 1 if no space
    bool foundChar = false;
    
    if (f.is_open())
    // your code here
    {
        //contributing to robust word identification
        foundChar = false;

        cout << "File is opening ..." << endl;
        //wont skip whitespaces aka space
        f >> noskipws;
        //if there are two words their will only be one space, add edge case
        space = 1;
        //loop through file, stop at space and store space count
        char ch;

        
        
        while (f >> ch)
        {
            foundChar = true;

            //not really robust let see if this works tho 
            if (ch == ' ')
            {
                cout << "Space Found!" << endl;
                space = space + 1;
                cout << "New Space Index: " << space << endl;
            }
        } 
    

    }

    else
    {
        cout << "Bad File." << endl;
        if (!f.is_open())
        {
            cerr << "File Fails To Be Open" << endl;
        }
    }

    // note: when you read from file, if you reach the end of the file, f.eof() will be true
    
    //edge case if no words
    if(!foundChar)
    {
        return 0;
    }
    else
    {
        return space;
    }
    

}