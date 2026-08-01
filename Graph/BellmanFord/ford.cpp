#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int totalEdges = edges.size();
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        bool done = false;
        for(int i=0;i<V-1;i++){
            bool updated = false;
            for(int j=0;j<totalEdges;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    dist[v] = dist[u]+wt;
                    updated = true;
                }
            }
            if(!updated){
                done = true;
                break;
            }
        }
        if(!done){
            for(int j=0;j<totalEdges;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                    return {-1};
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)dist[i] = 100000000;
        }
        return dist;
    }
    
};
