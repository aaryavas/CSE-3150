#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

// we want to define two functions ECSetIntersection and ECIntersection that find the overlap between two generic containers
// ECSetIntersection does NOT include duplicates. You are free to use functions from the set library as necessary
// ECIntersection DOES include duplicates. For example the ECIntersection between "aaabc" and "aabb" will be "aab".


using namespace std;

template <typename container>
container ECSetIntersection(const container &c1, const container &c2) {
    // TO DO: find the set intersection of the two containers.
    // ie, no duplicates allowed in the result 


    //ok since here we could use a set hence the name
    //this is because a set would avoid the dups and will only store unique elements
    typedef typename container::value_type T;
    set<T> s;
    for (auto i : c1) {
        auto f = find(c2.begin(), c2.end(), i);
        if (f != c2.end()) {
            s.insert(i);
        }
    }
    container result;
    for (auto elem : s) {
        result.insert(result.end(), elem);
    }
    return result;
}



template <typename container>
container ECIntersection(const container &c1, const container &c2) {
    // TO DO: find the general intersection of the two containers
    // For this version duplicates are preserved such that if 'e' appears 2 time in EACH container
    // it will appear twice in the result, if it appears 3 times in EACH, then it will appear
    // thrice in the result
    // Use a brute-force algrothim in O(n^2)

    container intersect;
    container temp = c2;
    for(auto i: c1){
        auto f = find(temp.begin(), temp.end(), i);
        if( f != temp.end()){
            intersect.insert(intersect.end(), i);
            temp.erase(f);
        }
    }
    return intersect; 
}


