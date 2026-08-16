#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int doDP(int n,vector<int>& dp){
        if(n<=0)return 0;
        else if(n==1 || n==5 || n==10 || n==2)return 1;
        else if(dp[n]!=-1)return dp[n];
        int oneCost = doDP(n-1,dp);
        int twoCost = (n-2>=0)? doDP(n-2,dp): INT_MAX;
        int fiveCost = (n-5>=0)? doDP(n-5,dp): INT_MAX;
        int tenCost = (n-10>=0)? doDP(n-10,dp): INT_MAX;
        return dp[n] = 1+min(min(oneCost,twoCost),min(fiveCost,tenCost));
    }
    int findMin(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return doDP(n,dp);
    }
};