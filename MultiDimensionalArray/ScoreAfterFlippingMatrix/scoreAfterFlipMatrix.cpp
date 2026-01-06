#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Flip Rows
        for(int i=0;i<rows;i++){
            if(!grid[i][0]){
                for(int j=0;j<cols;j++){
                    if(grid[i][j])grid[i][j] = 0;
                    else grid[i][j] = 1;
                }
            }
        }
        // Flip Cols
        for(int j=0;j<cols;j++){
            int noz = 0;
            for(int i=0;i<rows;i++){
                if(!grid[i][j])noz++;
            }
            if(noz>rows-noz){
                for(int i=0;i<rows;i++){
                    if(grid[i][j])grid[i][j] = 0;
                    else grid[i][j] = 1;
                }    
            }
        }
        int ans = 0;
        for(int i=0;i<rows;i++){
            int value = 0;
            int mul = 1;
            for(int j=cols-1;j>=0;j--){
                value += (grid[i][j]*mul);
                mul *= 2;
            }
            ans += value;
        }
        return ans;
    }
};