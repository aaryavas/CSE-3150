#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

// In this project, you will build a simple decryption tool using a 
// Caesar cipher—a substitution cipher where each character is shifted by 
// a fixed number of positions. Note that the shift should wrap around
// such that A left shifted by 1 should be Z and X right shifted by 5
// should be C. (Hint: use modulo)

// Cipher rules:
// Apply a Caesar cipher to uppercase letters (A-Z) with a left shift of 13
// Apply a Caesar cipher to lowercase letters (a-z) with a right shift of 8 
// Apply a Caesar cipher to numbers (0-9) with a right shift of 3
// Leave all other characters unchanged

// Implement ECCreateCipherMap() to generate a mapping of original characters to their encrypted versions.
// Implement ECDecryptMessage() to decode an encrypted message using the cipher map.


using namespace std;

map<char, char> ECCreateCipherMap() {
    // TO DO: create cipher map
    
    map <char, char> cipher_map;

    //we want to shift capital 13 
    const int upperShift = 13;
    for(char c = 'A'; c <= 'Z'; c++){
        char shifter = 'A' +((c-'A') + upperShift)%26;
        cipher_map[c] = shifter;
    }
    //lower case 8
    const int lowerShift = 8;
    for(char c = 'a'; c <= 'z'; c++){
        char shifter = 'a' +((c-'a') + lowerShift)%26;
        cipher_map[c] = shifter;
    }
    //number shift 3
    const int numShift = 3;
    for(char c = '0'; c <= '9'; c++){
        char shifter = '0' +((c-'0') + numShift)%10;
        cipher_map[c] = shifter;
    }

    return cipher_map;
}

template <typename Container>
string ECDecryptMessage(const map<char, char>& cipher, const Container& encrypted_text) {    
    // TO DO: apply cipher to encrypted text and return the decrypted text
    Container decrypt;
    for(char c: encrypted_text){
        auto finder = cipher.find(c);
        if(finder != cipher.end()){
            decrypt.push_back(finder->second);
        }else{
            decrypt.push_back(c);
        }
    }
    return string(decrypt.begin(),decrypt.end());
}


