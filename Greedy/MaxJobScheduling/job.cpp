#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<tuple<int, int, int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        // Sort by end time
        sort(jobs.begin(), jobs.end());

        vector<int> ends(n);
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            ends[i] = get<0>(jobs[i]);
        }

        for (int i = 1; i <= n; i++) {
            int end = get<0>(jobs[i - 1]);
            int start = get<1>(jobs[i - 1]);
            int currProfit = get<2>(jobs[i - 1]);

            // Find first job whose end time >= start
            // We need previous job with end <= start.
            int left = 0;
            int right = i - 1;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (ends[mid] <= start)
                    left = mid + 1;
                else
                    right = mid;
            }

            int prev = 0;

            if (ends[left] <= start)
                prev = left + 1;
            else
                prev = left;

            int take = currProfit + dp[prev];
            int skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[n];
    }
};