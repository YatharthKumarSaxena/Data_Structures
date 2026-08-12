#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int doDP(vector<int> &price,vector<int> &dp,int i){
        if(i==0)return 0;
        else if(dp[i]!=-1)return dp[i];
        dp[i] = 0;
        for(int k=1;k<=i;k++){
            dp[i] = max(dp[i],price[k - 1] + doDP(price, dp, i - k));
        }
        return dp[i];
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int>dp(n+1,-1);
        return doDP(price,dp,n);
    }
};