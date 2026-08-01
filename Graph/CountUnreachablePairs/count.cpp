#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNodeInConnComp(vector<bool>& visited,
                            vector<vector<int>>& adjList,
                            int node) {

        queue<int> qu;
        qu.push(node);
        visited[node] = true;

        int totalNodes = 0;

        while (!qu.empty()) {
            int currNode = qu.front();
            qu.pop();

            totalNodes++;

            for (int neighbour : adjList[currNode]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    qu.push(neighbour);
                }
            }
        }

        return totalNodes;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> totalNodeInComps;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                totalNodeInComps.push_back(
                    countNodeInConnComp(visited, adjList, i)
                );
            }
        }

        int totalComps = totalNodeInComps.size();

        if (totalComps == 1)
            return 0;

        vector<long long> suffixSum(totalComps, 0);

        long long totalComp = 0;

        for (int i = totalComps - 1; i >= 0; i--) {
            suffixSum[i] = totalComp;
            totalComp += totalNodeInComps[i];
        }

        long long totalUnreachablePairs = 0;

        for (int i = 0; i < totalComps; i++) {
            totalUnreachablePairs +=
                suffixSum[i] * totalNodeInComps[i];
        }

        return totalUnreachablePairs;
    }
};