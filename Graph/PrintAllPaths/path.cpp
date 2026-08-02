#include <vector>
using namespace std;

class Solution {
public:
    void doDFS(int node, int target,
               vector<int>& path,
               vector<vector<int>>& graph,
               vector<vector<int>>& ans) {

        path.push_back(node);

        if (node == target) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (int neighbour : graph[node]) {
            doDFS(neighbour, target, path, graph, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> ans;
        vector<int> path;

        doDFS(0, n - 1, path, graph, ans);

        return ans;
    }
};