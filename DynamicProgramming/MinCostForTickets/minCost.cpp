#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int doDP(int day, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        int n = days.size();

        if(day > days[n - 1])
            return 0;

        if(dp[day] != -1)
            return dp[day];

        bool checkDayExist = false;

        for(int i = 0; i < n; i++) {
            if(days[i] == day) {
                checkDayExist = true;
                break;
            }
        }

        if(!checkDayExist)
            return dp[day] = doDP(day + 1, days, costs, dp);

        return dp[day] = min(
            costs[0] + doDP(day + 1, days, costs, dp),
            min(
                costs[1] + doDP(day + 7, days, costs, dp),
                costs[2] + doDP(day + 30, days, costs, dp)
            )
        );
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> dp(days[n - 1] + 1, -1);

        return doDP(days[0], days, costs, dp);
    }
};