#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1 << 21];

    int solve(int mask, int n, vector<vector<int>>& a) {
        if(mask == (1 << n) - 1)return 1;
        if(dp[mask] != -1) return dp[mask];
        int man = __builtin_popcount(mask);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(a[man][i] && !(mask & 1<<i)){
                int newMask = mask | (1 << i);
                ans += solve(newMask,n,a);
            }
        }
        return dp[mask] = ans;
    }

    int countWays(vector<vector<int>>& a) {
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, a);
    }
};