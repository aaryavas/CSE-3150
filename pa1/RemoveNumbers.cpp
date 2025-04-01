#include <string>

//just for testing remove when done
#include <iostream>

using namespace std;

string RemoveNumbers(string strIn) {
    
    //we have to look at the string given 
    
    //loop through the string split into chars 
    string myString; 
    for(char i: strIn)
    {
        //if value is int delete
        
        if(!isdigit(i))
        {
            //then add to new string
            myString += i;
        }
        else
        {
            cout << "Erasing Digits ... " << i << endl;
        }
        

    }

    return myString; 






    
}
