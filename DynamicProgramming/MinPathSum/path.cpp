#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int j=n-1;j>0;j--){
            grid[m-1][j-1] += grid[m-1][j];
        }
        for(int i=m-1;i>0;i--){
            grid[i-1][n-1] += grid[i][n-1];
        }
        for(int i=m-1;i>0;i--){
            for(int j=n-1;j>0;j--){
                grid[i-1][j-1] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[0][0];
    }
};