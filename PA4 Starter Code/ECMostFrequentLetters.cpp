// Given a string, find the 3 most frequent letters; if there is a tie, choose alphabetically smallest
// for example, for "I have bad dreams that have bad feelings", return "[(a, 6)(e, 5)(d, 3)]"
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
 
void ECMostFrequentLetters( const string &Str, vector<pair<char, int>> &letters ) {
    //freqency map
    map<char, int> freq;
    for (size_t i = 0; i < Str.size(); i++) {
        if (isalpha(Str[i])) {
            char ch = tolower(Str[i]);
            freq[ch]++;
        }
    }
    //map2vec
    for (const auto &z : freq) {
        letters.push_back(z);
    }

    //sort
    for (size_t i = 0; i < letters.size(); i++) {
        for (size_t j = i + 1; j < letters.size(); j++) {
            //swaperoini
            if (letters[j].second > letters[i].second ||(letters[j].second == letters[i].second && letters[j].first < letters[i].first)) {
                pair<char, int> temp = letters[i];
                letters[i] = letters[j];
                letters[j] = temp;
            }
        }
    }
    //some base case stuff
    if (letters.size() > 3) {
        letters.resize(3);
    }

    //looks good lets test
}