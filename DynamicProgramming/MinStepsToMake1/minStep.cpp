#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int doDP(vector<int>& dp, int n){
        if(n==1)return dp[1]= 0;
        else if(dp[n]!=-1)return dp[n];
        int divideBy2 = (n%2==0)? doDP(dp,n/2): INT_MAX;
        int divideBy3 = (n%3==0)? doDP(dp,n/3): INT_MAX;
        return dp[n] = 1+min(doDP(dp,n-1),min(divideBy2,divideBy3));
    }
    int getMinSteps(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return doDP(dp,n);
    }
};
