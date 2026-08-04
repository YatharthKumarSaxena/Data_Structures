#include <vector>
using namespace std;

class Solution {
public:
    int doDP(vector<vector<int>>& dp, int sr, int sc, int er, int ec){
        if(sr == er && sc == ec)return 1;
        else if(sr < 0 || sc < 0)return 0;
        else if(dp[sr][sc]!=-1)return dp[sr][sc];
        return dp[sr][sc] = doDP(dp,sr-1,sc,er,ec) + doDP(dp,sr,sc-1,er,ec);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return doDP(dp,m-1,n-1,0,0);
    }
};