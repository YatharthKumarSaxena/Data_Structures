#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void countNodeInConnComp(vector<bool>& visited,
                             vector<vector<int>>& stones,
                             int node) {

        queue<int> qu;
        qu.push(node);

        int totalStones = stones.size();
        visited[node] = true;

        while (!qu.empty()) {
            int currNode = qu.front();
            qu.pop();

            for (int neighbour = 0; neighbour < totalStones; neighbour++) {

                if (!visited[neighbour]) {

                    // Same row OR same column
                    if (stones[currNode][0] == stones[neighbour][0] ||
                        stones[currNode][1] == stones[neighbour][1]) {

                        visited[neighbour] = true;
                        qu.push(neighbour);
                    }
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int totalNodes = stones.size();
        int totalComps = 0;

        vector<bool> visited(totalNodes, false);

        for (int i = 0; i < totalNodes; i++) {

            if (!visited[i]) {
                totalComps++;
                countNodeInConnComp(visited, stones, i);
            }
        }

        return totalNodes - totalComps;
    }
};