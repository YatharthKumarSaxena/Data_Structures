#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
  public:
    typedef pair<int,int> pip;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        vector<int>dist(V,INT_MAX);
        pq.push({0,src});
        dist[src] = 0;
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
            int distance = curr.first;
            int node = curr.second;
            pq.pop();
            if(distance>dist[node])continue;
            for(auto Pair: adjList[node]){
                int newDistance = Pair.second + distance;
                int neighbour = Pair.first;
                if(dist[neighbour]>newDistance){
                    dist[neighbour] = newDistance;
                    pq.push({newDistance,neighbour});
                }
            }
        }
        return dist;
    }
};