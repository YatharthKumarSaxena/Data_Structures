#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    int doDP(int n, int k, int target, vector<vector<int>>& dp){
        if(n==0)return target==0;
        else if(dp[n][target]!=-1)return dp[n][target];
        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(target-i>=0){
                ans = (ans%MOD +doDP(n-1,k,target-i,dp)%MOD)%MOD;
            }
        }
        dp[n][target]= ans;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return doDP(n,k,target,dp);
    }
};