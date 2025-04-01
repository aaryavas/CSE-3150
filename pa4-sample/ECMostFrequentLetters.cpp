// Given a string, find the 3 most frequent letters; if there is a tie, choose alphabetically smallest
// for example, for "I have bad dreams that have bad feelings", return "[(a, 6)(e, 5)(d, 3)]"
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#include <algorithm>
void ECMostFrequentLetters( const string &Str, vector<pair<char, int>> &letters ) {
    map<char, int> frequencyMap;
    for (int i = 0; i < Str.size(); i++){
        if (isalpha(Str[i])){
            char ch = tolower(Str[i]);
            frequencyMap[ch]++;
        }
    }
    for (const auto &entry : frequencyMap) {
        letters.push_back(entry);  // Push the (letter, frequency) pair into the vector
    }
    sort(letters.begin(), letters.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;  // Alphabetical order
        }
        return a.second > b.second;  // Sort by frequency in descending order
    });
    if (letters.size() > 3) {
        letters.resize(3); 
    }
}
/*int main() {
    std::string input = "I have bad dreams that have bad feelings";
    std::vector<std::pair<char, int>> letterCounts;

    ECMostFrequentLetters(input, letterCounts);

    // Print the result
    for (const auto &entry : letterCounts) {
        std::cout << "Letter: " << entry.first << " Count: " << entry.second << std::endl;
    }

    return 0;
}*/