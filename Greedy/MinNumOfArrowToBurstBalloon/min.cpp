#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool Compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),Compare);

        int currEnd = intervals[0][1];
        int n = intervals.size();
        int arrows = 1;

        for(int i = 1; i < n; i++) {
            int nextStart = intervals[i][0];

            if(nextStart > currEnd) {
                arrows++;
                currEnd = intervals[i][1];
            }
        }

        return arrows;
    }
};