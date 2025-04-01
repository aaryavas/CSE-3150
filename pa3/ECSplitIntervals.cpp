#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void splitIntervals(vector<pair<int,int>> &intervals, const vector<int> &vals_to_remove){

    vector<pair<int,int>> f_intervalsRange;

    if(!intervals.empty()){
        for(auto& interval: intervals){
            vector<pair<int,int>> intervalsRange;
            vector<int> numRange;
            int first = interval.first;
            int last = interval.second;

            for( int i = first; i <= last; i++){
                numRange.push_back(i);
            }
            vector<bool> to_remove(numRange.size(), false);
            for (int val : vals_to_remove) {
                for (size_t i = 0; i < numRange.size(); ++i) {
                    if (numRange[i] == val) {
                        to_remove[i] = true;
                    }
                }
            }

            int start_index = -1;

            for (size_t i = 0; i < numRange.size(); ++i) {
                if (!to_remove[i]) {
                    if (start_index == -1) {
                        start_index = i;
                    }
                    if (i + 1 == numRange.size() || to_remove[i + 1]) {
                        intervalsRange.push_back({numRange[start_index], numRange[i]});
                        start_index = -1;
                    }
                } else {
                    start_index = -1;
                }
            }

            f_intervalsRange.insert(f_intervalsRange.end(), intervalsRange.begin(), intervalsRange.end());
        }
    }

    intervals = f_intervalsRange;
}