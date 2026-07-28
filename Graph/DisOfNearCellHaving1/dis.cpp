#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    typedef pair<pair<int,int>,int> pip;
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dis(m,vector<int>(n,-1));
        queue<pip>qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    qu.push({{i,j},0});
                    dis[i][j] = 0;
                }
            }
        }
        while(!qu.empty()){
            pip p = qu.front();
            qu.pop();
            int row = p.first.first;
            int col = p.first.second;
            int newDis = p.second+1;
            if(row>0 && mat[row-1][col]==0 && dis[row-1][col]==-1){
                dis[row-1][col] = newDis;
                qu.push({{row-1,col},newDis});
            }

            if(row<m-1 && mat[row+1][col]==0 && dis[row+1][col]==-1){
                dis[row+1][col] = newDis;
                qu.push({{row+1,col},newDis});
            }

            if(col<n-1 && mat[row][col+1]==0 && dis[row][col+1]==-1){
                dis[row][col+1] = newDis;
                qu.push({{row,col+1},newDis});
            }

            if(col>0 && mat[row][col-1]==0 && dis[row][col-1]==-1){
                dis[row][col-1] = newDis;
                qu.push({{row,col-1},newDis});
            }
        }
        return dis;
    }
};