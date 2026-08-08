#include <vector>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
  public:
    int dp[105][105];
    int doDP(vector<int> &arr, int i, int j){
        if(i==j)return 0;
        else if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<j;k++)
        ans = min(ans,doDP(arr,i,k)+doDP(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        memset(dp,-1,sizeof(dp));
        int n = arr.size()-1;
        return doDP(arr,1,n);
    }
};