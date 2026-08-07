#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dp[75][75][75];

    int doDP(int row, int col1, int col2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return INT_MIN;

        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int result = INT_MIN;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                result = max(result,
                             doDP(row + 1, col1 + d1, col2 + d2, grid));
            }
        }

        if (result == INT_MIN)
            return dp[row][col1][col2] = INT_MIN;

        result += grid[row][col1];

        if (col1 != col2)
            result += grid[row][col2];

        return dp[row][col1][col2] = result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));

        int m = grid[0].size();

        return doDP(0, 0, m - 1, grid);
    }
};