#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int doDP(int n,vector<int>& dp){
        if(__builtin_popcount(n)==1)return 0;
        else if(dp[n]!=-1)return dp[n];
        else if(n%2==0){
            return dp[n] = doDP(n/2,dp);
        }
        return dp[n] = 1+min(doDP(n-1,dp),doDP(n+1,dp));
    }
    int minOperations(int n) {
        vector<int>dp(n+2,-1);
        return doDP(n,dp)+1;
    }
};