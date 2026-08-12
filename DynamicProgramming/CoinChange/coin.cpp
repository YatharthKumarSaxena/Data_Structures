#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int doDP(vector<int>& coins, vector<int>& dp, int amount){
        if(amount == 0)return 0;
        else if(dp[amount]!=-1)return dp[amount];
        dp[amount] = INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int result = doDP(coins, dp, amount - coins[i]);

                if(result != INT_MAX) {
                    dp[amount] = min(dp[amount], 1 + result);
                }
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        vector<int>dp(amount+1,-1);
        dp[0] = 0;
        int ans = doDP(coins,dp,amount);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};