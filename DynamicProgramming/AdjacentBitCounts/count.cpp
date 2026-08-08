#include <cstring>

class Solution {
  public:
    int MOD = 1000000007;
    int dp[1005][1005][2];
    int doDP(int n, int k, int lastChar){
        if(n==0)return k==0;
        else if(k<0)return 0;
        else if(dp[n][k][lastChar]!=-1)return dp[n][k][lastChar];
        int res = 0;
        if(lastChar){
            res = (doDP(n-1,k,0)%MOD + res%MOD)%MOD;
            res = (doDP(n-1,k-1,1)%MOD + res%MOD)%MOD;
        }else{
            res = (doDP(n-1,k,0)%MOD + res%MOD)%MOD;
            res = (doDP(n-1,k,1)%MOD + res%MOD)%MOD;
        }
        return dp[n][k][lastChar] = res;
    }
    int countStrings(int n, int k) {
        // code here
        memset(dp,-1,sizeof(dp));
        return (doDP(n-1,k,0)%MOD + doDP(n-1,k,1)%MOD)%MOD;
    }
};