#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool Compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

    int activitySelection(vector<int>& start, vector<int>& finish) {
        int n = start.size();

        vector<pair<int, int>> activities;

        for (int i = 0; i < n; i++) {
            activities.push_back({start[i], finish[i]});
        }

        sort(activities.begin(), activities.end(), Compare);

        int currEnd = activities[0].second;
        int removals = 0;

        for (int i = 1; i < n; i++) {
            int nextStart = activities[i].first;
            int nextEnd = activities[i].second;

            if (nextStart <= currEnd) {
                removals++;
                currEnd = min(currEnd, nextEnd);
            } else {
                currEnd = nextEnd;
            }
        }

        return n - removals;
    }
};