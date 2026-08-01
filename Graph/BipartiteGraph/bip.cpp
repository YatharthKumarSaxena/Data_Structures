#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool colorByBFS(vector<vector<int>>& adjList, int start, vector<int>& color) {
        color[start] = 0;

        queue<int> qu;
        qu.push(start);

        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();

            for (int neighbour : adjList[curr]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = 1 - color[curr];
                    qu.push(neighbour);
                }
                else if (color[neighbour] == color[curr]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<vector<int>>& edges) {
        vector<int> color(V, -1);
        vector<vector<int>> adjList(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!colorByBFS(adjList, i, color))
                    return false;
            }
        }

        return true;
    }
};