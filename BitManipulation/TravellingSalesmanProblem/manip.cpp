#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[15][1<<15];
    int doBitManip(int city, int mask, int n, vector<vector<int>>& cost){
        if(mask==(1<<n)-1)return cost[city][0];
        else if(dp[city][mask]!=-1)return dp[city][mask];
        int ans = INT_MAX;
        for(int next=0;next<n;next++){
            if (!(mask & (1 << next))) {
                ans = min(ans,cost[city][next]+doBitManip(next,mask|(1<<next),n,cost));
            }
        }
        return dp[city][mask] = ans;
    }
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        int res = doBitManip(0,1,n,cost);
        return res;
    }
};