#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<double,int> State;      // PQ
    typedef pair<int,double> Edge;       // Adjacency
    double dijkstra(int V, vector<vector<int>> &edges, vector<double>& succProb, int src,int dest) {
        // Code here
        priority_queue<State>pq;
        vector<double>prob(V,0.0);
        pq.push({1.0,src});
        prob[src] = 1.0;
        int totalEdges = edges.size();
        vector<vector<Edge>>adjList(V,vector<Edge>());
        for(int i=0;i<totalEdges;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        while(!pq.empty()){
            State curr = pq.top();
            double probability = curr.first;
            int node = curr.second;
            pq.pop();
            if(probability<prob[node])continue;
            for(auto Pair: adjList[node]){
                double newProbability = Pair.second * probability;
                int neighbour = Pair.first;
                if(prob[neighbour]<newProbability){
                    prob[neighbour] = newProbability;
                    pq.push({newProbability,neighbour});
                }
            }
        }
        return prob[dest];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        return dijkstra(n,edges,succProb,start_node,end_node);
    }
};