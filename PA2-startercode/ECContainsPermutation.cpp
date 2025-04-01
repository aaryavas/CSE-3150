//Checks whether string s2 contains any permutation of string s1 
//Otherwise return false

#include <string>
using namespace std;

bool ECContainsPermutation(const std::string& s1, const std::string& s2)
{
    int len1 = s1.size();
    int len2 = s2.size();

    if (len1 > len2)
        return false;

    //this part of code may be unnecessary but leave it in for now 
    const int ASCII_COUNT = 128; 
    int freq1[ASCII_COUNT] = {0};
    int windowFreq[ASCII_COUNT] = {0};

    //freq counts for s1 and s2
    for (int i = 0; i < len1; i++) {
        freq1[(int)s1[i]]++;
        windowFreq[(int)s2[i]]++;
    }

    //check first win for permutation
    bool isMatch = true;
    for (int i = 0; i < ASCII_COUNT; i++) {
        if (freq1[i] != windowFreq[i]) {
            isMatch = false;
            break;
        }
    }
    if (isMatch){
        return true;
    }
        

    //slide the window across s2.
    for (int i = len1; i < len2; i++) {
        // Add the new character.
        windowFreq[(int)s2[i]]++;
        //remove the character that's no more in window
        windowFreq[(int)s2[i - len1]]--;
        isMatch = true;
        for (int j = 0; j < ASCII_COUNT; j++) {
            if (freq1[j] != windowFreq[j]) {
                isMatch = false;
                break;
            }
        }
        if (isMatch){
            return true;
        }    
    }

    return false;
}