#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int currEnd = intervals[0][1];
        int n = intervals.size();
        int removals = 0;

        for(int i = 1; i < n; i++) {
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if(nextStart < currEnd) {
                removals++;
                currEnd = min(currEnd, nextEnd);
            }
            else {
                currEnd = nextEnd;
            }
        }

        return removals;
    }
};