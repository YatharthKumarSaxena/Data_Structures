#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[1005][105][2];
    int doDP(vector<int>& prices, int i, int k, bool transaction){
        int n = prices.size();
        if(i==n || k==0)return 0;
        if(dp[i][k][transaction] != -1) return dp[i][k][transaction];
        int res = 0;
        if(transaction){
            res = max(doDP(prices,i+1,k-1,false)+prices[i], doDP(prices,i+1,k,true));
        }else{
            res = max(doDP(prices,i+1,k,true)-prices[i], doDP(prices,i+1,k,false));
        }
        return dp[i][k][transaction] = res;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return doDP(prices,0,k,false);
    }
};