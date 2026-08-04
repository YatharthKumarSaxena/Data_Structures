#include <vector>
using namespace std;

class Solution {
public:
    int countBits(int n, vector<int>& dp){
        if(n==0)return 0;
        else if(dp[n]!=-1)return dp[n];
        return dp[n] = countBits(n/2,dp) + n%2;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,-1);
        ans[0] = 0;
        for(int i = 0; i <= n; i++)
            countBits(i, ans);
        return ans;
    }
};