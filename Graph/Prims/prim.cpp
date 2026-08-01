#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<int,int>pip;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        pq.push({0,0});
        vector<bool>visited(V,false);
        int minCost = 0;
        int totalEdges = edges.size();
        vector<vector<pip>>adjList(V,vector<pip>());
        for(int i=0;i<totalEdges;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        while(!pq.empty()){
            pip curr = pq.top();
            int currDist = curr.first;
            int node = curr.second;
            pq.pop();
            if(visited[node])continue;
            visited[node] = true;
            minCost += currDist;
            for(auto Pair: adjList[node]){
                int distance = Pair.second;
                int neighbour = Pair.first;
                if(!visited[neighbour]){
                    pq.push({distance,neighbour});
                }
            }
        }
        return minCost;
    }
};