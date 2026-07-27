#include <vector>
using namespace std;

class Solution {
  public:
    void doDFS(vector<vector<int>>& adj,vector<int>& ans,vector<bool>& visited,int v){
        if(visited[v])return;
        ans.push_back(v);
        visited[v] = true;
        for(int neighbour: adj[v]){
            if(!visited[neighbour]) doDFS(adj,ans,visited,neighbour);
        } 
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int totalVertices = adj.size();
        vector<bool>visited(totalVertices,false);
        vector<int>ans;
        doDFS(adj,ans,visited,0);
        return ans;
    }
};