#include <cstring>

class Solution {
public:
    int dp[20];
    int f(int i){
        if(i<=1)return 1;
        else if(i==2)return 2;
        else if(dp[i]!=-1)return dp[i];
        int Sum = 0;
        for(int k=1;k<=i;k++){
            Sum += f(k-1)*f(i-k);
        }
        return dp[i] = Sum;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};