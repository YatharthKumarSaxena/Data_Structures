#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    typedef pair<long long, int> pip;
    const int MOD = 1000000007;

    int dijkstra(int V, vector<vector<int>>& edges, int src, int dest) {

        priority_queue<pip, vector<pip>, greater<pip>> pq;

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);

        dist[src] = 0;
        ways[src] = 1;

        pq.push({0, src});

        vector<vector<pip>> adjList(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            long long distance = curr.first;
            int node = curr.second;

            if (distance > dist[node])
                continue;

            for (auto &Pair : adjList[node]) {

                int neighbour = Pair.first;
                long long newDistance = distance + Pair.second;

                if (newDistance < dist[neighbour]) {

                    dist[neighbour] = newDistance;
                    ways[neighbour] = ways[node];

                    pq.push({newDistance, neighbour});
                }
                else if (newDistance == dist[neighbour]) {

                    ways[neighbour] =
                        (ways[neighbour] + ways[node]) % MOD;
                }
            }
        }

        return ways[dest];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        return dijkstra(n, roads, 0, n - 1);
    }
};