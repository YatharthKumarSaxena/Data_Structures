#include <vector>
using namespace std;

class Solution {
  public:
    int doDP(vector<vector<int>> &grid, vector<vector<int>>& dp, int sr, int sc, int er, int ec){
        if(sr < 0 || sc < 0)return 0;
        else if(grid[sr][sc])return 0;
        else if(sr == er && sc == ec)return 1;
        else if(dp[sr][sc]!=-1)return dp[sr][sc];
        return dp[sr][sc] = doDP(grid,dp,sr-1,sc,er,ec) + doDP(grid,dp,sr,sc-1,er,ec);
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return doDP(grid,dp,m-1,n-1,0,0);
    }
};