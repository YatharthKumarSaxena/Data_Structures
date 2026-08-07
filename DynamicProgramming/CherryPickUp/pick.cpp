#include <vector>
#include <climits>
#include <cstring>
using namespace std;


class Solution {
public:
    int dp[55][55][55];
    int doDP(int i, int j, int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=n || x>=m || y>=n || grid[i][j]==-1 || grid[x][y]==-1)return INT_MIN;
        else if(i == n-1 && j == n-1) return grid[i][j];
        else if(dp[i][j][x]!=-1)return dp[i][j][x];
        int result = INT_MIN;
        result = max(result,doDP(i,j+1,x+1,y,grid));
        result = max(result,doDP(i+1,j,x+1,y,grid));
        result = max(result,doDP(i,j+1,x,y+1,grid));
        result = max(result,doDP(i+1,j,x,y+1,grid));
        if(result == INT_MIN)return dp[i][j][x] = INT_MIN;
        result += grid[i][j];
        result += grid[x][y];
        if(i==x && j==y && grid[i][j])result--;
        return dp[i][j][x] = result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = doDP(0,0,0,0,grid);
        if(ans==INT_MIN)return 0;
        return ans;
    }
};