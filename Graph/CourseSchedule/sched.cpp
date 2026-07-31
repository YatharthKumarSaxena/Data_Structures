#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> qu;

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                qu.push(i);
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();

            ans.push_back(node);

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    qu.push(neighbour);
            }
        }

        // Cycle exists
        if (ans.size() != n)
            return {};

        return ans;
    }
};