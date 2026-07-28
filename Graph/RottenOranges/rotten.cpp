#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    typedef pair<pair<int,int>,int> pip;
    int orangesRot(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        if(m==0)return 0;
        int n = grid[0].size();
        queue<pip>qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    qu.push({{i,j},0});
                    grid[i][j] = 2;
                }
            }
        }
        int maxTime = 0;
        while(!qu.empty()){
            pip p = qu.front();
            qu.pop();
            int row = p.first.first;
            int col = p.first.second;
            maxTime = p.second;
            if(row>0 && grid[row-1][col]==1){
                grid[row-1][col] = 2;
                qu.push({{row-1,col},maxTime+1});
            }
            if(row<m-1 && grid[row+1][col]==1){
                grid[row+1][col] = 2;
                qu.push({{row+1,col},maxTime+1});
            }
            if(col<n-1 && grid[row][col+1]==1){
                grid[row][col+1] = 2;
                qu.push({{row,col+1},maxTime+1});
            }
            if(col>0 && grid[row][col-1]==1){
                grid[row][col-1] = 2;
                qu.push({{row,col-1},maxTime+1});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return maxTime;
    }
};