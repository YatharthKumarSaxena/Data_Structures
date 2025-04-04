#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    queue<pair<int,int>>qu;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0)qu.push({i,j});
        }
    }
    // Up,Down,Left,Right
    vector<int> dRow = {-1,1,0,0};
    vector<int> dCol = {0,0,-1,1};
    while(!qu.empty()){
        auto [row,col] = qu.front();
        qu.pop();
        for(int k=0;k<4;k++){
            int newRow = row + dRow[k];
            int newCol = col + dCol[k];
            if(newRow<0 || newRow>=n || newCol<0 || newCol>=m)continue;
            if(a[newRow][newCol]==-1)continue;
            if(a[newRow][newCol]==INT_MAX){
                a[newRow][newCol]=a[row][col]+1;
                qu.push({newRow,newCol});
            }
        }
    }
    return a;
}