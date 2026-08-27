#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool solve(int i, int count, int n, vector<bool>& visited, vector<vector<int>>& adjList){
        if(count==n)return true;
        for(int curr: adjList[i]){
            if(!visited[curr]){
                visited[curr] = true;
                if(solve(curr,count+1,n,visited,adjList))return true;
                visited[curr] = false;
            }
        }
        return false;
    }
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        vector<vector<int>> adjList(n+1);
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int start=1;start<=n;start++){
            vector<bool>visited(n,false);
            visited[start]=true;
            if(solve(start,1,n,visited,adjList))return true;
            visited[start]=false;
        }
        return false;
    }
};
