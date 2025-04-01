#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Return the number of groups, and the starting positions of a new group (Saved in positions)
int ECNumGroups( const string &str, vector<int> &positions ) {
    if (str.size() == 0){
        return 0;
    }
     positions.push_back(0);
    int numgroups = 1;
    for (int i = 1; i < str.size(); i++){
        if (str[i] != str[i-1]){
            numgroups++;
            positions.push_back(i);
        }
    }

    return numgroups;
}