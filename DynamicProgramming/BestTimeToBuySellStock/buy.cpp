#include <vector>
using namespace std;

class Solution {
public:
    int doDP(int i, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(i==n)return 0;
        else if(dp[i][buy]!=-1)return dp[i][buy];
        else if(buy){
            return dp[i][buy] = max(doDP(i+1,1,fee,prices,dp),-prices[i]+doDP(i+1,0,fee,prices,dp));
        }else{
            return dp[i][buy] = max(doDP(i+1,0,fee,prices,dp),prices[i]-fee+doDP(i+1,1,fee,prices,dp));
        }

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return doDP(0,1,fee,prices,dp);
    }
};