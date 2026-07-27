#include <vector>
using namespace std;

class Solution {
  public:
    void doDFS(vector<vector<int>>& adj,vector<bool>& visited,int v){
        if(visited[v])return;
        visited[v] = true;
        for(int neighbour: adj[v]){
            if(!visited[neighbour]) doDFS(adj,visited,neighbour);
        } 
    }
    int countConnected(int n, vector<vector<int>>& edges) {
        int totalEdges = edges.size();
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<totalEdges;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        int totalCC = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                totalCC++;
                doDFS(adj,visited,i);
            }
        }
        return totalCC;
    }
};