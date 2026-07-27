#include <vector>
using namespace std;

class Solution {
  public:
    void doDFS(vector<vector<int>>& grid,vector<vector<bool>>& visited,int r,int c){
        int n = grid.size();
        int m = grid[0].size();
        if(r<0 || c<0 || r>=n || c>=m)return;
        else if(visited[r][c] || !grid[r][c])return;
        else{
            visited[r][c] = true;
            doDFS(grid,visited,r-1,c);
            doDFS(grid,visited,r,c-1);
            doDFS(grid,visited,r+1,c);
            doDFS(grid,visited,r,c+1);
            doDFS(grid,visited,r-1,c-1);
            doDFS(grid,visited,r+1,c+1);
            doDFS(grid,visited,r-1,c+1);
            doDFS(grid,visited,r+1,c-1);
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        if(n==0)return 0;
        int m = grid[0].size();
        vector<vector<int>> adjGraph(n,vector<int>(m,0));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L')adjGraph[i][j]=1;
            }
        }
        int cc = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && adjGraph[i][j]){
                    doDFS(adjGraph,visited,i,j);
                    cc++;
                } 
            }
        }
        return cc;
    }
};