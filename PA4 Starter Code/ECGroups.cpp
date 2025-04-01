#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Return the number of groups, and the starting positions of a new group (Saved in positions)
int ECNumGroups( const string &str, vector<int> &positions ) {
    if(str.empty()){
        return 0;
    }
    positions.push_back(0);
    int groups = 1;
    for(int t =1; t < str.size(); t++){
        if(str[t]!=str[t-1]){
            positions.push_back(t);
            ++groups;
        }
    }
    return groups;
}   