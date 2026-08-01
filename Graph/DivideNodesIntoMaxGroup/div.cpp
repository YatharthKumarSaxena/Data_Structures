#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pip;

    vector<int> colorByBFS(vector<vector<int>>& adjList, int start, vector<int>& color) {
        color[start] = 0;

        queue<int> qu;
        qu.push(start);

        vector<int> component;

        while (!qu.empty()) {
            int ele = qu.front();
            qu.pop();

            component.push_back(ele);

            for (int neighbour : adjList[ele]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = 1 - color[ele];
                    qu.push(neighbour);
                }
                else if (color[neighbour] == color[ele]) {
                    return {};
                }
            }
        }

        return component;
    }

    int bfsLevels(vector<vector<int>>& adjList, int start) {

        int n = adjList.size();

        vector<bool> visited(n, false);

        queue<pip> qu;
        qu.push({start, 1});
        visited[start] = true;

        int maxLevel = 1;

        while (!qu.empty()) {

            auto curr = qu.front();
            qu.pop();

            int node = curr.first;
            int level = curr.second;

            maxLevel = max(maxLevel, level);

            for (int neighbour : adjList[node]) {

                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    qu.push({neighbour, level + 1});
                }
            }
        }

        return maxLevel;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {

        vector<int> color(n, -1);
        vector<vector<int>> adjList(n);

        for (auto &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> comps;

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                vector<int> component = colorByBFS(adjList, i, color);

                if (component.empty())
                    return -1;

                comps.push_back(component);
            }
        }

        int ans = 0;

        for (auto &component : comps) {

            int best = 0;

            for (int node : component) {
                best = max(best, bfsLevels(adjList, node));
            }

            ans += best;
        }

        return ans;
    }
};