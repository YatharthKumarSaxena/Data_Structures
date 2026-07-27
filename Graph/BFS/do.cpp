#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        int n = adj.size();

        vector<bool> visited(n, false);
        queue<int> qu;

        qu.push(0);

        while (!qu.empty()) {
            int ele = qu.front();
            qu.pop();

            if (visited[ele])
                continue;

            visited[ele] = true;
            ans.push_back(ele);

            for (int neighbour : adj[ele]) {
                if (!visited[neighbour]) {
                    qu.push(neighbour);
                }
            }
        }

        return ans;
    }
};