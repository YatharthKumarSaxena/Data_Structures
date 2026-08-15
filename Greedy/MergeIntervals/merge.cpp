#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];

        int n = intervals.size();

        vector<vector<int>> ans;

        for(int i = 1; i < n; i++) {
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if(nextStart <= currEnd) {
                currEnd = max(currEnd, nextEnd);
            }
            else {
                ans.push_back({currStart, currEnd});

                currStart = nextStart;
                currEnd = nextEnd;
            }
        }

        ans.push_back({currStart, currEnd});

        return ans;
    }
};