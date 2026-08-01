#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        int m = image.size();
        int n = image[0].size();
        queue<vector<int>>qu;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        qu.push({sr,sc});
        int origColor = image[sr][sc];
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            int r = curr[0];
            int c = curr[1];
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(!visited[nr][nc] && image[nr][nc]==origColor){
                        qu.push({nr,nc});
                        image[nr][nc] = newColor;
                        visited[nr][nc] = true;
                    }
                }
            }
        }
        return image;
    }
};