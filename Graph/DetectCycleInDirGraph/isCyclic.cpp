#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>indegree(V,0);
        int totalEdges = edges.size();
        vector<vector<int>>adj(V,vector<int>());
        for(int i=0;i<totalEdges;i++){
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int>qu;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)qu.push(i);
        }
        while(!qu.empty()){
            int ele = qu.front();
            qu.pop();
            for(int neighbour: adj[ele]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0)qu.push(neighbour);
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]!=0)return true;
        }
        return false;
    }
};