#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int calcLengthOfCycle(int src, vector<vector<int>>& adjList, int V) {

        queue<int> qu;
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        vector<int> dist(V, -1);

        visited[src] = true;
        dist[src] = 0;
        qu.push(src);

        int ans = INT_MAX;

        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();

            for (int neighbour : adjList[node]) {

                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    dist[neighbour] = dist[node] + 1;
                    qu.push(neighbour);
                }
                else if (neighbour != parent[node]) {
                    ans = min(ans, dist[node] + dist[neighbour] + 1);
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }

    int shortestCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int ans = INT_MAX;

        for (int i = 0; i < V; i++) {
            int res = calcLengthOfCycle(i, adjList, V);

            if (res != -1)
                ans = min(ans, res);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};